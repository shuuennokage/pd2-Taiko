#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->MainLabel->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->expDown->setGeometry(105,58,110,107);
    ui->expUp->setGeometry(142,90,41,41);
    ui->good->hide();
    ui->bad->hide();
    ui->expUp->hide();
    ui->expDown->hide();
    ui->Don->hide();
    ui->Don2->hide();
    ui->Don3->hide();
    ui->Don4->hide();
    ui->Ka->hide();
    ui->Ka2->hide();
    ui->Ka3->hide();
    ui->Ka4->hide();
    score = 0;
    count = 20;
    timer = new QTimer;
    timerG = new QTimer;
    ui->tokei->setDigitCount(2);
    ui->tokei->display(count);
    timer->start(1000);
    timerG->start(125);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    connect(timerG,SIGNAL(timeout()),this,SLOT(generateAll()));
}

void MainWindow::updateTime(){
    if(count<=0){
        timer->stop();
        timerG->stop();
        ui->Don->hide();
        ui->Don2->hide();
        ui->Don3->hide();
        ui->Don4->hide();
        ui->Ka->hide();
        ui->Ka2->hide();
        ui->Ka3->hide();
        ui->Ka4->hide();
        ui->setsumeiD->hide();
        ui->setsumeiK->hide();
        ui->label->hide();
        for(int i=0; i<8; i++){
            used[i] = 0;
        }
        ui->GameLabel->hide();
        ui->tokei->hide();
        ui->time->hide();
        ui->tensuu->setDigitCount(2);
        ui->tensuu->display(score);
    }
    count = count - 1;
    ui->tokei->display(count);
}

void MainWindow::on_Owari_clicked()
{
    close();
}

void MainWindow::on_Again_clicked()
{
    ui->GameLabel->show();
    ui->tokei->show();
    ui->time->show();
    ui->setsumeiD->show();
    ui->setsumeiK->show();
    ui->label->show();
    score = 0;
    count = 20;
    timer = new QTimer;
    timerG = new QTimer;
    ui->tokei->setDigitCount(2);
    ui->tokei->display(count);
    timer->start(1000);
    timerG->start(125);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    connect(timerG,SIGNAL(timeout()),this,SLOT(generateAll()));
}

void MainWindow::generateAll(){
    qsrand(QDateTime::currentDateTime().toTime_t());
    int n = qrand() % 8;
    if (n==0){
        generateDon();
    }else if(n==1){
        generateDon2();
    }else if(n==2){
        generateDon3();
    }else if(n==3){
        generateDon4();
    }else if(n==4){
        generateKa();
    }else if(n==5){
        generateKa2();
    }else if(n==6){
        generateKa3();
    }else if(n==7){
        generateKa4();
    }else{

    }
}

void MainWindow::generateDon(){
    if (used[0]==0){
        used[0] = 1;
        //ui->Don->setGeometry(450,90,31,41);
        ui->Don->show();
        timerDon = new QTimer;
        timerDon->start(10);
        connect(timerDon,SIGNAL(timeout()),this,SLOT(movementDon()));
    }
}

void MainWindow::generateDon2(){
    if (used[1]==0){
        used[1] = 1;
        //ui->Don2->setGeometry(450,90,31,41);
        ui->Don2->show();
        timerDon2 = new QTimer;
        timerDon2->start(10);
        connect(timerDon2,SIGNAL(timeout()),this,SLOT(movementDon2()));
    }
}

void MainWindow::generateDon3(){
    if (used[2]==0){
        used[2] = 1;
        //ui->Don3->setGeometry(450,90,31,41);
        ui->Don3->show();
        timerDon3 = new QTimer;
        timerDon3->start(10);
        connect(timerDon3,SIGNAL(timeout()),this,SLOT(movementDon3()));
    }
}

void MainWindow::generateDon4(){
    if (used[3]==0){
        used[3] = 1;
        //ui->Don4->setGeometry(450,90,31,41);
        ui->Don4->show();
        timerDon4 = new QTimer;
        timerDon4->start(10);
        connect(timerDon4,SIGNAL(timeout()),this,SLOT(movementDon4()));
    }
}

void MainWindow::generateKa(){
    if (used[4]==0){
        used[4] = 1;
        //ui->Ka->setGeometry(450,90,31,41);
        ui->Ka->show();
        timerKa = new QTimer;
        timerKa->start(10);
        connect(timerKa,SIGNAL(timeout()),this,SLOT(movementKa()));
    }
}

void MainWindow::generateKa2(){
    if (used[5]==0){
        used[5] = 1;
        //ui->Ka2->setGeometry(450,90,31,41);
        ui->Ka2->show();
        timerKa2 = new QTimer;
        timerKa2->start(10);
        connect(timerKa2,SIGNAL(timeout()),this,SLOT(movementKa2()));
    }
}

void MainWindow::generateKa3(){
    if (used[6]==0){
        used[6] = 1;
        //ui->Ka3->setGeometry(450,90,31,41);
        ui->Ka3->show();
        timerKa3 = new QTimer;
        timerKa3->start(10);
        connect(timerKa3,SIGNAL(timeout()),this,SLOT(movementKa3()));
    }
}

void MainWindow::generateKa4(){
    if (used[7]==0){
        used[7] = 1;
        //ui->Ka4->setGeometry(450,90,31,41);
        ui->Ka4->show();
        timerKa4 = new QTimer;
        timerKa4->start(10);
        connect(timerKa4,SIGNAL(timeout()),this,SLOT(movementKa4()));
    }
}

void MainWindow::movementDon(){
    int x = ui->Don->x();
    int y = ui->Don->y();
    if(ui->Don->x()<=80){
        used[0] = 0;
        timerDon->stop();
        //kesuNot();
        ui->Don->setGeometry(450,90,31,41);
        ui->Don->hide();
    }
    ui->Don->move(x-speed,y);
}

void MainWindow::movementDon2(){
    int x = ui->Don2->x();
    int y = ui->Don2->y();
    if(ui->Don2->x()<=80){
        used[1] = 0;
        timerDon2->stop();
        //kesuNot();
        ui->Don2->setGeometry(450,90,31,41);
        ui->Don2->hide();
    }
    ui->Don2->move(x-speed,y);
}

void MainWindow::movementDon3(){
    int x = ui->Don3->x();
    int y = ui->Don3->y();
    if(ui->Don3->x()<=80){
        used[2] = 0;
        timerDon3->stop();
        //kesuNot();
        ui->Don3->setGeometry(450,90,31,41);
        ui->Don3->hide();;
    }
    ui->Don3->move(x-speed,y);
}

void MainWindow::movementDon4(){
    int x = ui->Don4->x();
    int y = ui->Don4->y();
    if(ui->Don4->x()<=80){
        used[3] = 0;
        timerDon4->stop();
        //kesuNot();
        ui->Don4->setGeometry(450,90,31,41);
        ui->Don4->hide();
    }
    ui->Don4->move(x-speed,y);
}

void MainWindow::movementKa(){
    int x = ui->Ka->x();
    int y = ui->Ka->y();
    if(ui->Ka->x()<=80){
        used[4] = 0;
        timerKa->stop();
        //kesuNot();
        ui->Ka->setGeometry(450,90,31,41);
        ui->Ka->hide();
    }
    ui->Ka->move(x-speed,y);
}

void MainWindow::movementKa2(){
    int x = ui->Ka2->x();
    int y = ui->Ka2->y();
    if(ui->Ka2->x()<=80){
        used[5] = 0;
        timerKa2->stop();
        //kesuNot();
        ui->Ka2->setGeometry(450,90,31,41);
        ui->Ka2->hide();
    }
    ui->Ka2->move(x-speed,y);
}

void MainWindow::movementKa3(){
    int x = ui->Ka3->x();
    int y = ui->Ka3->y();
    if(ui->Ka3->x()<=80){
        used[6] = 0;
        timerKa3->stop();
        //kesuNot();
        ui->Ka3->setGeometry(450,90,31,41);
        ui->Ka3->hide();
    }
    ui->Ka3->move(x-speed,y);
}

void MainWindow::movementKa4(){
    int x = ui->Ka4->x();
    int y = ui->Ka4->y();
    if(ui->Ka4->x()<=80){
        used[7] = 0;
        timerKa4->stop();
        //kesuNot();
        ui->Ka4->setGeometry(450,90,31,41);
        ui->Ka4->hide();
    }
    ui->Ka4->move(x-speed,y);
}

void MainWindow::keyPressEvent(QKeyEvent *taiko){
    if(taiko->key() == Qt::Key_J){
       kesuDon();
       kesuDon2();
       kesuDon3();
       kesuDon4();
    }
    if(taiko->key() == Qt::Key_K){
       kesuKa();
       kesuKa2();
       kesuKa3();
       kesuKa4();
    }
}

void MainWindow::kesuDon(){
    if(ui->Don->x()<=190 && ui->Don->x()>=130){
        used[0] = 0;
        timerDon->stop();
        ui->Don->setGeometry(450,90,31,41);
        ui->Don->hide();
        score++;
        kesuKouka();
    }
}

void MainWindow::kesuDon2(){
    if(ui->Don2->x()<=190 && ui->Don2->x()>=130){
        used[1] = 0;
        timerDon2->stop();
        ui->Don2->setGeometry(450,90,31,41);
        ui->Don2->hide();
        score++;
        kesuKouka();
    }
}

void MainWindow::kesuDon3(){
    if(ui->Don3->x()<=190 && ui->Don3->x()>=130){
        used[2] = 0;
        timerDon3->stop();
        ui->Don3->setGeometry(450,90,31,41);
        ui->Don3->hide();
        score++;
        kesuKouka();
    }
}

void MainWindow::kesuDon4(){
    if(ui->Don4->x()<=190 && ui->Don4->x()>=130){
        used[3] = 0;
        timerDon4->stop();
        ui->Don4->setGeometry(450,90,31,41);
        ui->Don4->hide();
        score++;
        kesuKouka();
    }
}

void MainWindow::kesuKa(){
    if(ui->Ka->x()<=190 && ui->Ka->x()>=130){
        used[4] = 0;
        timerKa->stop();
        ui->Ka->setGeometry(450,90,31,41);
        ui->Ka->hide();
        score++;
        kesuKouka();
    }
}

void MainWindow::kesuKa2(){
    if(ui->Ka2->x()<=190 && ui->Ka2->x()>=130){
        used[5] = 0;
        timerKa2->stop();
        ui->Ka2->setGeometry(450,90,31,41);
        ui->Ka2->hide();
        score++;
        kesuKouka();
    }
}

void MainWindow::kesuKa3(){
    if(ui->Ka3->x()<=190 && ui->Ka3->x()>=130){
        used[6] = 0;
        timerKa3->stop();
        ui->Ka3->setGeometry(450,90,31,41);
        ui->Ka3->hide();
        score++;
        kesuKouka();
    }
}

void MainWindow::kesuKa4(){
    if(ui->Ka4->x()<=190 && ui->Ka4->x()>=130){
        used[7] = 0;
        timerKa4->stop();
        ui->Ka4->setGeometry(450,90,31,41);
        ui->Ka4->hide();
        score++;
        kesuKouka();
    }
}

void MainWindow::kesuKouka(){
    timerK = new QTimer;
    ui->expDown->show();
    ui->expUp->show();
    ui->good->show();
    timerK->start(200);
    connect(timerK,SIGNAL(timeout()),this,SLOT(kesuend()));
}

void MainWindow::kesuend(){
    timerK->stop();
    ui->expDown->hide();
    ui->expUp->hide();
    ui->good->hide();
}
