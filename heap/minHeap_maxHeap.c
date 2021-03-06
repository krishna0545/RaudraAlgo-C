			// Convert Minheap to Maxheap

#include <stdio.h>
#include <stdlib.h>

void swap(int heap[], int a, int b)
{
	int temp;
	temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void MaxHeapify(int heap[], int index, int size)
{
	int left = 2*index + 1, right=2*index+2, greatest=index;
	greatest = (left<size && heap[left]>heap[index])? left: index; 
	if (right < size && heap[right]>heap[greatest])
		greatest = right;
	if (greatest != index)
	{
		swap(heap, index, greatest);
		MaxHeapify(heap, greatest, size);
	}

}

void convertToMaxHeap(int heap[], int size)
{
	for(int i=(size/2)-1; i >= 0; i--)
		MaxHeapify(heap, i, size);
}

void printMaxHeap(int heap[], int size)
{
	for(int i=0; i<size; i++)
		printf("%d\t", heap[i]);
}

int main()
{
	int *heap, size;
	printf("Enter size of the heap");
	scanf("%d", &size);
	printf("Enter elements to heap\n");
	for(int index = 0; index< size; index++)
		scanf("%d", &heap[index]);
	convertToMaxHeap(heap, size);
	printMaxHeap(heap, size);
	return 0;
}