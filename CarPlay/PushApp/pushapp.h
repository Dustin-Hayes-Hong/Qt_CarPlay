#ifndef PUSHAPP_H
#define PUSHAPP_H

#include <QPushButton>
#include <QPropertyAnimation>
#include <QString>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>

class PushApp : public QPushButton
{
    Q_OBJECT

public:
    PushApp(const QString &normal_path, int pixwidth = 10, int pixheight = 10, QWidget *parent = nullptr);
    void zoom1();

private:
    QString normal_path;
    QPropertyAnimation *animation;

protected:
    bool event(QEvent *event) override;
};

#endif // PUSHAPP_H
