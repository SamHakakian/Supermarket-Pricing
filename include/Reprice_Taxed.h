#ifndef REPRICE_TAXED_H
#define REPRICE_TAXED_H

#include "Interface_Reprice.h"
#include <QVector>
#include "ItemListParser.h"


class Reprice_Taxed : public Interface_Reprice
{
public:
    Reprice_Taxed(QString filename);
    virtual ~Reprice_Taxed();

    virtual float checkCart(QMap<uint16_t, Containers::ShoppingCartItem> cart) final;
    virtual void print() final;


private:
    virtual void loadDoc(QString filename) final;
    QVector<Containers::Taxed_Product*> taxed;

};

#endif // REPRICE_TAXED_H
