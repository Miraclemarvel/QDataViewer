/********************************************************************************
** Form generated from reading UI file 'QDataViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDATAVIEWER_H
#define UI_QDATAVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDataViewerClass
{
public:
    QAction *actionsaveProject;
    QAction *actionloadProject;
    QAction *actionaddVectorLayer;
    QAction *actionaddRasterLayer;
    QAction *actionremoveLayer;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menuaddLayer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *layerList;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *QDataViewerClass)
    {
        if (QDataViewerClass->objectName().isEmpty())
            QDataViewerClass->setObjectName(QString::fromUtf8("QDataViewerClass"));
        QDataViewerClass->resize(912, 588);
        actionsaveProject = new QAction(QDataViewerClass);
        actionsaveProject->setObjectName(QString::fromUtf8("actionsaveProject"));
        actionloadProject = new QAction(QDataViewerClass);
        actionloadProject->setObjectName(QString::fromUtf8("actionloadProject"));
        actionaddVectorLayer = new QAction(QDataViewerClass);
        actionaddVectorLayer->setObjectName(QString::fromUtf8("actionaddVectorLayer"));
        actionaddRasterLayer = new QAction(QDataViewerClass);
        actionaddRasterLayer->setObjectName(QString::fromUtf8("actionaddRasterLayer"));
        actionremoveLayer = new QAction(QDataViewerClass);
        actionremoveLayer->setObjectName(QString::fromUtf8("actionremoveLayer"));
        centralWidget = new QWidget(QDataViewerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QDataViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QDataViewerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 912, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menuaddLayer = new QMenu(menu_2);
        menuaddLayer->setObjectName(QString::fromUtf8("menuaddLayer"));
        QDataViewerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QDataViewerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QDataViewerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QDataViewerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QDataViewerClass->setStatusBar(statusBar);
        layerList = new QDockWidget(QDataViewerClass);
        layerList->setObjectName(QString::fromUtf8("layerList"));
        layerList->setMinimumSize(QSize(220, 42));
        layerList->setMaximumSize(QSize(220, 524287));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        layerList->setWidget(dockWidgetContents);
        QDataViewerClass->addDockWidget(Qt::LeftDockWidgetArea, layerList);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionsaveProject);
        menu->addAction(actionloadProject);
        menu_2->addAction(menuaddLayer->menuAction());
        menu_2->addAction(actionremoveLayer);
        menuaddLayer->addAction(actionaddVectorLayer);
        menuaddLayer->addAction(actionaddRasterLayer);

        retranslateUi(QDataViewerClass);

        QMetaObject::connectSlotsByName(QDataViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QDataViewerClass)
    {
        QDataViewerClass->setWindowTitle(QCoreApplication::translate("QDataViewerClass", "QDataViewer", nullptr));
        actionsaveProject->setText(QCoreApplication::translate("QDataViewerClass", "\344\277\235\345\255\230\345\267\245\347\250\213", nullptr));
        actionloadProject->setText(QCoreApplication::translate("QDataViewerClass", "\346\211\223\345\274\200\345\267\245\347\250\213", nullptr));
        actionaddVectorLayer->setText(QCoreApplication::translate("QDataViewerClass", "\346\267\273\345\212\240\347\237\242\351\207\217\345\233\276\345\261\202", nullptr));
        actionaddRasterLayer->setText(QCoreApplication::translate("QDataViewerClass", "\346\267\273\345\212\240\346\240\205\346\240\274\345\233\276\345\261\202", nullptr));
        actionremoveLayer->setText(QCoreApplication::translate("QDataViewerClass", "\347\247\273\351\231\244\345\233\276\345\261\202", nullptr));
        menu->setTitle(QCoreApplication::translate("QDataViewerClass", "\345\267\245\347\250\213", nullptr));
        menu_2->setTitle(QCoreApplication::translate("QDataViewerClass", "\345\233\276\345\261\202", nullptr));
        menuaddLayer->setTitle(QCoreApplication::translate("QDataViewerClass", "\346\267\273\345\212\240\345\233\276\345\261\202", nullptr));
        layerList->setWindowTitle(QCoreApplication::translate("QDataViewerClass", "\345\233\276\345\261\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QDataViewerClass: public Ui_QDataViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDATAVIEWER_H
