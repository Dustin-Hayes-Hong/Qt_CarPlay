#ifndef PUSHAPP_H
#define PUSHAPP_H

#include <QPushButton>
#include <QPropertyAnimation>
#include <QString>
#include <QEvent>
#include <QMouseEvent>
#include <QObject>
#include <QWidget>
#include <QDebug>

class PushApp : public QPushButton
{
    Q_OBJECT

public:
    PushApp(const QString &normal_path, int pixwidth = 10, int pixheight = 10, QWidget *parent = nullptr);
    void zoom1();

signals:
    void clicked(); // 添加点击信号

private:
    QString normal_path;
    QPropertyAnimation *animation;

protected:
    bool event(QEvent *event) override;
};

#endif // PUSHAPP_H
