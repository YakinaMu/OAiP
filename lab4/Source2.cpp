#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

class Obiturient

{
public:

	string surname;
	string name;
	string patronymic;
	string floor;
	string nationality;
	string date_of_birth;
	string home_address;
	string exam_grades;
	string passing_score;
};

ostream& operator << (ostream& os, const Obiturient& obiturient);
istream& operator >> (istream& is, Obiturient& obiturient);

void output_owner(Obiturient ob);

int main()

{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "ru");

	Obiturient* ob = new Obiturient[9];

	int number;

	while (1)

	{

		system("cls");

		Obiturient obiturient;

		int choose;

		cout << "1.�������� �����.\n";
		cout << "2.���������� �������� � ����� �����.\n";
		cout << "3.����� ����������� ����� �� �����.\n";
		cout << "4.�������� �������� �� �����(� �������� �������).\n";
		cout << "5.�������� �������� �� �����(� �������� ������).\n";
		cout << "6.�������������� ��������� � ����� �� ���������� ��������, ����������� ��������������.\n";
		cout << "�������� ��������\n ";
		cin >> choose;

		system("cls");

		switch (choose)

		{
		case 1:
		{
			ofstream file;
			file.open("File.txt");

			if (!file.is_open())

			{
				cout << "Error";
			}

			else

				cout << "���� ������\n";

			file.close();

			Sleep(1000);

			break;

		}
		case 2:
		{
			ofstream file;

			file.open("File.txt", ofstream::app);

			if (!file.is_open())

			{

				cout << "Error";

			}

			else

			{

				cout << "������� ���������� ������������: ";
				cin >> number;

				if (number <= 0)

					break;

				else

				{
					ob = new Obiturient[number];

					for (int i = 0; i < number; i++)

					{

						system("cls");

						cout << "������� �������: "; cin >> ob[i].surname;
						cout << "������� ���: "; cin >> ob[i].name;
						cout << "������� ��������: "; cin >> ob[i].patronymic;
						cout << "������� ���: "; cin >> ob[i].floor;
						cout << "������� ��������������: "; cin >> ob[i].nationality;
						cout << "������� ���� ��������: "; cin >> ob[i].date_of_birth;
						cout << "������� �����: "; cin >> ob[i].home_address;
						cout << "������� ������ �� ������� "; cin >> ob[i].exam_grades;
						cout << "������� ��������� ���� "; cin >> ob[i].passing_score;
						file << ob[i];
					}

					cout << "��� ������ �������!";

					Sleep(1000);

					system("cls");

				}

			}

			file.close();

			break;

		}

		case 3:

		{

			ifstream file;

			file.open("File.txt");

			if (!file.is_open())

			{
				cout << "Error";
			}

			else

			{
				int i = 0;

				while (!file.eof())

				{
					file >> ob[i];

					if (file.eof())

					{

						break;

					}

					cout << ob[i] << endl;

					i++;

				}
				system("pause");
			}

			file.close();

			break;

		}
		case 4:
		{

			vector< Obiturient>Myvector;
			ifstream file;

			file.open("File.txt");

			if (!file.is_open())

			{
				cout << "Error";
			}

			else

			{
				while (!file.eof())

				{
					file >> obiturient;

					if (file.eof())

					{

						break;

					}

					Myvector.push_back(obiturient);

				}

				int number;
				cout << "��� ����� ������� ������� ��������� ";
				cin >> number;

				if (number == 0 || number > Myvector.size())

				{

					cout << "��� ��������� � ����� �������";

					Sleep(1000);

					break;

				}

				else

				{

					number--;

					Myvector.erase(Myvector.begin() + number);

					ofstream file;

					file.open("File.txt");

					if (!file.is_open())

					{
						cout << "Error";
					}

					else

					{

						for (int i = 0; i < Myvector.size(); i++)

							file << Myvector[i];

					}

					system("cls");

					cout << "���������";

					Sleep(1000);

				}

			}

			file.close();

			break;

		}

		case 5:

		{

			ifstream file;

			file.open("File.txt");

			if (!file.is_open())

			{

				cout << "Error";

			}

			else

			{
				int i = 0;

				vector<Obiturient>myVector;

				while (!file.eof())

				{

					file >> ob[i];

					if (file.eof())

					{
						break;
					}

					cout << ob[i] << endl;
					myVector.push_back(ob[i]);
					i++;

				}

				cout << "� ����� �������� ��������� �������? ";
				string last_n;
				cin >> last_n;

				for (int i = 0; i < myVector.size(); i++)
				{
					if (ob[i].surname == last_n)

					{
						myVector.erase(myVector.begin() + i);
						break;
					}
				}

				ofstream file;
				file.open("File.txt");
				if (!file.is_open())
				{
					cout << "Error";
				}

				else

				{
					for (int i = 0; i < myVector.size(); i++)

						file << myVector[i];
				}

				system("cls");
				cout << "���������";
				Sleep(1000);
			}
			file.close();
			break;
		}
		case 6:
		{

			ifstream file;
			file.open("File.txt");
			if (!file.is_open())

			{
				cout << "Error";
			}

			else
			{
				int j = 0;
				vector<Obiturient>myVector;
				while (!file.eof())
				{
					file >> ob[j];
					if (file.eof())
					{
						break;
					}
					cout << ob[j] << endl;
					myVector.push_back(ob[j]);
					j++;
				}

				Obiturient ob_copy;
				for (int i = 0; i < j - 1; i++)

				{
					if (ob[i].surname[0] > ob[i + 1].surname[0])
					{
						ob_copy = ob[i];

						ob[i] = ob[i + 1];

						ob[i + 1] = ob_copy;
					}
					else
					{
						cout << "Error sorting!"; continue;
					}
				}
				ofstream file;
				file.open("File.txt");
				if (!file.is_open())
				{
					cout << "Error";
				}
				else
				{
					for (int i = 0; i < j; i++)

						file << ob[i];
				}
				system("cls");
				cout << "���������";
				Sleep(1000);
			}
			break;
		}
		case 7:
			return 0;
			break;
		}

	}

	system("pause");

	return 0;

}

void output_owner(Obiturient ob)

{

	cout << "�������: " << ob.surname << endl;
	cout << "���: " << ob.name << endl;
	cout << "��������: " << ob.patronymic << endl;
	cout << "���: " << ob.floor << endl;
	cout << "��������������: " << ob.nationality << endl;
	cout << "���� ��������: " << ob.date_of_birth << endl;
	cout << "�����: " << ob.home_address << endl;
	cout << "���� �� �������: " << ob.exam_grades << endl;
	cout << "��������� ����: " << ob.passing_score << endl;

}

ostream& operator << (ostream& os, const Obiturient& obiturient)
{
	os << obiturient.surname << " " << obiturient.name << " " << obiturient.patronymic << " " << obiturient.floor << " " << obiturient.nationality

		<< " " << obiturient.date_of_birth << " " << obiturient.home_address << " " << obiturient.exam_grades << " " << obiturient.passing_score << "\n";

	return os;
}

istream& operator >> (istream& is, Obiturient& obiturient)
{
	is >> obiturient.surname >> obiturient.name >> obiturient.patronymic >> obiturient.floor >> obiturient.nationality

		>> obiturient.date_of_birth >> obiturient.home_address >> obiturient.exam_grades >> obiturient.passing_score;

	return is;
}

