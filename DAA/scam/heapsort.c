#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"heapSort.h"

Heap buildMaxHeap(int* const a,int n){
    //printf("Building Max Heap\n");
    int startIdx = floor(n/2) - 1;
    Heap newHeap;
    newHeap.a = a;
    newHeap.size = n;
    for(int i=startIdx;i>=0;i--){
        //printf("In heapo loopo\n");
        maxHeapify(newHeap,i);
    }
    return newHeap;
}

void maxHeapify(Heap h,int idx){
    //printf("Doing za maxHeapify\n");
    int largest = idx;
    int l = 2*idx + 1;
    int r = 2*idx + 2;
    int temp;

    if(l<h.size && h.a[l] > h.a[idx])
        largest = l;
    else
        largest = idx;

    if(r<h.size && h.a[r] > h.a[largest])
        largest = r;

    if(largest!=idx){
        temp = h.a[idx];
        h.a[idx] = h.a[largest];
        h.a[largest] = temp;

        maxHeapify(h,largest);
    }
}

void heapSort(int* const a,int n){
    Heap h = buildMaxHeap(a,n);
    //printf("Finished creating za heap\n");
    int temp;
    //printf("Running za heapifyo\n");
    for(int i=n-1;i>=0;i--){
        temp = h.a[0];
        h.a[0] = h.a[i];
        h.a[i] = temp;
        h.size--;
        maxHeapify(h,0);
    }
}
