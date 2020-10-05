#ifndef AUTOCLICKER_H
#define AUTOCLICKER_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

namespace Ui {
class AutoClicker;
}

class AutoClicker : public QWidget
{
    Q_OBJECT

public:
    AutoClicker() = default;
    AutoClicker(QString name, long price, double pps, QString ImageFile);
    ~AutoClicker();

    void BuyComplete();
    double GetPPS();

private:
    Ui::AutoClicker *ui;
    long total = 0;
    long currentprice = 0;
    long pointspersecond = 0;
    double totalpps = 0;

    void TryToBuy();

signals:
    void EmitBuy(AutoClicker* clicker, int price);
};
#endif // AUTOCLICKER_H
