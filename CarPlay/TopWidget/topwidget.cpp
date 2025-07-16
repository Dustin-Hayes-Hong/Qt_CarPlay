#include "topwidget.h"

#include <QHBoxLayout>

TopWidget::TopWidget(QWidget *parent)
    : QWidget(parent)
{
    // 设置 QLabel 文本内容
    m_pSysTimeLbl->setText("2025-07-16 19:29:39");
    m_pSysTimeLbl->setObjectName("sysTimeLbl");

    // 设置 QLabel 文本水平和垂直居中
    m_pSysTimeLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // 创建布局并添加 QLabel
    auto *pLayout = new QHBoxLayout;
    pLayout->addWidget(m_pSysTimeLbl);
    pLayout->setAlignment(Qt::AlignCenter); // 使布局内容整体居中
    pLayout->setContentsMargins(0, 0, 0, 0); // 移除布局边距
    pLayout->setSpacing(0); // 移除控件间距

    // 设置布局到 TopWidget
    setLayout(pLayout);
    setObjectName("mainWidget");

    // 设置固定高度，宽度自适应
    setFixedHeight(50);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // 宽度随父窗口扩展
}

