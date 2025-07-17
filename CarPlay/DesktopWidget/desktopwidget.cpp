#include "desktopwidget.h"

DesktopWidget::DesktopWidget(QWidget *parent)
    : QWidget(parent)
{
    m_gridLayout = new QGridLayout(this);
    m_gridLayout->setSpacing(10);
    m_gridLayout->setContentsMargins(20, 40, 20, 20);
    m_gridLayout->setRowMinimumHeight(0, 200);
    m_gridLayout->setRowMinimumHeight(1, 20);
    m_gridLayout->setRowMinimumHeight(2, 200);
    m_gridLayout->setRowMinimumHeight(3, 20);
    setStyleSheet("background: transparent;");

    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200);
    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200);
    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200);
    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200);
    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200);
    addIcon(":/misc/MusicWidget/images/music.png", "音乐", 200, 200);
}

void DesktopWidget::addIcon(const QString &normalPath, const QString &labelText, int pixWidth, int pixHeight)
{
    static int iconRow = 0;
    static int labelRow = 1;
    static int col = 0;

    PushApp *icon = new PushApp(normalPath, pixWidth, pixHeight, this);
    icon->setStyleSheet("QPushButton { background: transparent; border: none; }");
    QLabel *label = new QLabel(labelText, this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 14px; color: #FFFFFF; background: transparent; font-weight: bold;");
    label->setFixedSize(pixWidth, 20);
    label->setVisible(true);
    m_labels.append(label);

    m_gridLayout->addWidget(icon, iconRow, col, Qt::AlignCenter);
    m_gridLayout->addWidget(label, labelRow, col, Qt::AlignCenter);

    col++;
    if (col >= 3) {
        col = 0;
        iconRow = 2;
        labelRow = 3;
    }
}

void DesktopWidget::showLabels()
{
    for (QLabel *label : m_labels) {
        if (label) {
            label->setVisible(true);
        }
    }
}

void DesktopWidget::hideLabels()
{
    for (QLabel *label : m_labels) {
        if (label) {
            label->setVisible(false);
        }
    }
}
