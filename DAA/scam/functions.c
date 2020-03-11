#include "quickSort.h"
#include <stdio.h>
void swap(int *i1,int *i2){
    int i = *i1;
    *i1 = *i2;
    *i2 = i;
}
/**
 * divide(): 
 * Partition (rearrange) the array A[0..n-1]
 * into two (possibly empty) sub-arrays A[0 to q-1] and A[q+1 to n-1]
 * such that each element of A[0 to q-1] is less than or equal to A[q], 
 * which is, in turn, less than or equal to each element of A[q+1 to n-1].
 * Index q should be decided by calling the partition function
 * Return the two new pointers (along with length) by assigning them to a ptrPair structure
 */
void print_array(int *a,int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    putchar('\n');
}
ptrPair divide(int *a, int n){
    int i =getPartitionIndex(a,n);
    // printf("%d, ",i);
    
    ptrPair p;
    p.first = a;
    p.second = a+i+1;
    p.firstLen = i+1;
    p.secondLen = n-i-1;
    return p;
}

/**
 * getPartitionIndex():
 * Choose the first element from the array A[0..n-1] as the pivot element
 * Partition the array using hoare's partitioning scheme, 
 * and return the index of the split
 * HOARE-PARTITION(A, p, r)
    x = A[p]
    i = p - 1
    j = r + 1
    while true
        repeat
            j = j - 1
        until A[j] ≤ x
        repeat
            i = i + 1
        until A[i] ≥ x
        if i < j
            exchange A[i] with A[j]
        else return j
 */
int getPartitionIndex(int *a, int n){
    // print_array(a,n);
    int x = a[0];
    int i = -1;
    int j = n;
    while (1){
        do {
            i++;
        }while(a[i]<x);
        do {
            j-=1;
        }while(a[j]>x);
        
        if (i<j){
            swap(a+i,a+j);
        }
        else {
            return j;
        }
    }
    // int x = a[n-1];
    // int i = 0;
    
    // for (int j=0;j<n-1;j++){
    //     if (a[j]<x){
    //         swap(a+i++,a+j);
    //     }
    // }
    // swap(a+i,a+n-1);
    // return i-1;
}

/**
 * conquer():
 * Call the divide function to divide the array,
 * and then conquer the two sub arrays recursively
 */
void conquer(int *a, int n){
    
    if (n<=1)
        return;
    ptrPair p = divide(a,n);
    // printf("%d %d\n",p.firstLen,p.secondLen);
    conquer(p.first,p.firstLen);
    conquer(p.second,p.secondLen);
}

// Wrapper function to call conquer() for the first time.
void quickSort(int *a, int n){
        conquer(a,n);
}

// Check if an array is sorted.
// Return 1 if the array is sorted, 0 otherwise.
int isSorted(int *a, int n){
    for (int i=0;i<n-1;i++){
        if (a[i]>a[i+1])
            return 0;
    }
    return 1;
}