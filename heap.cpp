/**
* Title: Heaps
* Author: Atay Kaylar
* ID: 21703284
* Assignment: 3
* Description: Implementation of the heap class
*/




#include "heap.h"


Heap::Heap() //constructor which initalizes the size and comparisons to zero
{
    size = 0;
    comparisons = 0;
}

int Heap::getSize() const //returns the size of the array to the caller
{
    return size;
}

void Heap::getItems(int * returnItems) //transfers the array to the caller
{
    for (int i = 0; i< size;i++)
    {
        returnItems[i] = items[i];
    }
}

unsigned long Heap::getComparisons() const
{
    return comparisons;
}


bool Heap::isEmpty() const //returns boolean values according to the size
{
    return (size == 0);
}

void Heap::insert(const int a) //inserts the item to its corresponding location
{
    if (size >= MAX_HEAP)
    {
        cout <<"Heap is full"<<endl;
        return;
    }

    // Place the new item at the end of the heap
    items[size] = a;

    // Trickle new item up to its proper position
    int place = size;
    int parent = (place - 1)/2;
    while ((place > 0) && (items[place] > items[parent]))
    {
        comparisons++;
        int temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++size;
}

int Heap::popMaximum() //returns the maximum value in the array, which is the root, and deletes it
{
    int maximum = 0;
    if (isEmpty())
    {
        cout<<"Heap is empty"<<endl;
        return maximum;
    }
    else
    {
        maximum = items[0];
        items[0] = items[--size];
        heapRebuild(0);

    }
    return maximum;
}

void Heap::heapRebuild(int root) //rebuilds with swapping down the smaller value
{
    int child = 2 * root + 1; 
    if (child < size)
    {
        comparisons++;
        int rightChild = child + 1;

        if ((rightChild < size) && (items[rightChild] >items[child])) //if the right child is bigger, child becomes right child
        {
            comparisons++;
            child = rightChild;
        }

        if (items[root] < items[child]) //if the child is bigger swap 
        {
            comparisons++;
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;


            heapRebuild(child);
        }
    }
}

int Heap::maximum() //returns the maximum value, which is the root
{
    return items[0];

}

ostream &operator<<(ostream &out, Heap &heap) //operator overloading that print the contents of the tree
{
    return heap.print(out);
}

ostream &Heap::print(ostream &out) //helper function that passes root to printHelper
{
    return printHelper(out, items, size);
}

ostream &Heap::printHelper(ostream &out, int *items, int size) //algorithm that prints the data in the heap
{
    for (int i = 0; i<size;i++)
    {
        out <<items[i]<<endl;
    }

    return out;
}

