/********************************************************************************
** Form generated from reading UI file 'cscene_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSCENE_FRM_H
#define UI_CSCENE_FRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_CSceneFrm
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;

    void setupUi(QFrame *CSceneFrm)
    {
        if (CSceneFrm->objectName().isEmpty())
            CSceneFrm->setObjectName(QStringLiteral("CSceneFrm"));
        CSceneFrm->resize(400, 301);
        gridLayout = new QGridLayout(CSceneFrm);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(CSceneFrm);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setSceneRect(QRectF(-500, -500, 1000, 1000));
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        retranslateUi(CSceneFrm);

        QMetaObject::connectSlotsByName(CSceneFrm);
    } // setupUi

    void retranslateUi(QFrame *CSceneFrm)
    {
        CSceneFrm->setWindowTitle(QApplication::translate("CSceneFrm", "CSceneFrm", 0));
    } // retranslateUi

};

namespace Ui {
    class CSceneFrm: public Ui_CSceneFrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSCENE_FRM_H
