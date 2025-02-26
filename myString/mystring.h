#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
class MyString
{
public:
    explicit MyString(const char* str = nullptr);

    MyString(const MyString& another);
    MyString& operator=(const MyString& another);

    virtual ~MyString();
private:
    char* m_data;
    friend std::ostream& operator<<(std::ostream& os, const MyString& myString);
};

#endif // MYSTRING_H
