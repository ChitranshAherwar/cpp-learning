#include<iostream>

class Queue
{
private:
    int* data;
    int front = 0;
    int rear = -1;
    int size{0};
    int capacity{5};

public:
    Queue()
    {
        data = new int[capacity];
    }
    ~Queue()
    {
        delete[] data;
        std::cout << "Queue Deleted.\n";
    }

    void enqueue(int value);
    bool dequeue();
    int frontQ();

    bool isEmpty();
    int getSize();

};

void Queue::enqueue(int value)
{
    if(size == capacity){
        std::cout << "Queue full.\n";
        return;
    }
    rear = (rear + 1) % capacity;
    data[rear] = value;
    size++;

    std::cout << "Enqueue: " << value << '\n';
}

bool Queue::dequeue()
{
    if(size == 0){
        return false;
    }
    std::cout << "Dequeue: " << data[front] << '\n';
    front = (front + 1) % capacity;
    size--;
    return true;
    
}

int Queue::frontQ()
{
    if(size == 0)
    {
        std::cout << "Queue is empty.\n";
        return -1;
    }
    return data[front];
}

bool Queue::isEmpty()
{
    return size == 0;
}

int Queue::getSize()
{
    return size;
}

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);
    
}