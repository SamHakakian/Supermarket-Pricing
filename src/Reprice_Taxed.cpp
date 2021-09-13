#include "Reprice_Taxed.h"
#include <iomanip>

Reprice_Taxed::Reprice_Taxed(QString filename)
{
    loadDoc(filename);
}

Reprice_Taxed::~Reprice_Taxed()
{
    while (taxed.size() > 0)
    {
        Containers::Taxed_Product * t = taxed.last();
        taxed.pop_back();
        delete t;
    }
}

void Reprice_Taxed::loadDoc(QString filename)
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
                Containers::Taxed_Product * t = new Containers::Taxed_Product();
                t->productID = line[0].toUShort();
                t->percentTaxed = line[1].toFloat();
                taxed.push_back(t);
            }
        }
    }
}

float Reprice_Taxed::checkCart(QMap<uint16_t, Containers::ShoppingCartItem> cart)
{
    float retAdditionalCost = 0;
    for (int i = 0; i < taxed.size(); i++)
    {
        if (cart.contains(taxed[i]->productID))
        {
            std::cout << "Adding " << std::fixed << std::setprecision(2) << taxed[i]->percentTaxed << "% Tax to Product: " << cart[taxed[i]->productID].name.toStdString() << "\n";
            retAdditionalCost += cart[taxed[i]->productID].quantity * (1+(taxed[i]->percentTaxed/100));
        }
    }

    return retAdditionalCost;
}

void Reprice_Taxed::print()
{
    for (int i = 0; i < taxed.size(); i++)
    {
        std::cout << "Taxed Items #1: The tax for item " << taxed[i]->productID << " is " << taxed[i]->percentTaxed << "%\n";
    }
}


