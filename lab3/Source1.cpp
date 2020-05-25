#include <Windows.h>
#include <iostream>
using namespace std;

void division(float);

void pow(float);

void sum(float);


int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	void(*arr[3])(float) = { division,pow,sum };
	cout << "1.������� ���� �����\n";
	cout << "2.���������� � �������\n";
	cout << "3.����� ���� �����\n";
	cout << "  ����� �� ���� ������� �������?\n ";
	int my_choose;
	cin >> my_choose;
	my_choose--;
	(*arr[my_choose])(my_choose);
	return 0;
}
void division(float)
{
	cout << "������� ��� �����: \n";
	int a, b;
	cin >> a >> b;
	cout << "��������� �����: " << a / b;
}
void pow(float)
{
	cout << "������� ��� �����: \n";
	int a, b;
	cin >> a >> b;
	cout << "��������� �����: " << pow(a, b);
}
void sum(float)
{
	cout << "������� ��� �����: \n";
	int a, b;
	cin >> a >> b;
	cout << "��������� �����: " << a + b;
}
