#include <iostream>

using namespace std;

void FillArr(int* const arr, const int size);
void ShowArr(int* const arr, const int size);
void SortArr(int* const arr, const int size);

int main()

{

	setlocale(LC_ALL, "ru");

	void(*P[3])(int* const, const int) = { FillArr , ShowArr ,SortArr };
	cout << "1.Заполнение массива\n";
	cout << "2.Вывод массива\n";
	cout << "3.Сортировка\n";
	cout << "Что выбрать?\n ";

	int size = 10;
	int* arr = new int[size];
	while (true)
	{
		int number;
		cin >> number;
		if (number <= 0 || number > 3)
		{
			return 0;
		}
		number--;
		(*P[number])(arr, size);
		cout << "Введите 0 для выхода\n";
	}

	return 0;
}

void FillArr(int* const arr, const int size)
{
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 20;
	}
}

void ShowArr(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void SortArr(int* const arr, const int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}

	cout << "Данные после сортировки пузырьком: ";

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

}

