//made by shubh
#include <iostream>
#include <complex>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to create a linked list
    void createList() {
        char choice;
        T value;

        do {
            std::cout << "Enter the value: ";
            std::cin >> value;
            insertElement(value);

            std::cout << "Do you want to add another element? (y/n): ";
            std::cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }

    // Function to display the linked list
    void displayList() {
        Node<T>* current = head;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    // Function to insert an element into the linked list
    void insertElement(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to delete an element from the linked list
    void deleteElement(T value) {
        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Element not found in the list." << std::endl;
            return;
        }

        if (previous == nullptr) {
            // Deleting the first node
            head = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        std::cout << "Element deleted successfully." << std::endl;
    }
};
// Main Function 
int main() {
    LinkedList<std::complex<double>> complexList;
    std::cout << "Enter complex number elements for the linked list:\n";
    complexList.createList();
    std::cout << "Complex Number Linked List: ";
    complexList.displayList();

    return 0;
}


//still working 
//still working 
