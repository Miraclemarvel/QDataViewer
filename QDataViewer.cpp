#include "QDataViewer.h"
#include "qfiledialog.h"
#include <qgsvectorlayer.h>
#include <qgslayoutitemregistry.h>
#include <qgsrasterlayer.h>
#include "qmessagebox.h"
#include <qgslayertreemodel.h>s
#include <QgsLayerTreeLayer.h>
#include <QgsLayerTreeNode.h>

QDataViewer::QDataViewer(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    mpMapCanvas = new QgsMapCanvas();
    this->setCentralWidget(mpMapCanvas);

    mpMapCanvas->enableAntiAliasing(true);
    mpMapCanvas->setCanvasColor(QColor(255, 255, 255));
    mpMapCanvas->setVisible(true);

    QgsLayerTreeModel* layerTreeModel = new QgsLayerTreeModel(QgsProject::instance()->layerTreeRoot());
    layerTreeModel->setFlag(QgsLayerTreeModel::AllowNodeChangeVisibility);
    mpLayerTreeView = new QgsLayerTreeView();
    mpLayerTreeView->setModel(layerTreeModel);
    ui.layerList->setWidget(mpLayerTreeView);

    // 创建桥接器：连接图层树视图与地图画布
    //mpLayerTreeCanvasBridge = new QgsLayerTreeMapCanvasBridge(QgsProject::instance()->layerTreeRoot(), mpMapCanvas);
}

QDataViewer::~QDataViewer()
{}

//打开矢量图层
void QDataViewer::on_actionaddVectorLayer_triggered() {
 QString filename = QFileDialog::getOpenFileName(this, tr("open vector"), "./TestData", "*.shp;;*.*");
    QStringList temp = filename.split("/");
    QString basename = temp.at(temp.size() - 1);
    QgsVectorLayer* vecLayer = new QgsVectorLayer(filename, basename, "ogr");
    if (!vecLayer->isValid()) {
        QMessageBox::critical(this, "error", "layer is invalid");
        return;
    }
    QgsProject::instance()->addMapLayer(vecLayer);
    mapCanvasLayerSet.append(vecLayer);
    mpMapCanvas->setExtent(vecLayer->extent());
    mpMapCanvas->setLayers(mapCanvasLayerSet);
    mpMapCanvas->setVisible(true);
    mpMapCanvas->freeze(false);
    mpMapCanvas->refresh();
}

//打开栅格图层
void QDataViewer::on_actionaddRasterLayer_triggered() {
    QString filename = QFileDialog::getOpenFileName(this, tr("open vector"), "./TestData", "*.tif;;*.*");
    QStringList temp = filename.split("/");
    QString basename = temp.at(temp.size() - 1);
    QgsRasterLayer* rasLayer = new QgsRasterLayer(filename, basename, "gdal");
    if (!rasLayer->isValid()) {
        QMessageBox::critical(this, "error", "layer is invalid");
        return;
    }
    QgsProject::instance()->addMapLayer(rasLayer);
    mapCanvasLayerSet.append(rasLayer);
    mpMapCanvas->setExtent(rasLayer->extent());
    mpMapCanvas->setLayers(mapCanvasLayerSet);
    mpMapCanvas->setVisible(true);
    mpMapCanvas->freeze(false);
    mpMapCanvas->refresh();
}
//保存工程文件
void QDataViewer::on_actionsaveProject_triggered() {
    QString projectFilePath = QFileDialog::getSaveFileName(this, QStringLiteral("保存工程"), "./TestData", QStringLiteral("QGIS Project Files (*.qgz *.qgs)"));
    if (!projectFilePath.isEmpty())
    {
        if (QgsProject::instance()->write(projectFilePath))
        {
            QMessageBox::information(this, QStringLiteral("保存成功"), QStringLiteral("工程文件已成功保存到: %1").arg(projectFilePath));
        }
        else
        {
            QMessageBox::warning(this, QStringLiteral("保存失败"), QStringLiteral("无法保存工程文件。"));
        }
    }
}
//载入工程文件
void QDataViewer::on_actionloadProject_triggered() {
    QString projectFilePath = QFileDialog::getOpenFileName(this, QStringLiteral("加载工程"), "./TestData", QStringLiteral("QGIS Project Files (*.qgz *.qgs)"));
    if (!projectFilePath.isEmpty())
    {
        if (QgsProject::instance()->read(projectFilePath))
        {
            mpMapCanvas->refresh();
            QMessageBox::information(this, QStringLiteral("加载成功"), QStringLiteral("工程文件已成功加载: %1").arg(projectFilePath));
        }
        else
        {
            QMessageBox::warning(this, QStringLiteral("加载失败"), QStringLiteral("无法加载工程文件。"));
        }
    }
}

//移除图层
void QDataViewer::on_actionremoveLayer_triggered() {
    // 获取当前选中的图层树节点
    auto selectedNode = mpLayerTreeView->currentNode();
    if (!selectedNode)
    {
        QMessageBox::warning(this, QStringLiteral("未选中图层"), QStringLiteral("请先选择一个要移除的图层。"));
        return;
    }

    // 检查是否为图层节点
    auto layerNode = dynamic_cast<QgsLayerTreeLayer*>(selectedNode);
    if (!layerNode)
    {
        QMessageBox::warning(this, QStringLiteral("无效选择"), QStringLiteral("请选择一个有效的图层节点。"));
        return;
    }

    // 从工程中移除图层
    QgsMapLayer* layer = layerNode->layer();
    if (layer)
    {
        // 从项目中移除图层
        QgsProject::instance()->removeMapLayer(layer);

        QMessageBox::information(this, QStringLiteral("图层已移除"), QStringLiteral("图层 '%1' 已成功移除。").arg(layer->name()));

        mapCanvasLayerSet.removeOne(layer);  // 使用 removeOne 确保安全删除
        mpMapCanvas->setLayers(mapCanvasLayerSet);

        mpMapCanvas->refresh();

    }
    else
    {
        QMessageBox::warning(this, QStringLiteral("无效图层"), QStringLiteral("选中的图层无效或已不存在。"));
    }
}
   