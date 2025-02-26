#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{

    MyString s1("111");
    cout << s1 <<endl;
    MyString s2 = s1;
    cout << s2 <<endl;
    s2 = MyString("222");
    cout << s2 <<endl;
    return 0;
}
