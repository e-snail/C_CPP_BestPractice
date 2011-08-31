#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBitmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


 //     ui->bt->setIcon(p);
//     ui->bt->setFixedSize(p.width(), p.height());

//     ui->bt->setPixmap(p);
//     ui->bt->setMask(p.mask());

//     ui->label->setPixmap(p);
//     ui->label->setMask(p.mask());


    QPixmap p("./Comma.png");
    QPixmap pp("./CommaPressed.png");

    ui->labelN->setPixmap(p);
    ui->labelN->setMask(p.mask());

     ui->labelP->setPixmap(pp);
     ui->labelP->setMask(pp.mask());

//     this->setAttribute(Qt::WA_TranslucentBackground);
     ui->pushButton->setAttribute(Qt::WA_TranslucentBackground);
}

MainWindow::~MainWindow()
{
    delete ui;
}
