#include <iostream>
#include "ArrayStack.hpp"

using namespace std;

template <typename T>
void testRotate(ArrayStack<T>& stack) {

    cout << "\nRotate RIGHT:\n";
    stack.rotate(Stack<T>::RIGHT);
    cout << stack << endl;

    cout << "\nRotate LEFT:\n";
    stack.rotate(Stack<T>::LEFT);
    cout << stack << endl;
}

int main() {

    try {

        cout << "Testing Integer Stack\n";

        ArrayStack<int> s(5);

        s.push(10);
        s.push(20);
        s.push(30);

        cout << s << endl;

        cout << "Peek: " << s.peek() << endl;

        s.pop();

        cout << "After pop:\n";
        cout << s << endl;

        testRotate(s);


        cout << "\nTesting String Stack\n";

        ArrayStack<string> s2(5);

        s2.push("A");
        s2.push("B");
        s2.push("C");

        cout << s2 << endl;

        testRotate(s2);


        cout << "\nTesting full stack exception\n";

        s.push(40);
        s.push(50);
        s.push(60);

    }

    catch (string err) {
        cout << "Exception: " << err << endl;
    }

};