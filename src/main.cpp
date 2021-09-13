/**
 * Supermarket Pricing System
 * Launguage: QT6 C++
 * Author: Sam Hakakian
 * eMail: s_hakakian@live.com
 * Created: September 12, 2021
 * Development Time: 5 hours
 **/

#include <QCoreApplication>
#include "SupermarketPricing.h"
#include <QObject>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SupermarketPricing w;

    w.AddProductList("data/products.dat");
    w.AddBOGOSaleList("data/BOGOsale.dat");
    w.AddBundledSaleList("data/bundledSale.dat");
    w.AddTaxedList("data/taxed.dat");
    while (w.Driver() != 0){}
    return 0;

    return a.exec();
}
