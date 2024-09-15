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
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QDataViewerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QDataViewerClass)
    {
        if (QDataViewerClass->objectName().isEmpty())
            QDataViewerClass->setObjectName(QString::fromUtf8("QDataViewerClass"));
        QDataViewerClass->resize(600, 400);
        menuBar = new QMenuBar(QDataViewerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QDataViewerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QDataViewerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QDataViewerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QDataViewerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QDataViewerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QDataViewerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QDataViewerClass->setStatusBar(statusBar);

        retranslateUi(QDataViewerClass);

        QMetaObject::connectSlotsByName(QDataViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QDataViewerClass)
    {
        QDataViewerClass->setWindowTitle(QCoreApplication::translate("QDataViewerClass", "QDataViewer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QDataViewerClass: public Ui_QDataViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDATAVIEWER_H
