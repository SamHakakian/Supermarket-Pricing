#include "Reprice_BOGO.h"

Reprice_BOGO::Reprice_BOGO(QString filename)
{
    loadDoc(filename);
}

Reprice_BOGO::~Reprice_BOGO()
{
    while (sales.size() > 0)
    {
        Containers::BOGO_SALE * s = sales.last();
        sales.pop_back();
        delete s;
    }
}

void Reprice_BOGO::loadDoc(QString filename)
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
                Containers::BOGO_SALE * b = new Containers::BOGO_SALE();
                b->buyProductID = line[0].toUShort();
                b->quantity = line[1].toUShort();
                b->getProductID = line[2].toUShort();
                b->percentOff = line[3].toFloat();

                sales.push_back(b);
            }
        }
    }
}

float Reprice_BOGO::checkCart(QMap<uint16_t, Containers::ShoppingCartItem> cart)
{
    float retAdditionalCost = 0;
    for (int i = 0; i < sales.size(); i++)
    {
        while (cart.contains(sales[i]->buyProductID) &&
                cart[sales[i]->buyProductID].quantity >= sales[i]->quantity &&
                cart.contains(sales[i]->getProductID))
        {
            std::cout << "You saved " << sales[i]->percentOff << "% off of " << cart[sales[i]->getProductID].name.toStdString() << "\n";
            float per = sales[i]->percentOff == 100 ? 0 : sales[i]->percentOff;
            retAdditionalCost -= cart[sales[i]->getProductID].pricePerUnit * (1+(per/100));
            cart[sales[i]->buyProductID].quantity -= sales[i]->quantity;
            cart[sales[i]->getProductID].quantity -= 1;

        }
    }
    return retAdditionalCost;
}

void Reprice_BOGO::print()
{
    for (int i = 0; i < sales.size(); i++)
    {
        std::cout << "Sale #" << i+1 << ": Buy " << sales[i]->quantity << " of " << sales[i]->buyProductID << " and get " << sales[i]->getProductID << " " << sales[i]->percentOff << "% Off.\n";
    }
}

