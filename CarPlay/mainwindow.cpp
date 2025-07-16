#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    auto *pLayout = new QVBoxLayout(centralWidget);

    // 添加 TopWidget 到顶部
    pLayout->addWidget(m_pTopWidget, 0, Qt::AlignTop | Qt::AlignHCenter);

    // 创建 QHBoxLayout 用于 CmdWidget 和 DesktopWidget
    auto *pHLayout = new QHBoxLayout;
    pHLayout->addWidget(m_pCmdWidget, 0, Qt::AlignLeft | Qt::AlignVCenter); // 左侧 CmdWidget
    pHLayout->addWidget(m_pDesktopWidget, 1); // 右侧 DesktopWidget
    pHLayout->setContentsMargins(0, 0, 0, 0);
    pHLayout->setSpacing(0);

    pLayout->addLayout(pHLayout);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pLayout->setSpacing(0);

    // 添加拉伸项
    pLayout->addStretch();

    // 连接 CmdWidget 的 toggleLabels 信号
    connect(m_pCmdWidget, &CmdWidget::toggleLabels, this, [this](bool show) {
        if (show) {
            m_pDesktopWidget->showLabels();
        } else {
            m_pDesktopWidget->hideLabels();
        }
    });

    setCentralWidget(centralWidget);
    setFixedSize(m_screenWidth, m_screenHeigh);
}

MainWindow::~MainWindow()
{
}
