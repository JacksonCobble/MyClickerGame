#ifndef MANUALCLICKER_H
#define MANUALCLICKER_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class ManualClicker;
}

class ManualClicker : public QWidget
{
    Q_OBJECT

public:
    explicit ManualClicker(QWidget *parent = nullptr);
    ~ManualClicker();

    int getClicknumber() const;
    int getUpgradeCost() const;
    void UpgradeComplete();

private:
    Ui::ManualClicker *ui;
    void ButtonClicked();
    void UpgradeButtonClicked();

    int UpgradeCost = 1000;
    int ClickAmount = 10;

signals:
    void EmitClicked();
    void UpgradeClicked();


};

#endif // MANUALCLICKER_H
