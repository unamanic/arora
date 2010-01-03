#include "useragentmenu.h"
#include "useragentmenuaction.h"
#include <QtGui>
#include <QtXml>
#include <QFile>


UserAgentMenu::UserAgentMenu(QWidget *parent) : QMenu(parent)
{
}

void UserAgentMenu::buildUserAgentMenu()
{
    DefaultUA *defaultUa = new DefaultUA(this);
    defaultUa->setText(tr("Default"));
    connect(defaultUa, SIGNAL(triggered()), defaultUa, SLOT(onAction()));
    addAction(defaultUa);

    addSeparator();

    QDomDocument doc(tr("useragentswitcher"));
    QFile file(tr(":/useragents/useragents.xml"));
    if( !doc.setContent( &file ) )
    {
        file.close();
        //return -2;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomNode n = root.firstChild();
    while( !n.isNull() )
    {
        QDomElement e = n.toElement();
        if( !e.isNull() )
        {
            if( e.tagName() == tr("useragent") )
            {
                UserAgent ua( e.attribute( tr("description"), tr("") ), e.attribute(tr("useragent"),tr("")));
                UserAgentMenuAction* uama = new UserAgentMenuAction(this);
                uama->setUserAgent(ua);
                connect(uama, SIGNAL(triggered()), uama, SLOT(onAction()));
                addAction(uama);
            }
        }
        n = n.nextSibling();
    }
}


DefaultUA::DefaultUA(QWidget *parent) : QAction(parent)
{
}

void DefaultUA::onAction()
{
    QSettings setting;
    setting.remove(QLatin1String("useragent"));
    setting.sync();
}
