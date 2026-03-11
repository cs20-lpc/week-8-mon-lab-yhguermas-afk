#include <string>

template <typename T>
ArrayStack<T>::ArrayStack(int size) {
    if (size <= 0) {
        throw string("Invalid stack size");
    }

    maxSize = size;
    this->length = 0;
    buffer = new T[maxSize];
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& other) {
    copy(other);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& other) {
    if (this != &other) {
        delete[] buffer;
        copy(other);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] buffer;
}

template <typename T>
void ArrayStack<T>::clear() {
    this->length = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& other) {
    maxSize = other.maxSize;
    this->length = other.length;

    buffer = new T[maxSize];

    for (int i = 0; i < this->length; i++) {
        buffer[i] = other.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    if (isEmpty()) {
        throw string("Stack is empty");
    }

    return buffer[this->length - 1];
}

template <typename T>
void ArrayStack<T>::pop() {
    if (isEmpty()) {
        throw string("Stack is empty");
    }

    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    if (isFull()) {
        throw string("Stack is full");
    }

    buffer[this->length] = elem;
    this->length++;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {

    if (this->length <= 1) {
        return;
    }

    if (dir == Stack<T>::RIGHT) {

        T temp = buffer[this->length - 1];

        for (int i = this->length - 1; i > 0; i--) {
            buffer[i] = buffer[i - 1];
        }

        buffer[0] = temp;
    }

    else if (dir == Stack<T>::LEFT) {

        T temp = buffer[0];

        for (int i = 0; i < this->length - 1; i++) {
            buffer[i] = buffer[i + 1];
        }

        buffer[this->length - 1] = temp;
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {

    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}