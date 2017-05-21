/********************************************************************************
** Form generated from reading UI file 'cdetec_result_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDETEC_RESULT_FRM_H
#define UI_CDETEC_RESULT_FRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CDetecResultFrm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QFrame *CDetecResultFrm)
    {
        if (CDetecResultFrm->objectName().isEmpty())
            CDetecResultFrm->setObjectName(QStringLiteral("CDetecResultFrm"));
        CDetecResultFrm->resize(542, 357);
        verticalLayout_2 = new QVBoxLayout(CDetecResultFrm);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CDetecResultFrm);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(CDetecResultFrm);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QStringLiteral("color:rgb(255,255,255);background: rgb(80,80,80)"));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CDetecResultFrm);

        QMetaObject::connectSlotsByName(CDetecResultFrm);
    } // setupUi

    void retranslateUi(QFrame *CDetecResultFrm)
    {
        CDetecResultFrm->setWindowTitle(QApplication::translate("CDetecResultFrm", "CDetecResultFrm", 0));
        label->setText(QApplication::translate("CDetecResultFrm", "\346\243\200\346\265\213\347\273\223\346\236\234", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CDetecResultFrm", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CDetecResultFrm", "\345\214\205\345\220\253\347\227\205\345\256\263", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CDetecResultFrm", "\347\227\205\345\256\263\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CDetecResultFrm", "\347\227\205\345\256\263\345\255\220\345\235\227\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("CDetecResultFrm", "\347\227\205\345\256\263\345\255\220\345\235\227\346\240\207\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("CDetecResultFrm", "\345\233\276\345\203\217\350\267\257\345\276\204", 0));
    } // retranslateUi

};

namespace Ui {
    class CDetecResultFrm: public Ui_CDetecResultFrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDETEC_RESULT_FRM_H
