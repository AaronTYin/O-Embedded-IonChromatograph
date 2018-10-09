/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QRadioButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *levelBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *level1;
    QRadioButton *level2;
    QRadioButton *level3;
    QRadioButton *level4;
    QRadioButton *level5;
    QRadioButton *level6;
    QRadioButton *level7;
    QRadioButton *levelAuto;
    QLabel *labelLevelShow;
    QLCDNumber *lcdLevelNumber;
    QGroupBox *funcBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QRadioButton *levelChoseButton;
    QRadioButton *ADC0;
    QRadioButton *ADC1;
    QRadioButton *ADC2;
    QRadioButton *ADC3;
    QGroupBox *ADCshow;
    QTextBrowser *ADCtext;
    QGroupBox *AuthorBox;
    QGraphicsView *Author;
    QTextBrowser *AuthorInfo;
    QLabel *label;
    QButtonGroup *funcGroup;
    QButtonGroup *levelGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(462, 284);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        levelBox = new QGroupBox(centralWidget);
        levelBox->setObjectName(QString::fromUtf8("levelBox"));
        levelBox->setGeometry(QRect(100, 10, 351, 71));
        layoutWidget = new QWidget(levelBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 331, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        level1 = new QRadioButton(layoutWidget);
        levelGroup = new QButtonGroup(MainWindow);
        levelGroup->setObjectName(QString::fromUtf8("levelGroup"));
        levelGroup->addButton(level1);
        level1->setObjectName(QString::fromUtf8("level1"));

        horizontalLayout->addWidget(level1);

        level2 = new QRadioButton(layoutWidget);
        levelGroup->addButton(level2);
        level2->setObjectName(QString::fromUtf8("level2"));

        horizontalLayout->addWidget(level2);

        level3 = new QRadioButton(layoutWidget);
        levelGroup->addButton(level3);
        level3->setObjectName(QString::fromUtf8("level3"));

        horizontalLayout->addWidget(level3);

        level4 = new QRadioButton(layoutWidget);
        levelGroup->addButton(level4);
        level4->setObjectName(QString::fromUtf8("level4"));

        horizontalLayout->addWidget(level4);

        level5 = new QRadioButton(layoutWidget);
        levelGroup->addButton(level5);
        level5->setObjectName(QString::fromUtf8("level5"));

        horizontalLayout->addWidget(level5);

        level6 = new QRadioButton(layoutWidget);
        levelGroup->addButton(level6);
        level6->setObjectName(QString::fromUtf8("level6"));

        horizontalLayout->addWidget(level6);

        level7 = new QRadioButton(layoutWidget);
        levelGroup->addButton(level7);
        level7->setObjectName(QString::fromUtf8("level7"));

        horizontalLayout->addWidget(level7);

        levelAuto = new QRadioButton(layoutWidget);
        levelGroup->addButton(levelAuto);
        levelAuto->setObjectName(QString::fromUtf8("levelAuto"));
        levelAuto->setChecked(true);

        horizontalLayout->addWidget(levelAuto);

        labelLevelShow = new QLabel(centralWidget);
        labelLevelShow->setObjectName(QString::fromUtf8("labelLevelShow"));
        labelLevelShow->setGeometry(QRect(10, 10, 101, 18));
        lcdLevelNumber = new QLCDNumber(centralWidget);
        lcdLevelNumber->setObjectName(QString::fromUtf8("lcdLevelNumber"));
        lcdLevelNumber->setGeometry(QRect(10, 40, 81, 31));
        lcdLevelNumber->setSmallDecimalPoint(false);
        funcBox = new QGroupBox(centralWidget);
        funcBox->setObjectName(QString::fromUtf8("funcBox"));
        funcBox->setGeometry(QRect(10, 90, 91, 181));
        layoutWidget1 = new QWidget(funcBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 71, 146));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        levelChoseButton = new QRadioButton(layoutWidget1);
        funcGroup = new QButtonGroup(MainWindow);
        funcGroup->setObjectName(QString::fromUtf8("funcGroup"));
        funcGroup->addButton(levelChoseButton);
        levelChoseButton->setObjectName(QString::fromUtf8("levelChoseButton"));
        levelChoseButton->setChecked(true);

        verticalLayout->addWidget(levelChoseButton);

        ADC0 = new QRadioButton(layoutWidget1);
        funcGroup->addButton(ADC0);
        ADC0->setObjectName(QString::fromUtf8("ADC0"));

        verticalLayout->addWidget(ADC0);

        ADC1 = new QRadioButton(layoutWidget1);
        funcGroup->addButton(ADC1);
        ADC1->setObjectName(QString::fromUtf8("ADC1"));

        verticalLayout->addWidget(ADC1);

        ADC2 = new QRadioButton(layoutWidget1);
        funcGroup->addButton(ADC2);
        ADC2->setObjectName(QString::fromUtf8("ADC2"));

        verticalLayout->addWidget(ADC2);

        ADC3 = new QRadioButton(layoutWidget1);
        funcGroup->addButton(ADC3);
        ADC3->setObjectName(QString::fromUtf8("ADC3"));

        verticalLayout->addWidget(ADC3);

        ADCshow = new QGroupBox(centralWidget);
        ADCshow->setObjectName(QString::fromUtf8("ADCshow"));
        ADCshow->setGeometry(QRect(109, 89, 151, 181));
        ADCtext = new QTextBrowser(ADCshow);
        ADCtext->setObjectName(QString::fromUtf8("ADCtext"));
        ADCtext->setGeometry(QRect(10, 30, 131, 141));
        AuthorBox = new QGroupBox(centralWidget);
        AuthorBox->setObjectName(QString::fromUtf8("AuthorBox"));
        AuthorBox->setGeometry(QRect(270, 90, 181, 181));
        Author = new QGraphicsView(AuthorBox);
        Author->setObjectName(QString::fromUtf8("Author"));
        Author->setGeometry(QRect(10, 30, 161, 111));
        Author->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/MZ.jpg);"));
        AuthorInfo = new QTextBrowser(AuthorBox);
        AuthorInfo->setObjectName(QString::fromUtf8("AuthorInfo"));
        AuthorInfo->setGeometry(QRect(10, 40, 161, 131));
        AuthorInfo->setStyleSheet(QString::fromUtf8("border:0;"));
        label = new QLabel(AuthorBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(33, 150, 121, 20));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"Sans Serif\";"));
        label->setTextFormat(Qt::AutoText);
        AuthorInfo->raise();
        label->raise();
        Author->raise();
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        levelBox->setTitle(QApplication::translate("MainWindow", "level", 0, QApplication::UnicodeUTF8));
        level1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        level2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        level3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        level4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        level5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        level6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        level7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        levelAuto->setText(QApplication::translate("MainWindow", "Auto", 0, QApplication::UnicodeUTF8));
        labelLevelShow->setText(QApplication::translate("MainWindow", "LevelShow", 0, QApplication::UnicodeUTF8));
        funcBox->setTitle(QApplication::translate("MainWindow", "Function", 0, QApplication::UnicodeUTF8));
        levelChoseButton->setText(QApplication::translate("MainWindow", "Level", 0, QApplication::UnicodeUTF8));
        ADC0->setText(QApplication::translate("MainWindow", "ADC0", 0, QApplication::UnicodeUTF8));
        ADC1->setText(QApplication::translate("MainWindow", "ADC1", 0, QApplication::UnicodeUTF8));
        ADC2->setText(QApplication::translate("MainWindow", "ADC2", 0, QApplication::UnicodeUTF8));
        ADC3->setText(QApplication::translate("MainWindow", "ADC3", 0, QApplication::UnicodeUTF8));
        ADCshow->setTitle(QApplication::translate("MainWindow", "ADCshow", 0, QApplication::UnicodeUTF8));
        AuthorBox->setTitle(QApplication::translate("MainWindow", "Author", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "By : AaronYin - MZ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
