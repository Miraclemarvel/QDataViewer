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

    // �����Ž���������ͼ������ͼ���ͼ����
    //mpLayerTreeCanvasBridge = new QgsLayerTreeMapCanvasBridge(QgsProject::instance()->layerTreeRoot(), mpMapCanvas);
}

QDataViewer::~QDataViewer()
{}

//��ʸ��ͼ��
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

//��դ��ͼ��
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
//���湤���ļ�
void QDataViewer::on_actionsaveProject_triggered() {
    QString projectFilePath = QFileDialog::getSaveFileName(this, QStringLiteral("���湤��"), "./TestData", QStringLiteral("QGIS Project Files (*.qgz *.qgs)"));
    if (!projectFilePath.isEmpty())
    {
        if (QgsProject::instance()->write(projectFilePath))
        {
            QMessageBox::information(this, QStringLiteral("����ɹ�"), QStringLiteral("�����ļ��ѳɹ����浽: %1").arg(projectFilePath));
        }
        else
        {
            QMessageBox::warning(this, QStringLiteral("����ʧ��"), QStringLiteral("�޷����湤���ļ���"));
        }
    }
}
//���빤���ļ�
void QDataViewer::on_actionloadProject_triggered() {
    QString projectFilePath = QFileDialog::getOpenFileName(this, QStringLiteral("���ع���"), "./TestData", QStringLiteral("QGIS Project Files (*.qgz *.qgs)"));
    if (!projectFilePath.isEmpty())
    {
        if (QgsProject::instance()->read(projectFilePath))
        {
            mpMapCanvas->refresh();
            QMessageBox::information(this, QStringLiteral("���سɹ�"), QStringLiteral("�����ļ��ѳɹ�����: %1").arg(projectFilePath));
        }
        else
        {
            QMessageBox::warning(this, QStringLiteral("����ʧ��"), QStringLiteral("�޷����ع����ļ���"));
        }
    }
}

//�Ƴ�ͼ��
void QDataViewer::on_actionremoveLayer_triggered() {
    // ��ȡ��ǰѡ�е�ͼ�����ڵ�
    auto selectedNode = mpLayerTreeView->currentNode();
    if (!selectedNode)
    {
        QMessageBox::warning(this, QStringLiteral("δѡ��ͼ��"), QStringLiteral("����ѡ��һ��Ҫ�Ƴ���ͼ�㡣"));
        return;
    }

    // ����Ƿ�Ϊͼ��ڵ�
    auto layerNode = dynamic_cast<QgsLayerTreeLayer*>(selectedNode);
    if (!layerNode)
    {
        QMessageBox::warning(this, QStringLiteral("��Чѡ��"), QStringLiteral("��ѡ��һ����Ч��ͼ��ڵ㡣"));
        return;
    }

    // �ӹ������Ƴ�ͼ��
    QgsMapLayer* layer = layerNode->layer();
    if (layer)
    {
        // ����Ŀ���Ƴ�ͼ��
        QgsProject::instance()->removeMapLayer(layer);

        QMessageBox::information(this, QStringLiteral("ͼ�����Ƴ�"), QStringLiteral("ͼ�� '%1' �ѳɹ��Ƴ���").arg(layer->name()));

        mapCanvasLayerSet.removeOne(layer);  // ʹ�� removeOne ȷ����ȫɾ��
        mpMapCanvas->setLayers(mapCanvasLayerSet);

        mpMapCanvas->refresh();

    }
    else
    {
        QMessageBox::warning(this, QStringLiteral("��Чͼ��"), QStringLiteral("ѡ�е�ͼ����Ч���Ѳ����ڡ�"));
    }
}
   