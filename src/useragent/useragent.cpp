#include "useragent.h"

UserAgent::UserAgent()
{
   // name = new QString("");
   // userAgentString = new QString("");
}

UserAgent::UserAgent(QString name, QString userAgentString)
{
    this->name = name;
    this->userAgentString = userAgentString;
}

QString UserAgent::getName()
{
    return name;
}

void UserAgent::setName(QString name)
{
    this->name = name;
}

QString UserAgent::getUserAgentString()
{
    return userAgentString;
}

void UserAgent::setUserAgentString(QString userAgentString)
{
    this->userAgentString = userAgentString;
}
