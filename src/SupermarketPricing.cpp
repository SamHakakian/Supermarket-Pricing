#include "SupermarketPricing.h"

#include <iostream>
#include <stdio.h>

#include <QtCore/QCoreApplication>

SupermarketPricing::SupermarketPricing()
{

}

SupermarketPricing::~SupermarketPricing()
{
    delete itemList;
    delete sale_bogo;
    delete sale_bundled;
    delete sale_taxed;
}

void SupermarketPricing::AddProductList(QString filename)
{
    itemList = new ItemListParser(filename);
}

void SupermarketPricing::AddTaxedList(QString filename)
{
    sale_taxed = new Reprice_Taxed(filename);
}

void SupermarketPricing::AddBOGOSaleList(QString filename)
{
    sale_bogo = new Reprice_BOGO(filename);
}

void SupermarketPricing::AddBundledSaleList(QString filename)
{
    sale_bundled = new Reprice_Bundled(filename);
}

int SupermarketPricing::Driver()
{
    bool loop = true;
    PrintHeader();
    QMap<uint16_t, Containers::ShoppingCartItem> cart;
    cart.clear();

    while (loop)
    {
        std::cout << "\n";
        std::cout << "Please choose from the options below:\n";
        std::cout << "Option #1: See Product List. \n";
        std::cout << "Option #2: See Shopping Cart. \n";
        std::cout << "Option #3: See BOGO Sales. \n";
        std::cout << "Option #4: See Bundled Sales. \n";
        std::cout << "Option #5: See Taxed Items. \n";
        std::cout << "Option #6: Checkout. \n";
        std::cout << "Option #7: Exit. \n";
        std::cout << "Please enter your selection (1-7) or input Product ID to add item to your cart: ";

        std::string s_in;
        std::cin >> s_in;
        uint16_t input = QString::fromStdString(s_in).toUShort();

        switch (input)
        {
        case 0:
        {
            std::cout << "Invalid input received.\n";
        }
            break;
        case 1:
        {
            itemList->print();
        }
            break;
        case 2:
        {
            std::cout << "There are " << cart.size() << " items in your cart.\n";
            for (auto k : cart.keys())
            {
                cart[k].print();
            }
        }
            break;
        case 3:
        {
            sale_bogo->print();
        }
            break;
        case 4:
        {
            sale_bundled->print();
        }
            break;
        case 5:
        {
            sale_taxed->print();
        }
            break;
        case 6:
        {
            Checkout(cart);
            cart.clear();
            PrintHeader();
        }
            break;
        case 7:
        {
            std::cout << "\n Thank you for shopping with us.\nHave a great day :)\nExiting...\n";
            loop = false;
        }
            break;
        default:
        {
            if (itemList->getProductQuantity(input) > 0)
            {
                if (cart.contains(input))
                {
                    cart[input].quantity++;
                    // do this so it decrements properly
                    itemList->getProducts(input);
                }
                else
                {
                    Containers::ShoppingCartItem c(input, itemList->getProducts(input));
                    cart.insert(input, c);
                }
                std::cout << "There is/are " << cart[input].quantity << " " << cart[input].name.toStdString() << " in the cart.\n";
            }
            else if( itemList->getProductQuantity(input) == 0)
            {
                std::cout << "There is no remaining quantity of this item.\n";
            }
            else
            {
                std::cout << "Invalid input received.\n";
            }
        }
            break;
        }
    }
    return 0;
}

void SupermarketPricing::Checkout(QMap<uint16_t, Containers::ShoppingCartItem> cart)
{
    std::cout << "There are " << cart.size() << " items in your cart.\n";

    float total = 0;

    for (auto k : cart.keys())
    {
        cart[k].print();
        total += (cart[k].pricePerUnit * cart[k].quantity);
    }

    std::cout << "Cart Base Total: $" << total << ".\n";
    std::cout << "Adding Taxes...\n";
    total += sale_taxed->checkCart(cart);

    std::cout << "Checking for Sales...\n";
    total += sale_bogo->checkCart(cart);
    total += sale_bundled->checkCart(cart);

    std::cout << "Grand Total: $" << std::fixed << std::setprecision(2) << total << "\n";
    std::cout << "Please Enter Payment: $";

    while (total >= 0.01 || total <= -0.01)
    {
        std::string s_in;
        std::cin >> s_in;
        float input = QString::fromStdString(s_in).toFloat();

        total -= input;
        if (total > 0)
        {
            std::cout << "Remaining Balance: $" << std::fixed << std::setprecision(2) << total << "\n";
            std::cout << "Please Enter Payment: $";
        }
        else if (total < 0)
        {
            std::cout << "You have overpaid. Please accept your change, totalling $" << std::fixed << std::setprecision(2) << total*(-1) << "\n";
            total = 0;
        }
    }
}


void SupermarketPricing::PrintHeader()
{
    std::cout << "\n";
    std::cout << "************************************\n";
    std::cout << "*** Welcome to Sam's Supermarket ***\n";
    std::cout << "************************************\n";
}

