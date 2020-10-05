#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CentralWidget = new MainForm(this);
    setCentralWidget(CentralWidget);
    setWindowTitle("Pod Farmer V1.0");
    this->setFixedSize(800,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}
