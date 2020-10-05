#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QLabel>
#include <QMovie>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include "manualclicker.h"
#include "clickerlist.h"

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();
    void UpgradeManualClick();

private:
    Ui::MainForm *ui;

    double MyTotalPoints = 0;
    QLabel* TotalPoints;
    QLabel* PointsLabel;

    QLabel* FloatingJuul;
    QMovie* FloatingAnimation;

    ManualClicker* MyManualClicker;
    ClickerList* PodList;
    QScrollArea* PodScroll;

    QHBoxLayout* mainLayout;
    QVBoxLayout* labelmanualLayout;


    QTimer* ClickerTimer;

    void UpdateLabel();

private slots:
    void AddManualClick();
    void GenericBuyHandler(AutoClicker* clicker, int price);
    void GetAutoPoints();

};

#endif // MAINFORM_H
