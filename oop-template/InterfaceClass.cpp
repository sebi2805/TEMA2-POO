#include <iostream>
#include <string.h>
#include "InterfaceClass.h"
void InterfaceMenu::start()
{

    cout << "*******************************************CONFIGURARE CADOU*******************************************" << endl;
    do
    {
        cout << "1.Start configurare cadou\n2.Printare cadou\n3.Adaugare cadou nou\n4.Stergere cadou\n5.Modificare cadou existent\n6.Afisare informatii generale\n7.Printare toate cadourile\n8.Clear\n0.Exit\n";
        cin >> i;
        switch (i)
        {
        case 9:
        {
            const bool x = (allGifts[0] == allGifts[1]);

            cout << x;
        }
        case 0:
            cout << "Iesire interfata";
            break;

        case 1:
        {

            cin >> allGifts[numberOfGifts];
            numberOfGifts++;
            break;
        }

        case 2:
        {
            if (numberOfGifts == 0)
                cout << "Configurati primul cadou\n";
            else
            {
                int j;
                cout << "Ce cadou vrei sa afisezi?\n";
                cin >> j;
                cout << "destinatie" << allGifts[0].getDestination();
                if (j <= numberOfGifts)
                    cout << allGifts[j - 1];
                else
                    cout << "Ne pare rau acest cadou nu exista.\n";
            }
            break;
        }
        case 3:
        {

            cin >> allGifts[numberOfGifts];
            numberOfGifts++;
            break;
        }

        case 4:
        {
            int j;
            cout << "Ce cadou doriti sa stergeti?\n";
            cin >> j;
            if (j < numberOfGifts)
            {

                for (int k = j - 1; j < numberOfGifts; j++)
                {
                    cout << "Pasul" << k << endl;
                    allGifts[k] = allGifts[k + 1];
                    cout << "Stergere completa. \n";
                    numberOfGifts--;
                }
            }
            else if (j == numberOfGifts)
                numberOfGifts--;
            else
                cout << "Ne pare rau acest cadou nu exista.\n";
            break;
        }
        case 5:
        {
            int giftNumber;
            cout << "Ce cadou vreti sa modificati?\n";
            cin >> giftNumber;
            allGifts[giftNumber - 1].updateGift();
            break;
        }
        case 6:
        {
            int j;
            cout << "Pentru ce cadou vreti afisate informatiile generalizat?\n";
            cin >> j;
            allGifts[j - 1].summariseGift();
            break;
        }
        case 7:
        {
            for (int i = 0; i < numberOfGifts; i++)
            {
                cout << allGifts[i];
                cout << endl;
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