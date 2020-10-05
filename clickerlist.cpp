#include "clickerlist.h"
#include "ui_clickerlist.h"

ClickerList::ClickerList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClickerList)
{
    ui->setupUi(this);
    mainLayout = new QVBoxLayout(this);
    QString ClickerName("Virginia Tobacco Pod");
    QString ClickerFile(":/Sprites/Sprites/Virginia_Pod.png");
    VirginiaPod = new AutoClicker(ClickerName, 150, 1, ClickerFile);

    ClickerName = "Classic Tobacco Pod";
    ClickerFile = ":/Sprites/Sprites/Classic_Pod.png";
    ClassicPod = new AutoClicker(ClickerName, 1000, 60, ClickerFile);

    ClickerName = "Creme Pod";
    ClickerFile = ":/Sprites/Sprites/Creme_Pod.png";
    CremePod = new AutoClicker(ClickerName, 15000, 500, ClickerFile);

    ClickerName = "Fruit Pod";
    ClickerFile = ":/Sprites/Sprites/Fruit_Pod.png";
    FruitPod = new AutoClicker(ClickerName, 100000, 2500, ClickerFile);

    ClickerName = "Cucumber Pod";
    ClickerFile = ":/Sprites/Sprites/Cucumber_Pod.png";
    CucumberPod = new AutoClicker(ClickerName, 2000000, 40000, ClickerFile);

    ClickerName = "Menthol Pod";
    ClickerFile = "C:/Users/jacks/OneDrive/Documents/ClickerGame/Sprites/Menthol_Pod.png";
    MentholPod = new AutoClicker(ClickerName, 50000000, 2000000, ClickerFile);

    ClickerName = "Mango Pod";
    ClickerFile = ":/Sprites/Sprites/Mango_Pod.png";
    MangoPod = new AutoClicker(ClickerName, 100000000, 100000000, ClickerFile);

    ClickerName = "Mint Pod";
    ClickerFile = ":/Sprites/Sprites/Mint_Pod.png";
    MintPod = new AutoClicker(ClickerName, 1000000000, 500000000, ClickerFile);


    mainLayout->addWidget(VirginiaPod);
    mainLayout->addWidget(ClassicPod);
    mainLayout->addWidget(CremePod);
    mainLayout->addWidget(FruitPod);
    mainLayout->addWidget(CucumberPod);
    mainLayout->addWidget(MentholPod);
    mainLayout->addWidget(MangoPod);
    mainLayout->addWidget(MintPod);
}

ClickerList::~ClickerList()
{
    delete ui;
}
