#ifndef INTERFACE_SALE_H
#define INTERFACE_SALE_H

#include <QString>
#include <iostream>
#include <stdio.h>
#include "Containers.h"
#include <iomanip>

class Interface_Reprice
{
public:
    Interface_Reprice(){}
    virtual ~Interface_Reprice(){}

    virtual float checkCart(QMap<uint16_t, Containers::ShoppingCartItem>) = 0;
    virtual void print() = 0;

    const QString DELIMITER = ", ";

private:
    virtual void loadDoc(QString filename) = 0;

};

#endif // INTERFACE_SALE_H
