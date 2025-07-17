#include "topwidget.h"
#include <QHBoxLayout>

TopWidget::TopWidget(QWidget *parent)
    : QWidget(parent)
{
    m_pSysTimeLbl = new QLabel(this);
    m_pSysTimeLbl->setText("2025-07-16 19:29:39");
    m_pSysTimeLbl->setObjectName("sysTimeLbl");
    m_pSysTimeLbl->setStyleSheet("font-size: 30px; color: #FFFFFF; background: transparent; font-weight: bold;");
    m_pSysTimeLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    auto *pLayout = new QHBoxLayout;
    pLayout->addWidget(m_pSysTimeLbl);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 20, 0, 0);
    pLayout->setSpacing(0);

    setLayout(pLayout);
    setObjectName("mainWidget");
    setFixedHeight(50);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void TopWidget::setSysTimeText(const QString &text)
{
    if (m_pSysTimeLbl) {
        m_pSysTimeLbl->setText(text);
    }
}
