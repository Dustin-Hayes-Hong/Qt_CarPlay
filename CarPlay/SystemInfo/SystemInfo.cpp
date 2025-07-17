#include "mainwindow.h"

#include <QDateTime>
#include <QTimer>

void MainWindow::updateSysInfo()
{
    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [&](){
        if(m_pTopWidget){
            m_pTopWidget->setSysTimeText(QDateTime::currentDateTimeUtc().addSecs(60 * 60 * 8).toString("yyyy-MM-dd hh:mm:ss"));
        }
    });
    timer->start(999);
}
