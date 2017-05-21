/********************************************************************************
** Form generated from reading UI file 'cconsole_frm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCONSOLE_FRM_H
#define UI_CCONSOLE_FRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_CConsoleFrm
{
public:

    void setupUi(QFrame *CConsoleFrm)
    {
        if (CConsoleFrm->objectName().isEmpty())
            CConsoleFrm->setObjectName(QStringLiteral("CConsoleFrm"));
        CConsoleFrm->resize(507, 334);

        retranslateUi(CConsoleFrm);

        QMetaObject::connectSlotsByName(CConsoleFrm);
    } // setupUi

    void retranslateUi(QFrame *CConsoleFrm)
    {
        CConsoleFrm->setWindowTitle(QApplication::translate("CConsoleFrm", "CConsoleFrm", 0));
    } // retranslateUi

};

namespace Ui {
    class CConsoleFrm: public Ui_CConsoleFrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCONSOLE_FRM_H
