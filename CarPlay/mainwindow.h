#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "TopWidget/topwidget.h"
#include "CmdWidget/cmdwidget.h"
#include "DesktopWidget/desktopwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    static constexpr int m_screenHeigh = 600;
    static constexpr int m_screenWidth = 1024;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateSysInfo();

    void setBackground(const QPixmap &pixmap);

private:
    TopWidget    *m_pTopWidget    = new TopWidget(this) ;
    CmdWidget    *m_pCmdWidget    = new CmdWidget(this) ;
    DesktopWidget *m_pDesktopWidget = new DesktopWidget(this);
};
#endif // MAINWINDOW_H
