#include "mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initUi();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initUi()
{
    setObjectName("mainwindow");
    setFixedSize(m_screenWidth, m_screenHeigh); //设置窗口尺寸
    setBackground(QPixmap(":/misc/resource/image/background.jpeg"));    //设置背景图片
    Page_Home();
}

void MainWindow::setBackground(const QPixmap &pixmap)
{
    QPalette  palette = this->palette();
    palette.setBrush(backgroundRole(), pixmap.scaled(m_screenWidth, m_screenHeigh, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));   //缩放图片
    setPalette(palette);
    setAutoFillBackground(true);
}

QWidget *MainWindow::Page_Home()
{
    //音乐按钮
    myPushButton * music_button=new myPushButton(":/misc/musicwidget/images/music.png","",200,200);
    //time1= new QTimer(this);
    music_button->setParent(this);
    music_button->move(200,40);

    //音乐按下
    connect(music_button,&myPushButton::clicked,[=](){
        music_button->zoom1();//弹跳
    });

    //天气按钮
    myPushButton * weather_button=new myPushButton(":/misc/weatherwidget/images/weather_normal.png","",200,200);
    weather_button->setParent(this);
    weather_button->move(500,40);

    //天气按钮按下处理
    connect(weather_button,&myPushButton::clicked,[=](){
        weather_button->zoom1();//弹跳
    });


}
