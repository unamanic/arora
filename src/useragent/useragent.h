#ifndef USERAGENT_H
#define USERAGENT_H

#include <QString>

class UserAgent
{
public:
    UserAgent();
    UserAgent(QString name, QString userAgentString);

    QString getName();
    void setName(QString name);

    QString getUserAgentString();
    void setUserAgentString(QString userAgentString);


private:
    QString name;
    QString userAgentString;
};

#endif // USERAGENT_H
