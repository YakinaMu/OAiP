#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	setlocale(0, "ru");


	ifstream fin;
	fin.open("F.txt");
	if (!fin.is_open()) cout << "Îøèáêà";
	else
	{
		string str;
		vector<string>v;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			v.push_back(str);
		}
		v.pop_back();
		v.pop_back();
		v.pop_back();

		ofstream fout;
		fout.open("F.txt");
		if (!fout.is_open()) cout << "Îøèáêà";
		else
		{
			for (int i = 0; i < v.size(); i++)
				fout << v[i];
			fout.close();
		}

		fin.close();
	}

	return 0;
}

