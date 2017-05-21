/********************************************************************************
** Form generated from reading UI file 'cnew_file_dlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CNEW_FILE_DLG_H
#define UI_CNEW_FILE_DLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CNewFileDlg
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_describe;
    QTextBrowser *textBrowser_describe;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QListWidget *listWidget;

    void setupUi(QDialog *CNewFileDlg)
    {
        if (CNewFileDlg->objectName().isEmpty())
            CNewFileDlg->setObjectName(QStringLiteral("CNewFileDlg"));
        CNewFileDlg->resize(500, 360);
        CNewFileDlg->setMinimumSize(QSize(500, 360));
        CNewFileDlg->setMaximumSize(QSize(500, 360));
        layoutWidget = new QWidget(CNewFileDlg);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 50, 361, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setMinimumSize(QSize(50, 0));

        horizontalLayout->addWidget(label_name);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setStyleSheet(QStringLiteral("background:#606060;color:white"));

        horizontalLayout->addWidget(lineEdit_name);

        layoutWidget1 = new QWidget(CNewFileDlg);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 190, 361, 81));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_describe = new QLabel(layoutWidget1);
        label_describe->setObjectName(QStringLiteral("label_describe"));
        label_describe->setMinimumSize(QSize(80, 0));

        horizontalLayout_3->addWidget(label_describe);

        textBrowser_describe = new QTextBrowser(layoutWidget1);
        textBrowser_describe->setObjectName(QStringLiteral("textBrowser_describe"));
        textBrowser_describe->setMinimumSize(QSize(150, 0));
        textBrowser_describe->setStyleSheet(QStringLiteral("background:#303030;color:white"));

        horizontalLayout_3->addWidget(textBrowser_describe);

        layoutWidget2 = new QWidget(CNewFileDlg);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(220, 294, 161, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_ok = new QPushButton(layoutWidget2);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        horizontalLayout_4->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(layoutWidget2);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_4->addWidget(pushButton_cancel);

        layoutWidget3 = new QWidget(CNewFileDlg);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 90, 361, 91));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(label);

        listWidget = new QListWidget(layoutWidget3);
        QIcon icon;
        icon.addFile(QStringLiteral(":/picture/ui_picture/file/scene.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/picture/ui_picture/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/picture/ui_picture/file/UI.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/picture/ui_picture/objects/map.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setIcon(icon3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral("background:#303030;color:white"));
        listWidget->setIconSize(QSize(60, 60));
        listWidget->setSpacing(0);
        listWidget->setGridSize(QSize(60, 80));
        listWidget->setViewMode(QListView::IconMode);

        horizontalLayout_2->addWidget(listWidget);


        retranslateUi(CNewFileDlg);
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), CNewFileDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CNewFileDlg);
    } // setupUi

    void retranslateUi(QDialog *CNewFileDlg)
    {
        CNewFileDlg->setWindowTitle(QApplication::translate("CNewFileDlg", "\346\226\260\345\273\272\346\226\207\344\273\266", 0));
        label_name->setText(QApplication::translate("CNewFileDlg", "\346\226\207\344\273\266\345\220\215\347\247\260", 0));
        label_describe->setText(QApplication::translate("CNewFileDlg", "\346\217\217\350\277\260", 0));
        pushButton_ok->setText(QApplication::translate("CNewFileDlg", "\346\226\260\345\273\272", 0));
        pushButton_cancel->setText(QApplication::translate("CNewFileDlg", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("CNewFileDlg", "\347\261\273\345\236\213", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("CNewFileDlg", "Scene", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("CNewFileDlg", "Script", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("CNewFileDlg", "UI", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("CNewFileDlg", "Map", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class CNewFileDlg: public Ui_CNewFileDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CNEW_FILE_DLG_H
