#ifndef SUPERMARKETPRICING_H
#define SUPERMARKETPRICING_H

#include "ItemListParser.h"
#include "Interface_Reprice.h"
#include "Reprice_BOGO.h"
#include "Reprice_Bundled.h"
#include "Reprice_Taxed.h"
#include "Containers.h"

class SupermarketPricing : public QObject
{
    Q_OBJECT

public:
    SupermarketPricing();
    ~SupermarketPricing();

    void AddProductList(QString filename);
    void AddTaxedList(QString filename);
    void AddBOGOSaleList(QString filename);
    void AddBundledSaleList(QString filename);

    // return false when ready to exit
    int Driver();


signals:
    void exitProgram();

private:
    void Checkout(QMap<uint16_t, Containers::ShoppingCartItem> cart);

    ItemListParser * itemList;
    Reprice_BOGO * sale_bogo;
    Reprice_Bundled * sale_bundled;
    Reprice_Taxed * sale_taxed;

    void PrintHeader();
};
#endif // SUPERMARKETPRICING_H
