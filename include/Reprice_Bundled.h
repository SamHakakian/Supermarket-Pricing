#ifndef REPRICE_BUNDLED_H
#define REPRICE_BUNDLED_H

#include "Interface_Reprice.h"
#include <QVector>
#include "ItemListParser.h"

class Reprice_Bundled : public Interface_Reprice
{
public:
    Reprice_Bundled(QString filename);
    virtual ~Reprice_Bundled();

    virtual float checkCart(QMap<uint16_t, Containers::ShoppingCartItem> cart) final;
    virtual void print() final;

private:
    virtual void loadDoc(QString filename) final;
    QVector<Containers::Bundled_SALE*> sales;

};

#endif // REPRICE_BUNDLED_H
