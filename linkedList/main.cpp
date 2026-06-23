#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void push_back(int value);

    bool find(int value);
    int size();

    void print_list();
};


LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    std::cout << "Destructor is called.\n";

    Node* current = head;

    while(current != nullptr)
    {
        Node* temp = current;

        std::cout << "Deleting: " << temp->data << '\n';

        current = current->next;
        delete temp;
    }
}


void LinkedList::push_back(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* current = head;

        while(current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
    }
}


bool LinkedList::find(int value)
{
    Node* current = head;

    while(current != nullptr)
    {
        if(value == current->data)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

int LinkedList::size()
{
    Node* current = head;
    int counter{0};

    while(current != nullptr)
    {
        counter++;
        current = current->next;
    }

    return counter;
}


void LinkedList::print_list()
{
    Node* current = head;

    while(current != nullptr)
    {
        std::cout << current->data << '\n';
        current = current->next;
    }
}


int main()
{
    LinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);

    if(list.find(20))
    {
        std::cout << "Found!\n";
    }
    else
    {
        std::cout << "Not Found!\n";
    }

    std::cout << "Size: " << list.size() << '\n';

    list.print_list();

    return 0;
}