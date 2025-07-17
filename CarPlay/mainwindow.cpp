#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    auto *pLayout = new QVBoxLayout(centralWidget);

    pLayout->addWidget(m_pTopWidget, 0, Qt::AlignTop | Qt::AlignHCenter);
    auto *pHLayout = new QHBoxLayout;
    pHLayout->addWidget(m_pCmdWidget, 0, Qt::AlignLeft | Qt::AlignVCenter);
    pHLayout->addWidget(m_pDesktopWidget, 1);
    pHLayout->setContentsMargins(0, 0, 0, 0);
    pHLayout->setSpacing(0);
    pLayout->addLayout(pHLayout);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pLayout->setSpacing(0);
    pLayout->addStretch();

    setCentralWidget(centralWidget);
    setFixedSize(m_screenWidth, m_screenHeigh);
    setBackground(QPixmap(":/misc/room.jpg"));

    updateSysInfo();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setBackground(const QPixmap &pixmap)
{
    if (!pixmap.isNull()) {
        QPalette palette = this->palette();
        palette.setBrush(backgroundRole(), pixmap.scaled(m_screenWidth, m_screenHeigh, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        setPalette(palette);
        setAutoFillBackground(true);
    } else {
        qDebug() << "背景图片加载失败: :/misc/room.jpg";
    }
}
