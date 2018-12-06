#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "codelib/image/rgb.image.h"
#include <iostream>
#include <QImage>
#include <QPixmap>
#include "utils.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    codelib::rgb_image _lena   = Utils::QImage2RGBImage(QImage(":/images/lena.jpg"));
    codelib::rgb_image _rice   = Utils::QImage2RGBImage(QImage(":/images/rice.png"));
    codelib::rgb_image _cacos  = Utils::QImage2RGBImage(QImage(":/images/cacos.jpg"));

    ui->l1->setPixmap(QPixmap::fromImage(Utils::RGBImage2QImage(_lena)));
    ui->l2->setPixmap(QPixmap::fromImage(Utils::GrayImage2QImage(_lena.to_gray())));
    ui->l3->setPixmap(QPixmap::fromImage(Utils::BinaryImage2QImage(_lena.to_gray().to_binary())));

    ui->l4->setPixmap(QPixmap::fromImage(Utils::RGBImage2QImage(_rice)));
    ui->l5->setPixmap(QPixmap::fromImage(Utils::GrayImage2QImage(_rice.to_gray())));
    ui->l6->setPixmap(QPixmap::fromImage(Utils::BinaryImage2QImage(_rice.to_gray().to_binary())));

    ui->l7->setPixmap(QPixmap::fromImage(Utils::RGBImage2QImage(_cacos)));
    ui->l8->setPixmap(QPixmap::fromImage(Utils::GrayImage2QImage(_cacos.to_gray())));
    ui->l9->setPixmap(QPixmap::fromImage(Utils::BinaryImage2QImage(_cacos.to_gray().to_binary())));

}

MainWindow::~MainWindow()
{
    delete ui;
}
