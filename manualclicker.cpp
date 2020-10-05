#include "manualclicker.h"
#include "ui_manualclicker.h"

ManualClicker::ManualClicker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManualClicker)
{
    ui->setupUi(this);

    ui->PointsLabel->setNum(ClickAmount);
    ui->UpgradeLabel->setNum(UpgradeCost);
    //if the button is clicked, call func
    connect(ui->UpgradeButton, &QPushButton::clicked, this, &ManualClicker::UpgradeButtonClicked);
    connect(ui->ManualClickButton, &QPushButton::clicked, this, &ManualClicker::ButtonClicked);
}

void ManualClicker::ButtonClicked()
{
    //send out emitclicked so that mainform can
    //call addmanualclick
    emit EmitClicked();
}

void ManualClicker::UpgradeButtonClicked()
{
    qDebug() << "Upgrade Button is Clicked";
    emit UpgradeClicked();
}

int ManualClicker::getClicknumber() const
{
    return ClickAmount;
}

int ManualClicker::getUpgradeCost() const
{
    return UpgradeCost;
}

void ManualClicker::UpgradeComplete()
{
    UpgradeCost *= 1.75;
    ClickAmount *= 1.9;

    ui->PointsLabel->setNum(ClickAmount);
    ui->UpgradeLabel->setNum(UpgradeCost);
}

ManualClicker::~ManualClicker()
{
    delete ui;
}
