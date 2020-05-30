#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
setlocale(0, "ru");

ifstream fin;
fin.open("F1.txt");
if (!fin.is_open()) cout << "Ошибка";
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
if (v.size() < 3)
{
cout << "Недостаточное кол-во строк";
	
return 0;
}
v.pop_back();
v.pop_back();
v.pop_back();
ofstream fout;
fout.open("F1.txt");
if (!fout.is_open()) cout << "Ошибка";
else
{
for (int i = 0; i < v.size(); i++)
fout << v[i] << endl;
fout.close();
}
cout << "Выполнено";
fin.close();
}

return 0;

}
