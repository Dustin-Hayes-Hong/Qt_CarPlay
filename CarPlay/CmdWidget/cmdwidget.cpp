#include "cmdwidget.h"
#include <QVBoxLayout>

CmdWidget::CmdWidget(QWidget *parent)
    : QWidget(parent)
{
    // 创建 4 个 PushApp 按钮，使用单一图标
    m_pBackButton = new PushApp(":/misc/MusicWidget/images/music.png", 80, 80, this);
    m_pSettingsButton = new PushApp(":/misc/MusicWidget/images/music.png", 80, 80, this);
    m_pExitButton = new PushApp(":/misc/MusicWidget/images/music.png", 80, 80, this);
    m_pToggleLabelButton = new PushApp(":/misc/MusicWidget/images/music.png", 80, 80, this);

    // 创建垂直布局
    auto *pLayout = new QVBoxLayout;
    pLayout->addWidget(m_pBackButton, 0, Qt::AlignHCenter);
    pLayout->addWidget(m_pSettingsButton, 0, Qt::AlignHCenter);
    pLayout->addWidget(m_pExitButton, 0, Qt::AlignHCenter);
    pLayout->addWidget(m_pToggleLabelButton, 0, Qt::AlignHCenter);
    pLayout->setContentsMargins(10, 10, 10, 10);
    pLayout->setSpacing(10);
    pLayout->addStretch(); // 按钮靠上

    setLayout(pLayout);
    setObjectName("cmdWidget");
    setFixedWidth(100); // 固定宽度

    // 连接切换按钮的信号
    static bool labelsVisible = false;
    connect(m_pToggleLabelButton, &PushApp::clicked, this, [this]() {
        labelsVisible = !labelsVisible;
        emit toggleLabels(labelsVisible);
    });
}
