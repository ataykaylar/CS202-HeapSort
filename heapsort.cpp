/**
* Title: Heaps
* Author: Atay Kaylar
* ID: 21703284
* Assignment: 3
* Description: Heap sort algorithms and driver function of the project
*/



#include <iostream>
#include <fstream>
#include "heap.h"
using namespace std;



void heapRebuildSorting(int* anArray, int root, int last, unsigned long& comparisons)
{
    int child = 2 * root + 1;
    if (child < last) 
    {
        comparisons++;

        int rightChild = child + 1;

        if ((rightChild < last) && (anArray[rightChild] >anArray[child]))
        {
            comparisons++;
            child = rightChild;
        }

        if (anArray[root] < anArray[child]) {
            comparisons++;
            int temp = anArray[root];
            anArray[root] = anArray[child];
            anArray[child] = temp;

            heapRebuildSorting(anArray, child, last, comparisons);
        }

    }

}


void heapSort(int * anArray, int n, unsigned long &comparisons) {
    for (int last = n-1; last >0; last--) {
        // invariant: anArray[0..last] is a heap, 
        // anArray[last+1..n-1] is sorted and 
        // contains the largest items of anArray.
        int temp = anArray[0];
        anArray[0] = anArray[last];
        anArray[last] = temp;

        // make the heap region a heap again
        heapRebuildSorting(anArray, 0, last, comparisons);
    }
}


void writeFile(ostream& file, int *writeItems, int size, int comparisons) //function, writes the data into a new file
{
    for (int i = 0; i < size;i++)
    {
        file<< writeItems[i]<<endl;
    }
    file <<"\n\n\n"<<endl;
    file <<"Number of comparsions is "<<comparisons<<endl;
}


int main(int argc, char **argv)
{
    Heap h1;
    unsigned long totalComp = 0;
    unsigned long heapComp = 0;
    unsigned long sortComp = 0;
    ifstream file;
    ofstream outputFile;
    file.open(argv[1]);
    outputFile.open(argv[2]);

    int number;
    while (file >> number)
    {
        h1.insert(number);
    }
    int items[h1.getSize()];
    h1.getItems(items);
    heapComp = h1.getComparisons();
    heapSort(items, h1.getSize(), sortComp);
    totalComp = heapComp + sortComp;
    writeFile(outputFile, items, h1.getSize(), totalComp);

    return 0;
}