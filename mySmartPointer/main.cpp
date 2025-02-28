#include <iostream>
#include "mysmartpointer.hpp"
using namespace std;

class MyObject
{
public:
    explicit MyObject()
    {
        cout<<"MyObject Construct"<<endl;
    }
    MyObject(const MyObject& anther)
    {
        cout<<"Copy Const"<<endl;
    }
    void Func()
    {
        cout<<"On Func()"<<endl;
    }
    virtual ~MyObject()
    {
        cout<<"MyObject Destruct::"<<endl;
    }
};

int main()
{
    MySmartPointer<MyObject> sp(new MyObject);
    MySmartPointer<MyObject> sp1(sp);
    MySmartPointer<MyObject> sp2;
    cout<<"MyObject COUNT::"<<sp2.GetReferenceCount()<<endl;
    sp2 = sp1;
    cout<<"MyObject COUNT::"<<sp2.GetReferenceCount()<<"::"<<&sp2<<endl;
    sp2->Func();
    (*sp1).Func();
    MySmartPointer<MyObject> spO(new MyObject);
    cout<<"MyObject Other COUNT::"<<spO.GetReferenceCount()<<"::"<<&spO<<endl;
    MySmartPointer<char> csp(new char[]{"123"});
    cout<<"Char Str COUNT::"<<csp.GetReferenceCount()<<"::"<<&csp<<endl;
    return 0;
}
