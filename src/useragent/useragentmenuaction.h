#ifndef USERAGENTMENUACTION_H
#define USERAGENTMENUACTION_H

#include <QMenu>
#include "useragent.h"
#include "webpage.h"

class UserAgentMenuAction : public QAction
{
    Q_OBJECT

public:
    UserAgentMenuAction(QWidget* parent);
    ///UserAgentMenuAction(QWidget* parent, UserAgent ua);

    void setUserAgent(UserAgent ua);
    void setUserAgent(QString name, QString userAgent);

public slots:
    void onAction();

private:
    UserAgent *m_UserAgent;
};

#endif // USERAGENTMENUACTION_H
