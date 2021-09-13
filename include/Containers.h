#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <QString>
#include <QMap>
#include <QVector>
#include <stdio.h>
#include <iostream>

namespace Containers {

struct Product
{
    QString name;
    float price;
    uint64_t inventory;
};

struct BOGO_SALE
{
    uint16_t buyProductID;
    uint16_t quantity;
    uint16_t getProductID;
    float percentOff;
};

struct Bundled_SALE
{
    QVector<uint16_t> ids;
    float price;
};

struct Taxed_Product
{
    uint16_t productID;
    float percentTaxed;
};

struct ShoppingCartItem
{
    ShoppingCartItem()
    {
        productID = 0;
        name = "";
        quantity = 0;
        pricePerUnit = 0;
    }

    ShoppingCartItem(uint16_t id, Product* p)
    {
        productID = id;
        name = p->name;
        pricePerUnit = p->price;
        quantity = 1;
    }

    uint16_t productID;
    QString name;
    uint16_t quantity;
    float pricePerUnit;

    void print()
    {
        std::cout << "Product ID: " << productID << "\n"
                    << "Product: " << name.toStdString() << "\n"
                    << "Quantity: " << quantity << "\n"
                    << " Price Per Unit: " << pricePerUnit << "\n";
    }
};

}


#endif // CONTAINERS_H
