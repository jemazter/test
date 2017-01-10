#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&theDon,SIGNAL(dataReadyRead(QByteArray)),this,SLOT(dataInDaHouse(QByteArray)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dataInDaHouse(QByteArray data)
{
    QString dataString;
    dataString = data;
    //ui->apiResponseDisplay->setText(data);
    ui->textBrowser->setText(data);
    qDebug()<<data;
}

void MainWindow::on_pushButton_clicked()
{
    QString teste = "SN74S74N";
    theDon.makeRequest("https://octopart.com/api/v3/parts/match",teste);
}
