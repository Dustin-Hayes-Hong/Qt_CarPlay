#include "pushapp.h"

PushApp::PushApp(const QString &normal_path, int pixwidth, int pixheight, QWidget *parent)
    : QPushButton(parent), normal_path(normal_path), animation(new QPropertyAnimation(this, "geometry"))
{
    QPixmap pix;
    if (!pix.load(normal_path)) {
        qDebug() << "图片加载失败:" << normal_path;
        return;
    }

    setFixedSize(pixwidth, pixheight);
    setStyleSheet("QPushButton { border: 0px; }");
    setIcon(QIcon(pix));
    setIconSize(QSize(pixwidth, pixheight));
    setFocusPolicy(Qt::NoFocus);
}

void PushApp::zoom1()
{
    animation->setDuration(200);
    animation->setStartValue(QRect(x(), y() + 10, width(), height()));
    animation->setEndValue(QRect(x(), y(), width(), height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

bool PushApp::event(QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        zoom1(); // 触发缩放动画
    } else if (event->type() == QEvent::MouseButtonRelease) {
        emit clicked(); // 发出点击信号
    }
    return QPushButton::event(event);
}
