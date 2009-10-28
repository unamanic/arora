#include "useragentmenuaction.h"
#include "useragent.h"
#include <QWebPage>
#include <QSettings>

UserAgentMenuAction::UserAgentMenuAction(QWidget* parent) : QAction(parent)
{
    m_UserAgent = new UserAgent();
}

/*UserAgentMenuAction::UserAgentMenuAction(QWidget* parent, UserAgent ua)
{
    UserAgentMenuAction(parent);
    setUserAgent(ua.getName(), ua.getUserAgentString());
}*/

void UserAgentMenuAction::setUserAgent(UserAgent ua)
{
    setUserAgent(ua.getName(), ua.getUserAgentString());
}

void UserAgentMenuAction::setUserAgent(QString name, QString userAgent)
{
    m_UserAgent->setName(name);
    m_UserAgent->setUserAgentString(userAgent);
    setText(name);
}

void UserAgentMenuAction::onAction() {
    QSettings settings(QLatin1String("arora-browser.org"), QLatin1String("Arora"));
    settings.setValue("userAgent",m_UserAgent->getUserAgentString());
    settings.sync();

}
