#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    //Setting up the label to display total points
    TotalPoints = new QLabel("0");
    QFont Myfont = TotalPoints->font();
    Myfont.setPointSize(32);
    TotalPoints->setFont(Myfont);
    TotalPoints->setAlignment(Qt::AlignCenter);

    PointsLabel = new QLabel("Total Points");
    Myfont = TotalPoints->font();
    Myfont.setPointSize(32);
    PointsLabel->setFont(Myfont);
    PointsLabel->setAlignment(Qt::AlignCenter);

    //Set up animation of floating juul
    QString MovieName = ":/Sprites/Sprites/Juul_Floating.gif";
    FloatingJuul = new QLabel;
    FloatingAnimation = new QMovie(MovieName);
    FloatingJuul->setMovie(FloatingAnimation);
    FloatingAnimation->start();

    //Setting up manual Clicker
    MyManualClicker = new ManualClicker(this);

    //Setting up our Pod list
    PodList = new ClickerList(this);
    PodScroll = new QScrollArea(this);
    PodScroll->setWidget(PodList);
    PodScroll->setWidgetResizable(true);


    //Initializing Layouts
    labelmanualLayout = new QVBoxLayout;
    mainLayout = new QHBoxLayout(this);

    //Setting up main layout
    mainLayout->addLayout(labelmanualLayout);
    mainLayout->addWidget(PodScroll);

    //Setting up Total points layout


    //Setting up the Label/ManualClicker Layout
    labelmanualLayout->addWidget(PointsLabel);
    labelmanualLayout->addWidget(TotalPoints);
    labelmanualLayout->addStretch();
    labelmanualLayout->addWidget(FloatingJuul);
    labelmanualLayout->addStretch();
    labelmanualLayout->addWidget(MyManualClicker);


    //Creating a timer of 1/10 sec
    ClickerTimer = new QTimer(this);
    ClickerTimer->setInterval(100);
    ClickerTimer->start();

    //Add points to our total from autos every 1/10 sec
    connect(this->ClickerTimer, SIGNAL(timeout()),
            this, SLOT(GetAutoPoints()));

    //If manual clicker is clicked, Add it
    connect(this->MyManualClicker, SIGNAL(EmitClicked()),
            this, SLOT(AddManualClick()));

    //If a manual clicker upgrade happens, do function for it
    connect(this->MyManualClicker, &ManualClicker::UpgradeClicked,
            this, &MainForm::UpgradeManualClick);


    //If our autoclicker emits emitbuy, we call a generic buy handler
    //to try and buy it
    connect(this->PodList->VirginiaPod, SIGNAL(EmitBuy(AutoClicker*, int)),
            this, SLOT(GenericBuyHandler(AutoClicker*, int)));

    connect(this->PodList->ClassicPod, SIGNAL(EmitBuy(AutoClicker*, int)),
            this, SLOT(GenericBuyHandler(AutoClicker*, int)));

    connect(this->PodList->CremePod, SIGNAL(EmitBuy(AutoClicker*, int)),
            this, SLOT(GenericBuyHandler(AutoClicker*, int)));

    connect(this->PodList->FruitPod, SIGNAL(EmitBuy(AutoClicker*, int)),
            this, SLOT(GenericBuyHandler(AutoClicker*, int)));

    connect(this->PodList->CucumberPod, SIGNAL(EmitBuy(AutoClicker*, int)),
            this, SLOT(GenericBuyHandler(AutoClicker*, int)));

    connect(this->PodList->MentholPod, SIGNAL(EmitBuy(AutoClicker*, int)),
            this, SLOT(GenericBuyHandler(AutoClicker*, int)));

    connect(this->PodList->MangoPod, SIGNAL(EmitBuy(AutoClicker*, int)),
            this, SLOT(GenericBuyHandler(AutoClicker*, int)));

    connect(this->PodList->MintPod, SIGNAL(EmitBuy(AutoClicker*, int)),
            this, SLOT(GenericBuyHandler(AutoClicker*, int)));


}

//update the label with mytotalpoints
void MainForm::UpdateLabel()
{
    TotalPoints->setNum(int(MyTotalPoints));
}

void MainForm::AddManualClick()
{
    //Manual Click = +10 points, add it to our total and update label
    MyTotalPoints += MyManualClicker->getClicknumber();
    UpdateLabel();
}

void MainForm::UpgradeManualClick()
{
    //check if we can even buy it
    //send a call to upgrade the amount in our manual clicker
    //and then set it on the labels
    qDebug() << "Upgrade Manual Click Called";
    if(MyManualClicker->getUpgradeCost() <= MyTotalPoints)
    {
        MyTotalPoints -= MyManualClicker->getUpgradeCost();
        UpdateLabel();
        MyManualClicker->UpgradeComplete();
    }
}

void MainForm::GenericBuyHandler(AutoClicker* clicker, int price)
{
    //check if we have enough points to buy, and if so,
    //send a call to the buycomplete function of the clicker passed in
    if(price <= MyTotalPoints)
    {
        MyTotalPoints = MyTotalPoints - price;
        UpdateLabel();
        clicker->BuyComplete();
    }
}

void MainForm::GetAutoPoints()
{
    //Timer updates every 1/10 sec, so add 1/10 of the points
    //per second to our total points and update label
    MyTotalPoints += PodList->MintPod->GetPPS()/10;
    MyTotalPoints += PodList->CucumberPod->GetPPS()/10;
    MyTotalPoints += PodList->MangoPod->GetPPS()/10;
    MyTotalPoints += PodList->ClassicPod->GetPPS()/10;
    MyTotalPoints += PodList->VirginiaPod->GetPPS()/10;
    MyTotalPoints += PodList->CremePod->GetPPS()/10;
    MyTotalPoints += PodList->MentholPod->GetPPS()/10;
    MyTotalPoints += PodList->FruitPod->GetPPS()/10;
    UpdateLabel();
}

MainForm::~MainForm()
{
    delete ui;
}
