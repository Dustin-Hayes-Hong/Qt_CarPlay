#ifndef TOPWIDGET_H
#define TOPWIDGET_H

#include <QWidget>
#include <QLabel>

class TopWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TopWidget(QWidget *parent = nullptr);

private:
    QLabel  *m_pSysTimeLbl = new QLabel("2025-07-01 08:00:00", this);
};

#endif // TOPWIDGET_H
