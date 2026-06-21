#include <iostream>

class dynamicArray
{
private:
    int* data;
    int size{0};
    int capacity{5};

public:
    dynamicArray()
    {
        data = new int[capacity];
    }

    void push_back(int val)
    {
        if(size == capacity){
            newArray();
        }
            data[size] = val;
             size++;
            
    }

    void newArray()
    {
        int newCapacity = capacity*2;
        int* bigger = new int[newCapacity];

        for(int i=0; i<size; i++){
            bigger[i] = data[i];
        }

        delete[] data;
        data = bigger;
        capacity = newCapacity;
    }

    ~dynamicArray()
    {
        delete[] data;
        std::cout << "Destroyed\n";
    }

    void printVal()
    {
        for(int i=0; i<size; i++){

            std::cout << "Data: " << data[i] << '\n';
        }

        std::cout << '\n' << "Size: " << size << '\n';
        std::cout << "Capacity: " << capacity << '\n';
    }
};

int main()
{
    dynamicArray arr;

    for(int i = 1; i <= 100; i++)
    {
        arr.push_back(i);
    }

    arr.printVal();


    return 0;
}

