#ifndef USERAGENTMENU_H
#define USERAGENTMENU_H

#include <QMenu>
#include <QList>
#include "useragent.h"
#include "webpage.h"

class UserAgentMenu : public QMenu
{
public:
    UserAgentMenu(QWidget *parent=0);
    void buildUserAgentMenu();
};

#endif // USERAGENTMENU_H
