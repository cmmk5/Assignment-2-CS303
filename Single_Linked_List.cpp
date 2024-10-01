#include "Single_Linked_List.h"

// Constructor
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) pop_front();
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) { // Creates function that pushes number to front
    Node* new_node = new Node(item, head);
    head = new_node;
    if (num_items == 0) tail = head;
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) { // Creates function that pushes number to back
    Node* new_node = new Node(item);
    if (tail) tail->next = new_node;
    tail = new_node;
    if (num_items == 0) head = tail;
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() { // Creates function that pops the front numbers
    if (empty()) return;
    Node* old_head = head;
    head = head->next;
    delete old_head;
    --num_items;
    if (num_items == 0) tail = nullptr;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() { // Creates function that pops the back numbers
    if (empty()) return;
    if (num_items == 1) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* current = head;
        while (current->next != tail) current = current->next;
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    --num_items;
}

template <typename Item_Type>

// Checks if the list is empty or not

Item_Type Single_Linked_List<Item_Type>::front() const {
    if (!empty()) return head->data;
    throw runtime_error("List is empty.");
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (!empty()) return tail->data;
    throw runtime_error("List is empty.");
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) { // Inserts numbers
    if (index >= num_items) {
        push_back(item);
    }
    else if (index == 0) {
        push_front(item);
    }
    else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) current = current->next;
        Node* new_node = new Node(item, current->next);
        current->next = new_node;
        ++num_items;
    }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) { // Removes numbers (pop)
    if (index >= num_items) return false;
    if (index == 0) {
        pop_front();
    }
    else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) current = current->next;
        Node* to_delete = current->next;
        current->next = to_delete->next;
        if (to_delete == tail) tail = current;
        delete to_delete;
        --num_items;
    }
    return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const { // Finds numbers
    Node* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == item) return index;
        current = current->next;
        ++index;
    }
    return num_items;
}

// Explicit instantiation
template class Single_Linked_List<int>;
