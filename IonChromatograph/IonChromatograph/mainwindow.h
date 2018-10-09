#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QGroupBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int levelNumber;
    int funcNumber;

private slots:
    void setButtonId();
    void levelShow();
    void levelChose(int levelTT);
    void funcChose(int funcTT);
    void ADC_Data(int ADCTT);
    QString TCP(int sBuf);

};

#endif // MAINWINDOW_H
