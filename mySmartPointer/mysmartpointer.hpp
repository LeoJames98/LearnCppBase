#ifndef MYSMARTPOINTER_H
#define MYSMARTPOINTER_H
#include <iostream>
using namespace std;

template<typename T>
class MySmartPointer
{
public:
    explicit MySmartPointer(T* ptr = nullptr);
    MySmartPointer(const MySmartPointer<T>& another);
    virtual ~MySmartPointer();

    MySmartPointer<T>& operator=(const MySmartPointer<T>& another);
    T& operator*();
    T* operator->();

    int GetReferenceCount();

private:
    T* m_ptr;
    int* m_pCount;

    void releaseRefer();
};

template<typename T>
inline MySmartPointer<T>::MySmartPointer(T* ptr)
    :m_ptr(ptr)\
    ,m_pCount(nullptr)
{
    if(nullptr != ptr){
        m_pCount = new int(1);
    }
}

template<typename T>
inline MySmartPointer<T>::MySmartPointer(const MySmartPointer &another)
    :m_ptr(another.m_ptr)\
    ,m_pCount(another.m_pCount)
{
    if(nullptr != m_pCount){
        (*m_pCount)++;
    }
}

template<typename T>
inline MySmartPointer<T> &MySmartPointer<T>::operator=(const MySmartPointer &another)
{
    if (this != &another){
        releaseRefer();
        m_ptr = another.m_ptr;
        m_pCount = another.m_pCount;
        if (nullptr != m_pCount){
            (*m_pCount)++;
        }
    }
    return *this;
}

template<typename T>
inline T& MySmartPointer<T>::operator*()
{
    return *m_ptr;
}

template<typename T>
inline T *MySmartPointer<T>::operator->()
{
    return m_ptr;
}

template<typename T>
inline MySmartPointer<T>::~MySmartPointer()
{
    cout<<"Relase::"<<this<<endl;
    releaseRefer();

}

template<typename T>
inline int MySmartPointer<T>::GetReferenceCount()
{
    if (nullptr == m_pCount){
        return -1;
    }
    return *m_pCount;
}

template<typename T>
inline void MySmartPointer<T>::releaseRefer()
{
    if (nullptr == m_pCount){
        return;
    }
    (*m_pCount)--;
    if (0 == *m_pCount){
        delete m_ptr;
        delete m_pCount;
    }
}


#endif // MYSMARTPOINTER_H
