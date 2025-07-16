#include "desktopwidget.h"

DesktopWidget::DesktopWidget(QWidget *parent)
    : QWidget(parent)
{
    m_gridLayout = new QGridLayout(this);
    m_gridLayout->setSpacing(10); // 统一左右和上下间距
    m_gridLayout->setContentsMargins(20, 20, 20, 20); // 桌面边距
    m_gridLayout->setRowMinimumHeight(0, 380); // 固定每行高度
    m_gridLayout->setRowMinimumHeight(1, 380);
    setStyleSheet("background-color: #f0f0f0;"); // 桌面背景

    // 添加 6 个图标和说明，2 行 3 列
    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200); // (0,0)
    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200); // (0,1)
    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200); // (0,2)
    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200); // (1,0)
    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200); // (1,1)
    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200); // (1,2)
}

void DesktopWidget::addIcon(const QString &normalPath, const QString &labelText, int pixWidth, int pixHeight)
{
    static int row = 0;
    static int col = 0;

    // 创建图标
    PushApp *icon = new PushApp(normalPath, pixWidth, pixHeight, this);
    // 创建说明文字
    QLabel *label = new QLabel(labelText, this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 14px; color: #333333;");
    label->setFixedHeight(20); // 固定高度
    label->setVisible(false); // 默认隐藏
    m_labels.append(label);

    // 创建小部件包装图标和说明文字
    QWidget *container = new QWidget(this);
    container->setFixedHeight(230); // 固定容器高度：200(图标)+5(间距)+20(文字)
    auto *vLayout = new QVBoxLayout(container);
    vLayout->addWidget(icon, 0, Qt::AlignCenter);
    vLayout->addWidget(label, 0, Qt::AlignCenter);
    vLayout->setSpacing(5);
    vLayout->setContentsMargins(0, 0, 0, 0);

    // 添加到网格
    m_gridLayout->addWidget(container, row, col, Qt::AlignCenter);

    // 更新网格位置（2 行 3 列）
    col++;
    if (col >= 3) {
        col = 0;
        row++;
    }
}

void DesktopWidget::showLabels()
{
    for (QLabel *label : m_labels) {
        label->setVisible(true);
    }
}

void DesktopWidget::hideLabels()
{
    for (QLabel *label : m_labels) {
        label->setVisible(false);
    }
}
