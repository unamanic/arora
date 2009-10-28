#ifndef USERAGENTMENU_H
#define USERAGENTMENU_H

#include <QMenu>
#include <QList>
#include "useragent.h"
#include "webpage.h"
#include <QAction>

class UserAgentMenu : public QMenu
{
public:
    UserAgentMenu(QWidget *parent=0);
    void buildUserAgentMenu();



};

class DefaultUA : public QAction
{
    Q_OBJECT
    public:
        DefaultUA(QWidget *parent=0);

    public slots:
        void onAction();
};

#endif // USERAGENTMENU_H
