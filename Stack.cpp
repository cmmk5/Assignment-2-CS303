#include "Stack.h"

void Stack::push(int value) { // Function that push back values in stack
    stack.push_back(value);
}

void Stack::pop() {             // Function that pop numbers in stack
    if (!empty()) stack.pop_back();
    else cerr << "Stack is empty." << endl;
}

bool Stack::empty() const {     // Function that returns the stack empty
    return stack.empty();
}

int Stack::top() const {            // Function that pushes number to top if stack isn't empty
    if (!empty()) return stack.back();
    else {
        cerr << "Stack is empty." << endl;
        return -1;
    }
}

double Stack::average() const {     // Function that gets average of elements
    if (!empty()) {
        double sum = accumulate(stack.begin(), stack.end(), 0);
        return sum / stack.size();
    }
    return 0.0;
}
