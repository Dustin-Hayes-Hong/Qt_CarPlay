#ifndef TOPWIDGET_H
#define TOPWIDGET_H

#include <QWidget>
#include <QLabel>

class TopWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TopWidget(QWidget *parent = nullptr);
    void setSysTimeText(const QString &text);

private:
    QLabel *m_pSysTimeLbl;
};

#endif // TOPWIDGET_H
