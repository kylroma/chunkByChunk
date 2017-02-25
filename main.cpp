#include <iostream>
#include "uc.h"
using namespace std;

int main(int argc, char *argv[])
{
    UC uc;
    uc.init();
    uc.run();
    cout << "Hello World!" << endl;
    return 0;
}
