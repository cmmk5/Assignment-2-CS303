#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Stack {
private:
    vector<int> stack; // Creates private stack

public:                     // Creates public functions
    void push(int value);
    void pop();
    bool empty() const;
    int top() const;
    double average() const;
};
