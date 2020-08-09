/**
* Title: Heaps
* Author: Atay Kaylar
* ID: 21703284
* Assignment: 3
* Description: Header file for the heap class
*/


#include <iostream>
using namespace std;

const int MAX_HEAP = 10000;

class Heap{
    public:
        Heap();
        void insert(const int a);
        int maximum();
        int popMaximum();
        bool isEmpty() const;
        int getSize() const;
        void getItems(int * returnItems);
        unsigned long getComparisons() const;



    protected:
        void heapRebuild(int root);
    private:
        friend ostream &operator<<(ostream &out, Heap &heap);
        ostream &printHelper(ostream &out, int * items, int size);
        ostream &print(ostream &out);
        int items[MAX_HEAP];	// array of heap items
	    int size;            
        unsigned long comparisons;


};