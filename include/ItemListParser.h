#ifndef ITEMLISTPARSER_H
#define ITEMLISTPARSER_H

#include <QFile>
#include <QObject>
#include <QMap>
#include "Containers.h"

class ItemListParser : public QFile
{
public:
    ItemListParser(QString filename);
    ~ItemListParser();

    Containers::Product * getProducts(uint16_t id);
    uint16_t getProductCount();
    int getProductQuantity(uint16_t id);
    void print();

private:
    QMap<uint16_t, Containers::Product*> products;
    void writeNewInventory();

    const QString DELIMITER = ", ";
    const QString COMMENT_LINE = "#ID , NAME, QUANTITY, PRICE\n";
};

#endif // ITEMLISTPARSER_H
