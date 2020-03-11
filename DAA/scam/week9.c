#include "heapSort.h"

Heap buildMaxHeap(int *const a, int n){      
        Heap h;
        h.a=a;
        h.size=n;
        int i;
        i = h.size/ 2 - 1;
        while (i >= 0){
                maxHeapify(h,i);
                i -= 1;
        }
        return h;
}

void maxHeapify(Heap h, int idx){
        int largest=idx;
        int l=2*idx+1;
        int r=2*idx+2;
        if(l<h.size && h.a[l]>h.a[largest]){
                largest=l;
        }
        if(r<h.size && h.a[r] >h.a[largest]){
                largest=r;
        }
        if(largest!=idx){
                int temp=h.a[idx];
                h.a[idx]=h.a[largest];
                h.a[largest]=temp;
                maxHeapify(h,largest);
        }
}

void heapSort(int *const a, int n){
        Heap h;
        h.a=a;
        h.size=n;
        buildMaxHeap(h.a,h.size);
        int l=h.size-1;
        for(int i=l;i>=0;i--){
                int temp=h.a[0];
                h.a[0]=h.a[i];
                h.a[i]=temp;
                h.size=i;
                maxHeapify(h,0);
         }
}
