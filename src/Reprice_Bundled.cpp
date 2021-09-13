#include "Reprice_Bundled.h"

Reprice_Bundled::Reprice_Bundled(QString filename)
{
    loadDoc(filename);
}

Reprice_Bundled::~Reprice_Bundled()
{
    while (sales.size() > 0)
    {
        Containers::Bundled_SALE * s = sales.last();
        sales.pop_back();
        delete s;
    }
}

void Reprice_Bundled::loadDoc(QString filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QString readIn = file.readLine();
            if (readIn.contains("#") == false)
            {
                QStringList line = readIn.split(DELIMITER);
                Containers::Bundled_SALE * b = new Containers::Bundled_SALE();

                for (int i = 0; i < line.size()-1; i++)
                {
                    b->ids.push_back(line[i].toUShort());
                }
                b->price = line.last().toFloat();
                sales.push_back(b);
            }
        }
    }
}

float Reprice_Bundled::checkCart(QMap<uint16_t, Containers::ShoppingCartItem> cart)
{
    float retAdditionalCost = 0;

    for (int i = 0; i < sales.size(); i++)
    {
        bool applies = false;
        float invCost = 0;
        for (int j = 0; j < sales[i]->ids.size(); j++)
        {
            if(!(cart.contains(sales[i]->ids[j])))
            {
                applies = false;
                break;
            }
            else
            {
                invCost += cart[sales[i]->ids[j]].pricePerUnit;
            }
            applies = true;

        }
        if (applies)
        {
            float sub =  invCost - sales[i]->price;
            std::cout << " Cart contains bundled items. Saving $" << sub << "\n";
            retAdditionalCost -= sub;
        }
    }

    return retAdditionalCost;
}

void Reprice_Bundled::print()
{
    for (int i = 0; i < sales.size(); i++)
    {
        std::cout << "Sale #" << i << ": Get ";
        for (int j = 0; j < sales[i]->ids.size(); j++)
        {
            std::cout << sales[i]->ids[j]  << ", ";
        }
        std::cout << "for $" << sales[i]->price << ". \n";
    }
}

