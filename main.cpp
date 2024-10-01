#include "Single_Linked_List.h"
#include "Stack.h"
#include <iostream>

using namespace std;

int main() {
    // Single_Linked_List numbers
    Single_Linked_List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    cout << "Front of list: " << list.front() << endl; // Print front of list
    cout << endl;
    cout << "Back of list: " << list.back() << endl; // Print back of list
    cout << endl;
    list.pop_front();
    cout << "Front of list after pop_front: " << list.front() << endl; // Prints front of list after we pop the front numbers
    cout << endl;

    // Stack
    Stack s;
    cout << "Stack is empty: " << (s.empty() ? "Yes" : "No") << endl; // Prints if the stack is empty
    cout << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top of stack: " << s.top() << endl; // Prints the top of stack
    cout << endl;

    s.pop();
    cout << "Top of stack after pop: " << s.top() << endl; // Prints the top of stack after we pop top of stack
    cout << endl;

    cout << "Average of stack elements: " << s.average() << endl; // Prints average of stack units
    cout << endl;

    return 0;
}
