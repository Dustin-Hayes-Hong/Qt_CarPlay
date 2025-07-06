#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "pushbutton/mypushbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    static constexpr int m_screenHeigh = 600;
    static constexpr int m_screenWidth = 1024;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    void initUi();

    void setBackground(const QPixmap &pixmap);
    QWidget *Page_Home();

};
#endif // MAINWINDOW_H
