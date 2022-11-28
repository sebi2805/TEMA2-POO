#include <ostream>
#include <string.h>
#include "BToyClass.h"
#include "Gift.h"
#include "ModernToy.h"
#include "InterfaceClass.h"

using namespace std;

int main()
{
    InterfaceMenu menu;
    menu.printMessage();
    menu.start();
    return 0;
}
