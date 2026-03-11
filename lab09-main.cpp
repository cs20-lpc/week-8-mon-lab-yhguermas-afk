#include "ArrayStack.hpp"
#include <iostream>
using namespace std;

int main() {

    ArrayStack<int> stackA(10);
    ArrayStack<int> stackB(10);
    ArrayStack<int> stackC(10);

    // push 0–9 into stackA
    for (int i = 0; i < 10; i++) {
        stackA.push(i);
        cout << i << " ";
    }
    cout << endl;

    // stackA full test
    if (stackA.isFull()) {
        cout << "Stack A is full!" << endl;
    }

    cout << "Stack A length: " << stackA.getLength() << endl;

    // copy A into B
    stackB = stackA;

    cout << "Stack B length: " << stackB.getLength() << endl;

    // overflow test
    try {
        stackA.push(10);
    }
    catch (...) {
        cout << "push: error, stack is full, avoiding overflow" << endl;
    }

    // pop 5 elements from B
    for (int i = 0; i < 5; i++) {
        cout << "Popping " << stackB.peek() << " from stack B" << endl;
        stackB.pop();
    }

    cout << "Stack B length: " << stackB.getLength() << endl;

    // clear stackB
    stackB.clear();

    if (stackB.isEmpty()) {
        cout << "Stack B is now empty after being cleared" << endl;
    }

    // underflow test
    try {
        stackB.pop();
    }
    catch (...) {
        cout << "pop: error, stack is empty, avoiding underflow" << endl;
    }

    // peek empty test
    try {
        stackB.peek();
    }
    catch (...) {
        cout << "peek: error, stack is empty, cannot access the top" << endl;
    }

    cout << "Stack A length: " << stackA.getLength() << endl;

    // copy constructor test
    stackC = stackA;

    cout << "Stack C length: " << stackC.getLength() << endl;

    return 0;
}