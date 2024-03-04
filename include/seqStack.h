#pragma once

template <typename T>
class seqStack
{
public:
    seqStack(int size = 10) : size_(size), top_(0)
    {
        p_stak_ = new T[size_];
    }
    seqStack<T> &operator=(const seqStack<T> &seqstack);

    ~seqStack()
    {
        delete[] p_stak_;
        p_stak_ = nullptr;
    }

    bool isempty() const { return top_ == 0; }
    bool isfull() const { return top_ == size_; }
    void print();
    int expand();
    void push(const T &elem);
    void pop();

private:
    T *p_stak_;
    int top_;
    int size_;
};