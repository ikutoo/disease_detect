/********************************************************************************
** Form generated from reading UI file 'casset_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASSET_FRM_H
#define UI_CASSET_FRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CAssetFrm
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;

    void setupUi(QFrame *CAssetFrm)
    {
        if (CAssetFrm->objectName().isEmpty())
            CAssetFrm->setObjectName(QStringLiteral("CAssetFrm"));
        CAssetFrm->resize(431, 366);
        CAssetFrm->setFrameShape(QFrame::StyledPanel);
        CAssetFrm->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(CAssetFrm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(CAssetFrm);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMouseTracking(true);
        treeWidget->setStyleSheet(QStringLiteral("background:#606060;color:white"));
        treeWidget->setDragEnabled(true);
        treeWidget->setDragDropMode(QAbstractItemView::InternalMove);

        verticalLayout->addWidget(treeWidget);


        retranslateUi(CAssetFrm);

        QMetaObject::connectSlotsByName(CAssetFrm);
    } // setupUi

    void retranslateUi(QFrame *CAssetFrm)
    {
        CAssetFrm->setWindowTitle(QApplication::translate("CAssetFrm", "\350\265\204\344\272\247", 0));
    } // retranslateUi

};

namespace Ui {
    class CAssetFrm: public Ui_CAssetFrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASSET_FRM_H
