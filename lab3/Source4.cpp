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
	ifstream fin;
	fin.open("F.txt");
	if (!fin.is_open()) cout << "Error\n";
	else
	{
		cout << "Данные взятые из файла: " << endl;
		string str;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			cout << str << endl;
		}
		vector<string> myVector;
		string temp;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				myVector.push_back(temp);
				temp.clear();
			}
			else if (i + 1 == str.length()) {
				temp += str[i];
				myVector.push_back(temp);
			}
			else
				temp += str[i];
		}
		ofstream fout;
		fout.open("F1.txt");
		for (int i = 0; i < myVector.size(); i++)
		{
			string s = myVector[i];
			if (s[0] == 'с' || s[0] == 'С') {
				fout << myVector[i] << endl;
			}
		}
		fout.close();
	}
	fin.close();
	return 0;
}

