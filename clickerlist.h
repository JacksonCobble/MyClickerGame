#ifndef CLICKERLIST_H
#define CLICKERLIST_H

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QVBoxLayout>
#include <QDir>
#include <QtDebug>
#include "autoclicker.h"


namespace Ui {
class ClickerList;
}

class ClickerList : public QWidget
{
    Q_OBJECT

public:
    explicit ClickerList(QWidget *parent = nullptr);
    ~ClickerList();

    AutoClicker* VirginiaPod;
    AutoClicker* ClassicPod;
    AutoClicker* CremePod;
    AutoClicker* FruitPod;
    AutoClicker* CucumberPod;
    AutoClicker* MentholPod;
    AutoClicker* MangoPod;
    AutoClicker* MintPod;

    QVBoxLayout* mainLayout;
private:
    Ui::ClickerList *ui;
};

#endif // CLICKERLIST_H
