#include <iostream>
#include "seqStack.h"

template <typename T>
void seqStack<T>::print()
{
    for (int i = 0; i < top_; i++)
    {
        std::cout << p_stak_[i] << std::endl;
    }
}
template <typename T>
int seqStack<T>::expand()
{
    T *ptmp = new T[size_ * 2];
    for (int i = 0; i < top_; i++)
    {
        ptmp[i] = p_stak_[i];
    }
    delete[] p_stak_;
    p_stak_ = ptmp;
    size_ *= 2;
    return size_;
}
template <typename T>
void seqStack<T>::push(const T &elem)
{
    if (isfull())
    {
        int size = expand();
        std::cout << "is full ,size expand to " << size << std::endl;

    }
    p_stak_[top_++] = elem;
}

template <typename T>
void seqStack<T>::pop()
{
    if (isempty())
    {
        std::cout << "seqstakc is empty" << std::endl;

    }
    //delete &p_stak_[];
    top_--;
}
/*
int main()
{

    seqStack<int> s1(2);
    s1.push(20);
    s1.push(40);
    s1.push(302);
    s1.push(302);
    s1.push(3023);
    s1.push(3230);
    s1.print();
    s1.pop();
    s1.print();
    return 0;
}
*/