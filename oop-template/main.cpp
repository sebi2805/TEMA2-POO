#include <ostream>
#include <string.h>
#include "BToyClass.h"
#include "Gift.h"
#include "ModernToy.h"
#include "InterfaceClass.h"
#include "MyExceptions.h"

using namespace std;

int main()
{
    InterfaceMenu menu;
    menu.printMessage();
    try
    {

        menu.start();
    }
    catch (GiftNotFound ex)
    {
        cout << ex.what();
    }
    catch (ToyNotFound ex)
    {
        cout << ex.what();
    }
    catch (ToyTypeExceptions ex)
    {
        cout << ex.what();
    }
    catch (...)
    {
        cout << "Eroare in InterfaceMenu start";
    }
    return 0;
}
