/********************************************************************************
** Form generated from reading UI file 'cnew_project_dlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CNEW_PROJECT_DLG_H
#define UI_CNEW_PROJECT_DLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CNewProjectDlg
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancle;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_path;
    QPushButton *pushButton_browse;

    void setupUi(QDialog *CNewProjectDlg)
    {
        if (CNewProjectDlg->objectName().isEmpty())
            CNewProjectDlg->setObjectName(QStringLiteral("CNewProjectDlg"));
        CNewProjectDlg->resize(500, 360);
        CNewProjectDlg->setMinimumSize(QSize(500, 360));
        CNewProjectDlg->setMaximumSize(QSize(500, 360));
        QIcon icon;
        icon.addFile(QStringLiteral(":/picture/ui_picture/ygg.png"), QSize(), QIcon::Normal, QIcon::Off);
        CNewProjectDlg->setWindowIcon(icon);
        CNewProjectDlg->setSizeGripEnabled(false);
        CNewProjectDlg->setModal(true);
        layoutWidget = new QWidget(CNewProjectDlg);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 70, 321, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);

        layoutWidget1 = new QWidget(CNewProjectDlg);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(250, 240, 158, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_ok = new QPushButton(layoutWidget1);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        horizontalLayout_3->addWidget(pushButton_ok);

        pushButton_cancle = new QPushButton(layoutWidget1);
        pushButton_cancle->setObjectName(QStringLiteral("pushButton_cancle"));

        horizontalLayout_3->addWidget(pushButton_cancle);

        layoutWidget2 = new QWidget(CNewProjectDlg);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 110, 401, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_path = new QLineEdit(layoutWidget2);
        lineEdit_path->setObjectName(QStringLiteral("lineEdit_path"));
        lineEdit_path->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_path);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        pushButton_browse = new QPushButton(layoutWidget2);
        pushButton_browse->setObjectName(QStringLiteral("pushButton_browse"));

        horizontalLayout_4->addWidget(pushButton_browse);


        retranslateUi(CNewProjectDlg);
        QObject::connect(pushButton_ok, SIGNAL(clicked()), CNewProjectDlg, SLOT(accept()));
        QObject::connect(pushButton_cancle, SIGNAL(clicked()), CNewProjectDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CNewProjectDlg);
    } // setupUi

    void retranslateUi(QDialog *CNewProjectDlg)
    {
        CNewProjectDlg->setWindowTitle(QApplication::translate("CNewProjectDlg", "\346\226\260\345\273\272\345\267\245\347\250\213", 0));
        label->setText(QApplication::translate("CNewProjectDlg", "\351\241\271\347\233\256\345\220\215\347\247\260\357\274\232", 0));
        pushButton_ok->setText(QApplication::translate("CNewProjectDlg", "\347\241\256\350\256\244", 0));
        pushButton_cancle->setText(QApplication::translate("CNewProjectDlg", "\345\217\226\346\266\210", 0));
        label_2->setText(QApplication::translate("CNewProjectDlg", "\351\241\271\347\233\256\350\267\257\345\276\204\357\274\232", 0));
        pushButton_browse->setText(QApplication::translate("CNewProjectDlg", "\346\265\217\350\247\210", 0));
    } // retranslateUi

};

namespace Ui {
    class CNewProjectDlg: public Ui_CNewProjectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CNEW_PROJECT_DLG_H
