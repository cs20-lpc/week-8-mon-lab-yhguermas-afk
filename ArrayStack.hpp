#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include "Stack.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayStack : public Stack<T> {

private:
    T* buffer;
    int maxSize;

    void copy(const ArrayStack<T>&);

public:

    ArrayStack(int = 100);

    ArrayStack(const ArrayStack<T>&);

    ArrayStack<T>& operator=(const ArrayStack<T>&);

    virtual ~ArrayStack();

    virtual void clear() override;

    virtual int getLength() const override;

    int getMaxSize() const;

    virtual bool isEmpty() const override;

    bool isFull() const;

    virtual T peek() const override;

    virtual void pop() override;

    virtual void push(const T&) override;

    
    virtual void rotate(typename Stack<T>::Direction) override;

    template <typename U>
    friend ostream& operator<<(ostream&, const ArrayStack<U>&);
};

#include "ArrayStack.tpp"

#endif