/********************************************************************************
** Form generated from reading UI file 'cmain_win.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAIN_WIN_H
#define UI_CMAIN_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWin
{
public:
    QAction *action_newFile;
    QAction *action_newProject;
    QAction *action_openProject;
    QAction *action_4;
    QAction *action_exit;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QAction *action_9;
    QAction *action_10;
    QAction *action_object;
    QAction *action_asset;
    QAction *action_hierarchy;
    QAction *action_property;
    QAction *action_game;
    QAction *action_anime;
    QAction *action_console;
    QAction *action_18;
    QAction *action_20;
    QAction *action_21;
    QAction *action_22;
    QAction *action_23;
    QAction *action_closeProject;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_5;
    QAction *action_11;
    QAction *action_12;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMainWin)
    {
        if (CMainWin->objectName().isEmpty())
            CMainWin->setObjectName(QStringLiteral("CMainWin"));
        CMainWin->resize(902, 539);
        QIcon icon;
        icon.addFile(QStringLiteral(":/picture/ui_picture/ygg.png"), QSize(), QIcon::Normal, QIcon::Off);
        CMainWin->setWindowIcon(icon);
        CMainWin->setStyleSheet(QStringLiteral("font-size: 16px"));
        action_newFile = new QAction(CMainWin);
        action_newFile->setObjectName(QStringLiteral("action_newFile"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/picture/ui_picture/toolBar/newFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_newFile->setIcon(icon1);
        action_newProject = new QAction(CMainWin);
        action_newProject->setObjectName(QStringLiteral("action_newProject"));
        action_openProject = new QAction(CMainWin);
        action_openProject->setObjectName(QStringLiteral("action_openProject"));
        action_4 = new QAction(CMainWin);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_exit = new QAction(CMainWin);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_6 = new QAction(CMainWin);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_7 = new QAction(CMainWin);
        action_7->setObjectName(QStringLiteral("action_7"));
        action_8 = new QAction(CMainWin);
        action_8->setObjectName(QStringLiteral("action_8"));
        action_9 = new QAction(CMainWin);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_10 = new QAction(CMainWin);
        action_10->setObjectName(QStringLiteral("action_10"));
        action_object = new QAction(CMainWin);
        action_object->setObjectName(QStringLiteral("action_object"));
        action_object->setCheckable(true);
        action_object->setChecked(true);
        action_asset = new QAction(CMainWin);
        action_asset->setObjectName(QStringLiteral("action_asset"));
        action_asset->setCheckable(true);
        action_asset->setChecked(true);
        action_hierarchy = new QAction(CMainWin);
        action_hierarchy->setObjectName(QStringLiteral("action_hierarchy"));
        action_hierarchy->setCheckable(true);
        action_hierarchy->setChecked(true);
        action_property = new QAction(CMainWin);
        action_property->setObjectName(QStringLiteral("action_property"));
        action_property->setCheckable(true);
        action_property->setChecked(true);
        action_game = new QAction(CMainWin);
        action_game->setObjectName(QStringLiteral("action_game"));
        action_anime = new QAction(CMainWin);
        action_anime->setObjectName(QStringLiteral("action_anime"));
        action_console = new QAction(CMainWin);
        action_console->setObjectName(QStringLiteral("action_console"));
        action_console->setCheckable(true);
        action_console->setChecked(true);
        action_18 = new QAction(CMainWin);
        action_18->setObjectName(QStringLiteral("action_18"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/picture/ui_picture/toolBar/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_18->setIcon(icon2);
        action_20 = new QAction(CMainWin);
        action_20->setObjectName(QStringLiteral("action_20"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/picture/ui_picture/toolBar/preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_20->setIcon(icon3);
        action_21 = new QAction(CMainWin);
        action_21->setObjectName(QStringLiteral("action_21"));
        action_22 = new QAction(CMainWin);
        action_22->setObjectName(QStringLiteral("action_22"));
        action_23 = new QAction(CMainWin);
        action_23->setObjectName(QStringLiteral("action_23"));
        action_closeProject = new QAction(CMainWin);
        action_closeProject->setObjectName(QStringLiteral("action_closeProject"));
        action = new QAction(CMainWin);
        action->setObjectName(QStringLiteral("action"));
        action->setCheckable(true);
        action->setChecked(true);
        action_2 = new QAction(CMainWin);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(CMainWin);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_5 = new QAction(CMainWin);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_11 = new QAction(CMainWin);
        action_11->setObjectName(QStringLiteral("action_11"));
        action_12 = new QAction(CMainWin);
        action_12->setObjectName(QStringLiteral("action_12"));
        centralWidget = new QWidget(CMainWin);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CMainWin->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CMainWin);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 902, 27));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menu_4);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_6 = new QMenu(menuBar);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        CMainWin->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMainWin);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        CMainWin->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CMainWin);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CMainWin->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_6->menuAction());
        menu->addAction(action_newProject);
        menu->addAction(action_openProject);
        menu->addAction(action_4);
        menu->addAction(action_closeProject);
        menu->addAction(action_exit);
        menu_2->addAction(action_6);
        menu_2->addAction(action_7);
        menu_3->addAction(action_asset);
        menu_3->addAction(action_property);
        menu_3->addAction(action_console);
        menu_3->addAction(action);
        menu_4->addAction(action_18);
        menu_4->addAction(menu_5->menuAction());
        menu_4->addAction(action_2);
        menu_4->addAction(action_3);
        menu_4->addAction(action_5);
        menu_4->addAction(action_11);
        menu_4->addAction(action_12);
        menu_5->addAction(action_22);
        menu_5->addAction(action_23);
        mainToolBar->addAction(action_18);

        retranslateUi(CMainWin);
        QObject::connect(action_exit, SIGNAL(triggered()), CMainWin, SLOT(close()));

        QMetaObject::connectSlotsByName(CMainWin);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWin)
    {
        CMainWin->setWindowTitle(QApplication::translate("CMainWin", "DiseaseDetectionForge", 0));
        action_newFile->setText(QApplication::translate("CMainWin", "    \346\226\260\345\273\272\346\226\207\344\273\266  ", 0));
        action_newProject->setText(QApplication::translate("CMainWin", "    \346\226\260\345\273\272\345\267\245\347\250\213  ", 0));
        action_openProject->setText(QApplication::translate("CMainWin", "    \346\211\223\345\274\200\345\267\245\347\250\213  ", 0));
        action_4->setText(QApplication::translate("CMainWin", "    \344\277\235\345\255\230\345\267\245\347\250\213  ", 0));
        action_exit->setText(QApplication::translate("CMainWin", "    \351\200\200\345\207\272  ", 0));
        action_6->setText(QApplication::translate("CMainWin", "    \346\222\244\351\224\200  ", 0));
        action_7->setText(QApplication::translate("CMainWin", "    \351\207\215\345\201\232  ", 0));
        action_8->setText(QApplication::translate("CMainWin", "    \345\244\215\345\210\266  ", 0));
        action_9->setText(QApplication::translate("CMainWin", "    \347\262\230\350\264\264  ", 0));
        action_10->setText(QApplication::translate("CMainWin", "    \345\211\252\345\210\207  ", 0));
        action_object->setText(QApplication::translate("CMainWin", "    \345\257\271\350\261\241  ", 0));
        action_asset->setText(QApplication::translate("CMainWin", "    \350\265\204\344\272\247  ", 0));
        action_hierarchy->setText(QApplication::translate("CMainWin", "    \345\261\202\347\272\247  ", 0));
        action_property->setText(QApplication::translate("CMainWin", "    \345\261\236\346\200\247  ", 0));
        action_game->setText(QApplication::translate("CMainWin", "    \346\270\270\346\210\217  ", 0));
        action_anime->setText(QApplication::translate("CMainWin", "    \345\212\250\347\224\273  ", 0));
        action_console->setText(QApplication::translate("CMainWin", "    \350\276\223\345\207\272  ", 0));
        action_18->setText(QApplication::translate("CMainWin", "    \351\241\271\347\233\256\350\256\276\347\275\256  ", 0));
        action_20->setText(QApplication::translate("CMainWin", "    \351\242\204\350\247\210  ", 0));
        action_21->setText(QApplication::translate("CMainWin", "    \345\217\221\345\270\203  ", 0));
        action_22->setText(QApplication::translate("CMainWin", "    \350\213\261\346\226\207  ", 0));
        action_23->setText(QApplication::translate("CMainWin", "    \347\256\200\344\275\223\344\270\255\346\226\207  ", 0));
        action_closeProject->setText(QApplication::translate("CMainWin", "    \345\205\263\351\227\255\345\267\245\347\250\213  ", 0));
        action->setText(QApplication::translate("CMainWin", "    \346\243\200\346\265\213\347\273\223\346\236\234", 0));
        action_2->setText(QApplication::translate("CMainWin", "    \346\211\271\345\244\204\347\220\206", 0));
        action_3->setText(QApplication::translate("CMainWin", "    \345\274\200\345\247\213\346\243\200\346\265\213", 0));
        action_5->setText(QApplication::translate("CMainWin", "    \345\201\234\346\255\242\346\243\200\346\265\213", 0));
        action_11->setText(QApplication::translate("CMainWin", "    \346\243\200\346\265\213\347\273\223\346\236\234\345\257\274\345\207\272", 0));
        action_12->setText(QApplication::translate("CMainWin", "    \346\243\200\346\265\213\350\256\276\347\275\256", 0));
        menu->setTitle(QApplication::translate("CMainWin", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("CMainWin", "\347\274\226\350\276\221", 0));
        menu_3->setTitle(QApplication::translate("CMainWin", "\347\252\227\345\217\243", 0));
        menu_4->setTitle(QApplication::translate("CMainWin", "\351\241\271\347\233\256", 0));
        menu_5->setTitle(QApplication::translate("CMainWin", "    \350\257\255\350\250\200", 0));
        menu_6->setTitle(QApplication::translate("CMainWin", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class CMainWin: public Ui_CMainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAIN_WIN_H
