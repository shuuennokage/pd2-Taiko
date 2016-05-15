#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTime>
#include <QTimer>
#include <QDateTime>
#include <QPoint>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void keyPressEvent(QKeyEvent *taiko);

private slots:
    void on_pushButton_clicked();
    void updateTime();
    void on_pushButton_2_clicked();
    void on_Owari_clicked();
    void on_Again_clicked();
    void generateAll();
    void generateDon();
    void generateDon2();
    void generateDon3();
    void generateDon4();
    void generateKa();
    void generateKa2();
    void generateKa3();
    void generateKa4();
    void movementDon();
    void movementDon2();
    void movementDon3();
    void movementDon4();
    void movementKa();
    void movementKa2();
    void movementKa3();
    void movementKa4();
    void kesuDon();
    void kesuDon2();
    void kesuDon3();
    void kesuDon4();
    void kesuKa();
    void kesuKa2();
    void kesuKa3();
    void kesuKa4();
    void kesuKouka();
    void kesuend();
    

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timerG;
    QTimer *timerK;
    QTimer *timerDon;
    QTimer *timerDon2;
    QTimer *timerDon3;
    QTimer *timerDon4;
    QTimer *timerKa;
    QTimer *timerKa2;
    QTimer *timerKa3;
    QTimer *timerKa4;
    int count;
    int score;
    static const int speed = 2;
    int used[8] = {0};
};

#endif // MAINWINDOW_H
