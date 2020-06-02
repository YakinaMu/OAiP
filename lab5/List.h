#pragma once
#include <stdlib.h>

template <class T>
struct List
{
	int size = 0;
	T* arr = nullptr;

	void push(T item);
	void remove(T index);
	
	T operator[](int index)
	{
		return arr[index];
	}
};

template <class T>
void List<T>::push(T item)
{
	size++;
	arr = (T*)realloc(arr, size * sizeof(T));
	arr[size - 1] = item;
}

template <class T>
void List<T>::remove(T index)
{
	if (index < size - 1)
		for (int i = index; i < size - 1; i++)
			arr[i] = arr[i + 1];

	size--;
	arr = (T*)realloc(arr, size * sizeof(T));
}