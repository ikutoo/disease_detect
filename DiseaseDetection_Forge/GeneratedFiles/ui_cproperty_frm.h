/********************************************************************************
** Form generated from reading UI file 'cproperty_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPROPERTY_FRM_H
#define UI_CPROPERTY_FRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CPropertyFrm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox_blur;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *comboBox_detect;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_detThreshold;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QCheckBox *checkBox_maft;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QCheckBox *checkBox_projection;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QCheckBox *checkBox_mutliC;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEdit_binThreshold;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_save;
    QPushButton *pushButton_detect;
    QPushButton *pushButton_read;

    void setupUi(QFrame *CPropertyFrm)
    {
        if (CPropertyFrm->objectName().isEmpty())
            CPropertyFrm->setObjectName(QStringLiteral("CPropertyFrm"));
        CPropertyFrm->resize(456, 463);
        CPropertyFrm->setMinimumSize(QSize(400, 400));
        CPropertyFrm->setBaseSize(QSize(400, 400));
        CPropertyFrm->setStyleSheet(QStringLiteral(""));
        CPropertyFrm->setFrameShape(QFrame::StyledPanel);
        CPropertyFrm->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(CPropertyFrm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(CPropertyFrm);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox_blur = new QComboBox(CPropertyFrm);
        comboBox_blur->setObjectName(QStringLiteral("comboBox_blur"));
        comboBox_blur->setStyleSheet(QLatin1String("color :rgb(255, 255, 255);\n"
"background: rgb(40, 40, 40);"));

        horizontalLayout->addWidget(comboBox_blur);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(CPropertyFrm);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        comboBox_detect = new QComboBox(CPropertyFrm);
        comboBox_detect->setObjectName(QStringLiteral("comboBox_detect"));
        comboBox_detect->setAutoFillBackground(false);
        comboBox_detect->setStyleSheet(QLatin1String("color :rgb(255, 255, 255);\n"
"background: rgb(40, 40, 40);"));

        horizontalLayout_5->addWidget(comboBox_detect);


        horizontalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(CPropertyFrm);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_detThreshold = new QLineEdit(CPropertyFrm);
        lineEdit_detThreshold->setObjectName(QStringLiteral("lineEdit_detThreshold"));
        lineEdit_detThreshold->setStyleSheet(QLatin1String("color :rgb(255, 255, 255);\n"
"background: rgb(40, 40, 40);"));

        horizontalLayout_6->addWidget(lineEdit_detThreshold);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(CPropertyFrm);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        checkBox_maft = new QCheckBox(CPropertyFrm);
        checkBox_maft->setObjectName(QStringLiteral("checkBox_maft"));
        checkBox_maft->setEnabled(true);
        checkBox_maft->setStyleSheet(QStringLiteral(""));
        checkBox_maft->setChecked(false);

        horizontalLayout_2->addWidget(checkBox_maft);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(CPropertyFrm);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        checkBox_projection = new QCheckBox(CPropertyFrm);
        checkBox_projection->setObjectName(QStringLiteral("checkBox_projection"));

        horizontalLayout_3->addWidget(checkBox_projection);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(CPropertyFrm);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        checkBox_mutliC = new QCheckBox(CPropertyFrm);
        checkBox_mutliC->setObjectName(QStringLiteral("checkBox_mutliC"));

        horizontalLayout_4->addWidget(checkBox_mutliC);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(CPropertyFrm);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEdit_binThreshold = new QLineEdit(CPropertyFrm);
        lineEdit_binThreshold->setObjectName(QStringLiteral("lineEdit_binThreshold"));
        lineEdit_binThreshold->setStyleSheet(QLatin1String("color :rgb(255, 255, 255);\n"
"background: rgb(40, 40, 40);"));

        horizontalLayout_8->addWidget(lineEdit_binThreshold);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton_save = new QPushButton(CPropertyFrm);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setEnabled(true);
        pushButton_save->setMaximumSize(QSize(150, 50));
        pushButton_save->setStyleSheet(QStringLiteral("color :rgb(0, 0, 0);background: rgb(255,255,255)"));
        pushButton_save->setCheckable(false);
        pushButton_save->setChecked(false);
        pushButton_save->setAutoDefault(false);
        pushButton_save->setFlat(false);

        horizontalLayout_9->addWidget(pushButton_save);

        pushButton_detect = new QPushButton(CPropertyFrm);
        pushButton_detect->setObjectName(QStringLiteral("pushButton_detect"));
        pushButton_detect->setEnabled(true);
        pushButton_detect->setMaximumSize(QSize(150, 50));
        pushButton_detect->setStyleSheet(QStringLiteral("color :rgb(0, 0, 0);background: rgb(255,255,255)"));
        pushButton_detect->setCheckable(false);
        pushButton_detect->setChecked(false);
        pushButton_detect->setAutoDefault(false);
        pushButton_detect->setFlat(false);

        horizontalLayout_9->addWidget(pushButton_detect);

        pushButton_read = new QPushButton(CPropertyFrm);
        pushButton_read->setObjectName(QStringLiteral("pushButton_read"));
        pushButton_read->setEnabled(true);
        pushButton_read->setMaximumSize(QSize(150, 50));
        pushButton_read->setStyleSheet(QStringLiteral("color :rgb(0, 0, 0);background: rgb(255,255,255)"));
        pushButton_read->setCheckable(false);
        pushButton_read->setChecked(false);
        pushButton_read->setAutoDefault(false);
        pushButton_read->setFlat(false);

        horizontalLayout_9->addWidget(pushButton_read);


        verticalLayout->addLayout(horizontalLayout_9);


        retranslateUi(CPropertyFrm);

        QMetaObject::connectSlotsByName(CPropertyFrm);
    } // setupUi

    void retranslateUi(QFrame *CPropertyFrm)
    {
        CPropertyFrm->setWindowTitle(QApplication::translate("CPropertyFrm", "Frame", 0));
        label_2->setText(QApplication::translate("CPropertyFrm", "\345\271\263\346\273\221\346\226\271\345\274\217\357\274\232", 0));
        comboBox_blur->clear();
        comboBox_blur->insertItems(0, QStringList()
         << QApplication::translate("CPropertyFrm", "\351\253\230\346\226\257\346\273\244\346\263\242", 0)
         << QApplication::translate("CPropertyFrm", "\345\235\207\345\200\274\346\273\244\346\263\242", 0)
         << QApplication::translate("CPropertyFrm", "\346\226\271\346\241\206\346\273\244\346\263\242", 0)
         << QApplication::translate("CPropertyFrm", "\344\270\255\345\200\274\346\273\244\346\263\242", 0)
        );
        label_5->setText(QApplication::translate("CPropertyFrm", "\346\243\200\346\265\213\346\226\271\345\274\217\357\274\232", 0));
        comboBox_detect->clear();
        comboBox_detect->insertItems(0, QStringList()
         << QApplication::translate("CPropertyFrm", "\345\255\220\345\235\227\346\226\271\345\267\256\346\263\225", 0)
         << QApplication::translate("CPropertyFrm", "\345\255\220\345\235\227\344\277\241\346\201\257\347\206\265\346\263\225", 0)
        );
        label_6->setText(QApplication::translate("CPropertyFrm", "\351\230\210\345\200\274\357\274\232", 0));
        label_3->setText(QApplication::translate("CPropertyFrm", "\345\202\205\351\207\214\345\217\266\345\217\230\346\215\242\357\274\232", 0));
        checkBox_maft->setText(QApplication::translate("CPropertyFrm", "\345\220\257\347\224\250", 0));
        label_4->setText(QApplication::translate("CPropertyFrm", "\346\212\225\345\275\261\346\243\200\346\265\213\357\274\232", 0));
        checkBox_projection->setText(QApplication::translate("CPropertyFrm", "\345\220\257\347\224\250", 0));
        label_7->setText(QApplication::translate("CPropertyFrm", "\345\244\232\351\200\232\351\201\223\346\243\200\346\265\213\357\274\232", 0));
        checkBox_mutliC->setText(QApplication::translate("CPropertyFrm", "\345\220\257\347\224\250", 0));
        label_8->setText(QApplication::translate("CPropertyFrm", "\344\272\214\345\200\274\345\214\226\351\230\210\345\200\274\357\274\232", 0));
        pushButton_save->setText(QApplication::translate("CPropertyFrm", "\344\277\235\345\255\230\351\205\215\347\275\256", 0));
        pushButton_detect->setText(QApplication::translate("CPropertyFrm", "\346\211\247\350\241\214\346\243\200\346\265\213", 0));
        pushButton_read->setText(QApplication::translate("CPropertyFrm", "\350\257\273\345\217\226\346\243\200\346\265\213\347\273\223\346\236\234", 0));
    } // retranslateUi

};

namespace Ui {
    class CPropertyFrm: public Ui_CPropertyFrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPROPERTY_FRM_H
