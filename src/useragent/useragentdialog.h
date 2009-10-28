#ifndef USERAGENTDIALOG_H
#define USERAGENTDIALOG_H

#include <QDialog>

namespace Ui {
    class UserAgentDialog;
}

class UserAgentDialog : public QDialog {
    Q_OBJECT
public:
    UserAgentDialog(QWidget *parent = 0);
    ~UserAgentDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::UserAgentDialog *ui;
    void buildUserAgents ();
    int addUserAgent (QString title, QString userAgentString);
    int addSite (QString siteRegex, QString userAgentString);
};

#endif // USERAGENTDIALOG_H
