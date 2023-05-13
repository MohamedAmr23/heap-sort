#include<iostream>
using namespace std;

void max_heapify(int arr[], int size, int node)
{
	int left_child = 2 * node + 1;
	int right_child = 2 * node + 2;
	int max = node;

	if (left_child < size && arr[left_child] > arr[max])
		max = left_child;

	if (right_child < size && arr[right_child] > arr[max])
		max = right_child;

	if (max != node)
	{
		swap(arr[node], arr[max]);
		max_heapify(arr, size, max);

	}
}

void build_heap(int arr[], int s)
{
	int heap_size = s;
	for (int i = s / 2 - 1; i >= 0; i--)
		max_heapify(arr, s, i);

}
void heapStort(int arr[], int s)
{

	build_heap(arr, s);
	for (int i = s - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);
		s--;
		max_heapify(arr, s, 0);

	}
}
void main()
{
	int arr[] = { 20, 80, 50, 30, 90, 10 };
	heapStort(arr, 6);
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl;


	system("pause");

}