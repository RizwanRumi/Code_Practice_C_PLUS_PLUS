#include <iostream>  
using namespace std;

// create max heap
void heapify(int a[], int n, int i)
{
    int root = i; // Initialize root 
    int left_child = 2 * i + 1;  
    int right_child = 2 * i + 2; 

    if (left_child < n && a[left_child] > a[root])
        root = left_child;
 
    if (right_child < n && a[right_child] > a[root])
        root = right_child;
    
    if (root != i) {
        // swap between parent and child values
        int temp = a[i];
        a[i] = a[root];
        a[root] = temp;
               
        // Recuresive heapify
        heapify(a, n, root);
    }
}


void heapSort(int a[], int n)
{
    // Rearrange array and build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Extract element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        
        // call max heap on the reduced heap
        heapify(a, i, 0);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = { 15, 19, 10, 7, 17, 16 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Array elements are : " << endl;
    printArray(a, n);

    // Implement Heapify algorithm 
    // (i=n/2 -1) for 0 based indexing
    for (int i = n / 2 - 1; i >= 0; i--) {         
        heapify(a, n, i);
    }
    cout << endl << "Create max heap : " << endl;
    printArray(a, n);

    heapSort(a, n);
    cout << endl << "Sorted array elements are : " << endl ;
    printArray(a, n);
    return 0;
}
