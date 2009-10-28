#include "useragentdialog.h"
#include "ui_useragentdialog.h"

UserAgentDialog::UserAgentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserAgentDialog)
{
    ui->setupUi(this);
    buildUserAgents();
}

UserAgentDialog::~UserAgentDialog()
{
    delete ui;
}

void UserAgentDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void UserAgentDialog::buildUserAgents()
{
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << tr("Site") << tr("User Agent"));
    ui->tableWidget->insertRow(0);
    QTableWidgetItem *twi1 = new QTableWidgetItem;
    QTableWidgetItem *twi2 = new QTableWidgetItem;
    ui->tableWidget->setItem(0, 0, twi1);
    ui->tableWidget->setItem(0, 1, twi2);
    ui->tableWidget->item(0, 0)->setText(tr("*.msn.com*"));
    ui->tableWidget->item(0, 1)->setText(tr("IE7 on WindiowsXP"));
}
