#pragma once
#pragma warning(disable:4819)
#include <QtWidgets/QMainWindow>
#include "ui_QDataViewer.h"
#include "qgsmapcanvas.h"
#include "qgsmaplayer.h"
#include "QgsLayerTreeView.h"
#include "qgslayertreemapcanvasbridge.h"


class QDataViewer : public QMainWindow
{
    Q_OBJECT

public:
    QDataViewer(QWidget *parent = nullptr);
    ~QDataViewer();

public slots:
    void on_actionsaveProject_triggered();      //保存工程文件
    void on_actionloadProject_triggered();      //载入工程文件
    void on_actionaddVectorLayer_triggered();   //打开矢量图层
    void on_actionaddRasterLayer_triggered();   //打开栅格图层
    void on_actionremoveLayer_triggered();      //移除图层

private:
    Ui::QDataViewerClass ui;
    QgsMapCanvas* mpMapCanvas;
    QList<QgsMapLayer*> mapCanvasLayerSet;
    QgsLayerTreeView* mpLayerTreeView;
    //QgsLayerTreeMapCanvasBridge* mpLayerTreeCanvasBridge;
};
