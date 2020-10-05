#include "autoclicker.h"
#include "ui_autoclicker.h"

AutoClicker::AutoClicker(QString name, long price, double pps, QString Imagefile) :
    ui(new Ui::AutoClicker)
{
    ui->setupUi(this);

    //set basic things needed for each instance of autoclicker
    pointspersecond = pps;
    currentprice = price;
    ui->NumPrice->setNum(currentprice);
    ui->NameOfClicker->setText(name);

    ui->PodImage->setPixmap(QPixmap(Imagefile));


    //Set backgrounds for labels and autowrap for text
    ui->NameOfClicker->setStyleSheet("image: url(:/Sprites/Sprites/LabelBackground.png);");
    ui->NameOfClicker->setWordWrap(true);

    //button calls try to buy
    connect(ui->BuyButton, &QPushButton::clicked, this, &AutoClicker::TryToBuy);
}

double AutoClicker::GetPPS()
{
    //basic getter for totalpps
    return totalpps;
}

void AutoClicker::TryToBuy()
{
    //emit this signal, passing in pointer to itself, mainform listens
    //for signal to process a buy
    emit EmitBuy(this, currentprice);
}

void AutoClicker::BuyComplete()
{
        //if a buy occured, we would end up here

        //add 1 to total and update how many we have
        total++;
        ui->NumBoughtLabel->setNum(total);

        //find total pps
        totalpps = total * pointspersecond;

        //setting it in the pps label
        ui->PPSLabel->setNum(totalpps);

        //increment price to make it more expensive for next buy
        //update label that displays it
        currentprice = currentprice * 1.25;
        ui->NumPrice->setNum(currentprice);
}

AutoClicker::~AutoClicker()
{
    delete ui;
}
