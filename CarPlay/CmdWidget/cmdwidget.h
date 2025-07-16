#ifndef CMDWIDGET_H
#define CMDWIDGET_H

#include <QWidget>
#include "PushApp/pushapp.h"

class CmdWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CmdWidget(QWidget *parent = nullptr);

signals:
    void toggleLabels(bool show); // 信号：切换说明文字显示/隐藏

private:
    PushApp *m_pBackButton;
    PushApp *m_pSettingsButton;
    PushApp *m_pExitButton;
    PushApp *m_pToggleLabelButton;
};

#endif // CMDWIDGET_H
