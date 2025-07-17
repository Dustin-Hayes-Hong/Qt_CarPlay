#ifndef CMDWIDGET_H
#define CMDWIDGET_H

#include <QWidget>
#include "PushApp/pushapp.h"

class CmdWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CmdWidget(QWidget *parent = nullptr);

private:
    PushApp *m_pBackButton;
    PushApp *m_pSettingsButton;
    PushApp *m_pExitButton;
};

#endif // CMDWIDGET_H
