#ifndef REPRICE_BOGO_H
#define REPRICE_BOGO_H

#include "Interface_Reprice.h"
#include <QVector>
#include "ItemListParser.h"

class Reprice_BOGO : public Interface_Reprice
{
public:
    Reprice_BOGO(QString filename);
    virtual ~Reprice_BOGO();

    virtual float checkCart(QMap<uint16_t, Containers::ShoppingCartItem> cart) final;
    virtual void print() final;

private:
    virtual void loadDoc(QString filename) final;
    QVector<Containers::BOGO_SALE*> sales;

};

#endif // REPRICE_BOGO_H
