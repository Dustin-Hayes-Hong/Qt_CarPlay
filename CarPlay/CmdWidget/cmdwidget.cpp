#include "cmdwidget.h"
#include <QVBoxLayout>

CmdWidget::CmdWidget(QWidget *parent)
    : QWidget(parent)
{
    m_pBackButton = new PushApp(":/misc/MusicWidget/images/music.png", 80, 80, this);
    m_pSettingsButton = new PushApp(":/misc/MusicWidget/images/music.png", 80, 80, this);
    m_pExitButton = new PushApp(":/misc/MusicWidget/images/music.png", 80, 80, this);

    auto *pLayout = new QVBoxLayout;
    pLayout->addWidget(m_pBackButton, 0, Qt::AlignHCenter);
    pLayout->addWidget(m_pSettingsButton, 0, Qt::AlignHCenter);
    pLayout->addWidget(m_pExitButton, 0, Qt::AlignHCenter);
    pLayout->setContentsMargins(10, 10, 10, 10);
    pLayout->setSpacing(80);
    pLayout->addStretch();

    setLayout(pLayout);
    setObjectName("cmdWidget");
    setFixedWidth(100);
    setStyleSheet("background: transparent;");
}
