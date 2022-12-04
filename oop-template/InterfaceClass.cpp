#include <iostream>
#include <string.h>
#include "InterfaceClass.h"
#include "ClassicToy.h"
void InterfaceMenu::printMessage()
{
    std::cout << "Tema numarul 2 \n Virtopeanu Sebastian-Filip\n CTI, GRUPA 264\n";
    std::cout << "In aceasta aplicatie puteti configura cadouri pentru diferite persoane. Un cadou poate contone mai multe jucarii, fiecare jucarie este de un tip anume.";
    std::cout << "\n Tipurile de jucarii sunt:\n ClassicToy- pentru acest tip de jucarie se cunoaste in plus materialul si culoarea";
    std::cout << "\n ElectronicToy - pentru acest tip de jucarie se cunoaste in plus numarul de baterii";
    std::cout << "\n EducativeToy - pentru acest tip de jucarie se cunoaste in plus abilitatea dezvoltata";
    std::cout << "\n ModernToy - un ModernToy este atat un ElectronicToy cat si un EducativeToy, in plus se cunoast si brandul\n";
}
void InterfaceMenu::start()
{

    std::cout << "*******************************************CONFIGURARE CADOU*******************************************" << endl;
    do
    {
        std::cout << "1.Start configurare cadou\n2.Printare cadou\n3.Adaugare cadou nou\n4.Stergere cadou\n5.Modificare cadou existent\n6.Afisare informatii generale\n7.Printare toate cadourile\n8.Clear\n0.Exit\n";
        std::cin >> i;
        switch (i)
        {
        case 9:
        {
            const bool x = (*allGifts[0] == *allGifts[1]);
            std::cout << x;
            break;
        }
        case 0:
            std::cout << "Iesire interfata";
            break;

        case 1:
        {
            if (allGifts.size() == 0)
            {

                allGifts.push_back(make_unique<Gift>());
                std::cin >> *(allGifts[0]);
                // dynamic_cast<ClassicToy *>((*allGifts[0]).getToys()[0].get())->playSound();
                // cout << "Jucarie:" << *dynamic_cast<ClassicToy *>(allGifts[0]->getToys()[0]) << endl;
            }
            else
                std::cout << "Ati configurat deja primul cadou" << endl;
            break;
        }

        case 2:
        {
            if (allGifts.size() == 0)
                std::cout << "Configurati primul cadou\n";
            else
            {
                int j;
                std::cout << "Ce cadou vrei sa afisezi?\n";
                std::cin >> j;

                if (j <= allGifts.size())
                    std::cout << *allGifts[j - 1];
                else
                    std::cout << "Ne pare rau acest cadou nu exista.\n";
            }

            break;
        }
        case 3:
        {
            allGifts.push_back(make_unique<Gift>());
            std::cin >> *(allGifts[allGifts.size() - 1]);
            break;
        }

        case 4:
        {
            int j;
            std::cout << "Ce cadou doriti sa stergeti?\n";
            std::cin >> j;
            if (j <= allGifts.size())
            {
                allGifts.erase(allGifts.begin() + j - 1);
            }

            else
                std::cout << "Ne pare rau acest cadou nu exista.\n";
            break;
        }
        case 5:
        {
            int giftNumber;
            std::cout << "Ce cadou vreti sa modificati?\n";
            std::cin >> giftNumber;
            allGifts[giftNumber - 1]->updateGift();
            break;
        }
        case 6:
        {
            int j;
            std::cout << "Pentru ce cadou vreti afisate informatiile generalizat?\n";
            std::cin >> j;
            allGifts[j - 1]->summariseGift();
            break;
        }
        case 7:
        {
            for (int i = 0; i < allGifts.size(); i++)
            {
                std::cout << *allGifts[i];
                std::cout << endl;
            }
            break;
        }
        case 8:
        {
            system("clear");
            break;
        }
        default:
            break;
        }
    } while (i != 0);
}