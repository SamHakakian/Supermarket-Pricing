#include "ItemListParser.h"
#include <iostream>
#include <stdio.h>

ItemListParser::ItemListParser(QString filename) : QFile(filename)
{
    if(this->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!this->atEnd())
        {
            QString readIn = this->readLine();
            if (readIn.contains("#") == false)
            {
                QStringList line = readIn.split(DELIMITER);
                Containers::Product * p = new Containers::Product();
                p->name = line[1];
                p->price = line[2].toFloat();
                p->inventory = line[3].toULongLong();

                products.insert(line[0].toUShort(), p);
            }
        }

        this->close();
    }
}

ItemListParser::~ItemListParser()
{
    // write new list
    writeNewInventory();
}

Containers::Product *ItemListParser::getProducts(uint16_t id)
{
    Containers::Product * ret = nullptr;
    if (products.contains(id) && products[id]->inventory-- > 0)
    {
        ret = products[id];
    }
    return ret;
}

uint16_t ItemListParser::getProductCount()
{
    return products.count();
}

int ItemListParser::getProductQuantity(uint16_t id)
{
    int ret = -1;
    if (products.contains(id))
    {
        ret = products[id]->inventory;
    }
    return ret;
}

void ItemListParser::print()
{
    for (auto k : products.keys())
    {
        std::cout << "Product ID: " << k << "\n";
        std::cout << "Name: " << products[k]->name.toStdString() << "\n";
        std::cout << "Price: " << products[k]->price << "\n";
        std::cout << "Quantity: " << products[k]->inventory << "\n\n";
    }
}

void ItemListParser::writeNewInventory()
{
    if (this->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        this->write(COMMENT_LINE.toStdString().c_str());
        for (uint16_t k : products.keys())
        {
            this->write(QString(QString::number(k) + DELIMITER +
                                products[k]->name + DELIMITER +
                                QString::number(products[k]->price) + DELIMITER +
                                QString::number(products[k]->inventory)+ QString("\n")).toStdString().c_str() );

            delete products[k];
            products[k] = nullptr;
        }

        this->close();
    }
}
