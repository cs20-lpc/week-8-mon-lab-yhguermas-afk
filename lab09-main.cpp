#include "ArrayStack.hpp"
#include <iostream>
using namespace std;

int main() {

    ArrayStack<int> stackA(10);
    ArrayStack<int> stackB(10);
    ArrayStack<int> stackC(10);

    for (int i = 0; i < 10; i++) {
        stackA.push(i);
        cout << i << " ";
    }

    if (stackA.isFull())
        cout << "Stack A is full! ";

    cout << "Stack A length: " << stackA.getLength();

    stackB = stackA;

    cout << "Stack B length: " << stackB.getLength();

    try {
        stackA.push(10);
    }
    catch (...) {
        cout << "push: error, stack is full, avoiding overflow";
    }

    for (int i = 0; i < 5; i++) {
        cout << "Popping " << stackB.peek() << " from stack B";
        stackB.pop();
    }

    cout << "Stack B length: " << stackB.getLength();

    stackB.clear();

    if (stackB.isEmpty())
        cout << "Stack B is now empty after being cleared";

    try {
        stackB.pop();
    }
    catch (...) {
        cout << "pop: error, stack is empty, avoiding underflow";
    }

    try {
        stackB.peek();
    }
    catch (...) {
        cout << "peek: error, stack is empty, cannot access the top";
    }

    cout << "Stack A length: " << stackA.getLength();

    stackC = stackA;

    cout << "Stack C length: " << stackC.getLength();

    return 0;
}