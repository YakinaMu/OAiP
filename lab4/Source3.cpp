#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include<string>

using namespace std;

int main()
{
	setlocale(0, "ru");
	srand(time(NULL));
	int k;

	cout << "Введите количество матриц ";
	cin >> k;

	int n;
	cout << "Введите размер матриц ";
	cin >> n;

	for (int i = 0; i < k; i++)
	{
		ofstream file1;
		file1.open("Laba1.txt", ofstream::app);
		if (!file1.is_open()) cout << "Error";
		else
		{
			int** arr = new int*[n];

			for (int j = 0; j < n; j++)
			{
				arr[j] = new int[n];
			}
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					arr[j][k] = rand() % 20 + 1;
				}
			}

			int sum = 0;

			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					if (k == j || k + j == n - 1)
					{
						sum += arr[j][k];
						if (n % 2 != 0)
							sum - arr[(n - 1) / 2][(n - 1) / 2];
					}
				}
			}

			if (sum % 2 == 0)
			{
				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						file1 << arr[j][k] << "\t";
					}

					file1 << endl;

				}

				file1 << endl;
				file1.close();
			}

			else
			{
				ofstream file2;
				file2.open("Laba2.txt", ofstream::app);

				if (!file2.is_open()) cout << "Error";

				else
				{
					for (int j = 0; j < n; j++)
					{
						for (int k = 0; k < n; k++)
						{
							file2 << arr[j][k] << "\t";
						}
						file2 << endl;
					}
					file2 << endl;
					file2.close();
				}

				//транспонирование матрицы

				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						int** tmp = new int*[n];

						for (j = 0; j < n; ++j)

							tmp[j] = new int[n];

						for (j = 0; j < n; ++j)

							for (k = 0; k < n; ++k)

								tmp[j][k] = arr[k][j];

						for (int g = 0; g < n; g++)
						{
							for (int h = 0; h < n; h++)
							{
								file1 << tmp[g][h] << "\t";
							}
							file1 << endl;
						}

						file1 << endl;

					}
				}
				file1 << endl;
				file1.close();
			}

			cout << endl;

			for (int j = 0; j < n; j++)

				delete[] arr[j];

			delete[]arr;

		}
	}

	ifstream file1;
	file1.open("Laba1.txt");
	if (!file1.is_open()) cout << "Error";

	else
	{
		cout << "Содержимое первого файла " << endl;
		string s;
		while (!file1.eof())
		{
			string s = "";

			getline(file1, s);

			cout << s << endl;
		}
		file1.close();
	}

	cout << "\n\n";
	ifstream file2;
	file2.open("Laba2.txt");

	if (!file2.is_open()) cout << "Error";

	else
	{
		cout << "Содержимое второго файла " << endl;
		string s;
		while (!file2.eof())
		{
			string s = "";

			getline(file2, s);

			cout << s << endl;
		}
		file2.close();
	}

	return 0;
}
