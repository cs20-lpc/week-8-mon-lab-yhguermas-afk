#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class Stack {

public:

    enum Direction {
        RIGHT,
        LEFT
    };

protected:

    // number of elements currently in the stack
    int length;

public:

    // constructor
    Stack() {
        length = 0;
    }

    // destructor
    virtual ~Stack() {}

    // remove all elements
    virtual void clear() = 0;

    // return number of elements
    virtual int getLength() const = 0;

    // check if empty
    virtual bool isEmpty() const = 0;

    // return top element
    virtual T peek() const = 0;

    // remove top element
    virtual void pop() = 0;

    // add element
    virtual void push(const T&) = 0;

    // rotate stack
    virtual void rotate(Direction) = 0;
};

#endif