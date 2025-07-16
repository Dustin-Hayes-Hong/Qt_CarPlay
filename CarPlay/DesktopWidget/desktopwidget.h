#ifndef DESKTOPWIDGET_H
#define DESKTOPWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "PushApp/pushapp.h"

class DesktopWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DesktopWidget(QWidget *parent = nullptr);
    void addIcon(const QString &normalPath, const QString &labelText, int pixWidth = 150, int pixHeight = 150);

public slots:
    void showLabels();
    void hideLabels();

private:
    QGridLayout *m_gridLayout;
    QList<QLabel*> m_labels; // 存储图标说明文字
};

#endif // DESKTOPWIDGET_H
