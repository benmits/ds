#include <stdio.h>
void swap(int *a, int *b) { int temp = *a;
*a = *b;
*b = temp;
}
void maxHeapify(int arr[], int n, int i) { int largest = i;
int left = 2*i + 1; int right = 2*i + 2;

if (left < n && arr[left] > arr[largest]) largest = left;

if (right < n && arr[right] > arr[largest]) largest = right;
if (largest != i) {
swap(&arr[i], &arr[largest]); maxHeapify(arr, n, largest);
}
}

void minHeapify(int arr[], int n, int i) { int smallest = i;
int left = 2*i + 1; int right = 2*i + 2;

if (left < n && arr[left] < arr[smallest]) smallest = left;
if (right < n && arr[right] < arr[smallest]) smallest = right;




if (smallest != i) {
swap(&arr[i], &arr[smallest]);
 
minHeapify(arr, n, smallest);
}
}

void buildMaxHeap(int arr[], int n) { for (int i = n/2 - 1; i >= 0; i--)
maxHeapify(arr, n, i);
}
void buildMinHeap(int arr[], int n) { for (int i = n/2 - 1; i >= 0; i--)
minHeapify(arr, n, i);
}

void printHeap(int arr[], int n) { for (int i = 0; i < n; i++)
printf("%d ", arr[i]); printf("\n");
}
int main() {
int arr[] = {10, 3, 5, 2, 8};
int n = sizeof(arr)/sizeof(arr[0]);

int maxHeap[5], minHeap[5]; for (int i = 0; i < n; i++) {
maxHeap[i] = arr[i]; minHeap[i] = arr[i];
}
buildMaxHeap(maxHeap, n); buildMinHeap(minHeap, n);

printf("Max Heap: "); printHeap(maxHeap, n);

printf("Min Heap: "); printHeap(minHeap, n);
return 0;
}
