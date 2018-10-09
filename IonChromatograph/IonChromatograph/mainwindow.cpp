#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QProcess"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setButtonId();
    connect(ui->levelGroup,SIGNAL(buttonClicked(int)),this,SLOT(levelChose(int)));
    connect(ui->funcGroup,SIGNAL(buttonClicked(int)),this,SLOT(funcChose(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setButtonId()
{
    ui->levelGroup->setId(ui->level1,1);
    ui->levelGroup->setId(ui->level2,2);
    ui->levelGroup->setId(ui->level3,3);
    ui->levelGroup->setId(ui->level4,4);
    ui->levelGroup->setId(ui->level5,5);
    ui->levelGroup->setId(ui->level6,6);
    ui->levelGroup->setId(ui->level7,7);
    ui->levelGroup->setId(ui->levelAuto,8);
    //qDebug()<<levelNumber;
    levelNumber=8;
    //qDebug()<<levelNumber;

    ui->ADCshow->setEnabled(false);

    ui->funcGroup->setId(ui->levelChoseButton,0);
    ui->funcGroup->setId(ui->ADC0,10);
    ui->funcGroup->setId(ui->ADC1,11);
    ui->funcGroup->setId(ui->ADC2,12);
    ui->funcGroup->setId(ui->ADC3,13);
    //qDebug()<<funcNumber;
    funcNumber=0;
    //qDebug()<<funcNumber;
}

void MainWindow::levelShow()
{
    ui->lcdLevelNumber->display(levelNumber);
}

void MainWindow::levelChose(int levelTT)
{
    levelNumber=levelTT;//ui->levelGroup->checkedId();
    //qDebug()<<levelNumber;
    levelShow();
    TCP(levelNumber);
}

void MainWindow::funcChose(int funcTT)
{
    funcNumber=funcTT;
    //qDebug()<<funcNumber;
    if(funcNumber==0)
    {
        ui->levelBox->setEnabled(true);
        ui->ADCshow->setEnabled(false);
        ADC_Data(0);
    }
    else if(funcNumber==10)
    {
        ui->ADCshow->setEnabled(true);
        ui->levelBox->setEnabled(false);
        ADC_Data(0);
        ADC_Data(10);
    }
    else if(funcNumber==11)
    {
        ui->ADCshow->setEnabled(true);
        ui->levelBox->setEnabled(false);
        ADC_Data(0);
        ADC_Data(11);
    }
    else if(funcNumber==12)
    {
        ui->ADCshow->setEnabled(true);
        ui->levelBox->setEnabled(false);
        ADC_Data(0);
        ADC_Data(12);
    }
    else if(funcNumber==13)
    {
        ui->ADCshow->setEnabled(true);
        ui->levelBox->setEnabled(false);
        ADC_Data(0);
        ADC_Data(13);
    }
}

void MainWindow::ADC_Data(int ADCTT)
{
    switch (ADCTT) {
    case 0:
        ui->ADCtext->clear();
        break;
    /*case 10:
        for(int i=0;i<10;i++)
            ui->ADCtext->textCursor().insertText("ADC=0000"+QString::number(i)+"\n");
        break;
    case 11:
        for(int i=0;i<10;i++)
            ui->ADCtext->textCursor().insertText("ADC=1100"+QString::number(i)+"\n");
        break;
    case 12:
        for(int i=0;i<10;i++)
            ui->ADCtext->textCursor().insertText("ADC=2200"+QString::number(i)+"\n");
        break;
    case 13:
        for(int i=0;i<10;i++)
            ui->ADCtext->textCursor().insertText("ADC=3300"+QString::number(i)+"\n");
        break;*/
    default:
        for(int i=0;i<10;i++)
        {
            QString rTT=TCP(10);
            ui->ADCtext->textCursor().insertText(rTT+"\n");
            //qDebug()<<rTT;
        }

        break;
    }
}

QString MainWindow::TCP(int sBuf)
{
    QString output;
    QString rBuf;
    QProcess sys;

    switch (sBuf) {
    case 1:
        system("./pc 192.168.1.230 2W411103");
        break;
    case 2:
        system("./pc 192.168.1.230 2W411013");
        break;
    case 3:
        system("./pc 192.168.1.230 2W411003");
        break;
    case 4:
        system("./pc 192.168.1.230 2W410113");
        break;
    case 5:
        system("./pc 192.168.1.230 2W410103");
        break;
    case 6:
        system("./pc 192.168.1.230 2W410013");
        break;
    case 7:
        system("./pc 192.168.1.230 2W410003");
        break;
    case 8:
        system("./pc 192.168.1.230 2W401113");
        break;
    case 10:
    {
        sys.start("./pc 192.168.1.230 2R000003");
        sys.waitForFinished();
        output=sys.readAllStandardOutput();
        rBuf=output.mid(3,4);
        //qDebug()<<rBuf;
        break;
    }
    default:
        break;
    }

    return rBuf;
}
