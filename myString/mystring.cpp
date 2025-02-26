#include "mystring.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const MyString& myString)
{
    os << myString.m_data;
    return os;
}

MyString::MyString(const char *str)
{
    if(nullptr == str){
        m_data = new char[1]{};
    } else {
        auto len = strlen(str);
        m_data = new char[len+1]{};
        strncpy(m_data, str, len);
    }
}

MyString::MyString(const MyString &another)
{
    auto len = strlen(another.m_data);
    m_data = new char[len+1]{};
    strncpy(m_data, another.m_data, len);
}

MyString &MyString::operator=(const MyString &another)
{
    if(this != &another){
        delete[] m_data;
        auto len = strlen(another.m_data);
        m_data = new char[len+1]{};
        strncpy(m_data, another.m_data, len);
    }
    return *this;
}

MyString::~MyString()
{
    delete[] m_data;//使用new[]来分配，应该使用delete[]来释放
}
