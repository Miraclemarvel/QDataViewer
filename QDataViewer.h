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
    void on_actionsaveProject_triggered();      //���湤���ļ�
    void on_actionloadProject_triggered();      //���빤���ļ�
    void on_actionaddVectorLayer_triggered();   //��ʸ��ͼ��
    void on_actionaddRasterLayer_triggered();   //��դ��ͼ��
    void on_actionremoveLayer_triggered();      //�Ƴ�ͼ��

private:
    Ui::QDataViewerClass ui;
    QgsMapCanvas* mpMapCanvas;
    QList<QgsMapLayer*> mapCanvasLayerSet;
    QgsLayerTreeView* mpLayerTreeView;
    //QgsLayerTreeMapCanvasBridge* mpLayerTreeCanvasBridge;
};
