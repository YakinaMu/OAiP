#include<iostream>
#include <string>
#include<vector>
#include <fstream>
#include<Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "ru");

	string path = "F.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "error";
	}
	else
	{
		char ch;
		vector<char>v;
		while (fin.get(ch))
			v.push_back(ch);

		int n = v.size();

		char* mass1 = new char[n];    //строка
		const char mass2[7] = { ' ',',','.','!','?',':',';' }; //исключаемые символы

		for (int i = 0; i < v.size(); i++)
		{
			mass1[i] = v[i];

		}
		for (int i = 0; i < n; i++)
		{
			cout << mass1[i] << " ";
		}
		cout << endl;


		cout << "¬ведите сдвиг " << endl;
		int k;        //сдвиг
		int count = 0;

		cin >> k;
		if (k < 1 || k>10) { cout << "error"; }
		else
		{

			for (int j = 0; j < n; j++)
			{
				count = 0;
				for (int i = 0; i < 7; i++)
				{
					if (mass1[j] != mass2[i])
					{
						count++;
					}
				}
				if (count == 7)
				{
					mass1[j] = mass1[j] + k;
				}
				cout << mass1[j];
			}
		}
		ofstream fout;
		fout.open(path);
		if (!fout.is_open())
		{
			cout << "error";
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				fout << mass1[i];
			}
			fout.close();
		}
		fin.close();
	}
}


