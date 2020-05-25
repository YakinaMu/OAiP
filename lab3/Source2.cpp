#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<vector>

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(0, "ru");
	string path = "F.txt";
	ofstream file;
	file.open(path);

	const int n = 7;
	int array[n];
	if (!file.is_open()) cout << "Error\n";
	else
	{
		cout << "Данные записанные в файл: ";
		for (int i = 0; i < n; i++) {
			array[i] = rand() % 10;
			file << array[i] << " ";
			cout << array[i] << " ";
		}
		cout << endl;
	}

	file.close();


	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) cout << "Error\n";
	else
	{
		char ch;
		vector<char> myVector;
		cout << "Данные из файла: ";
		while (fin.get(ch))
			if (ch != ' ')
				myVector.push_back(ch);

		for (int i = 0; i < myVector.size(); i++)
			cout << myVector[i] << " ";

		cout << endl;
		cout << "Данные после сортировки: ";

		for (int i = 0; i < myVector.size(); i++) {
			for (int j = 0; j < myVector.size() - 1; j++) {
				if (myVector[j] > myVector[j + 1]) {
					int t = myVector[j];
					myVector[j] = myVector[j + 1];
					myVector[j + 1] = t;
				}
			}
		}
		for (int i = 0; i < myVector.size(); i++)
			cout << myVector[i] << " ";

		file.open(path, ofstream::app);
		file << endl;
		if (!file.is_open()) cout << "Error\n";
		for (int i = 0; i < myVector.size(); i++) {
			file << myVector[i] << " ";
		}
		file.close();
	}

	fin.close();
	return 0;
}
