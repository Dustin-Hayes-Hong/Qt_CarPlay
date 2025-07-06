#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include<QPushButton>
#include<QPropertyAnimation>
#include<QString>
#include<QEvent>
#include<QMouseEvent>

#include <QObject>
#include <QWidget>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    myPushButton(QString normal_path,QString press_path="",int pixwidth=10,int pixheight=10);
    void zoom1();
<<<<<<< HEAD
=======
    void zoom2();
>>>>>>> 1e1d65985c845cd81bb338f14e16d0836969e42a
private:
    QString normal_path;
    QString press_path;
    QPropertyAnimation* animation;
<<<<<<< HEAD

=======
protected:
    void mousePressEvent(QMouseEvent * e);
    void mouseReleaseEvent(QMouseEvent * e);
>>>>>>> 1e1d65985c845cd81bb338f14e16d0836969e42a
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
