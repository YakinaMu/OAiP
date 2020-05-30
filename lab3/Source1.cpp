#include <iostream>
using namespace std;

void ru();

void eng();

void deut();

int main()
{
setlocale(LC_ALL, "ru");

void (*arr[3])() = { ru,eng,deut };
cout << "1.Русский\n";
cout << "2.Английский\n";
cout << "3.Немецкий\n";
cout << " Какую из трех функций выбрать?\n ";

int my_choose;
cin >> my_choose;
my_choose--;
(*arr[my_choose])();

return 0;

}
void ru()
{
cout << "Привет мир\n";
}
void eng()
{
cout << "Hello world \n";
}
void deut()
{
cout << "Hallo welt \n";
}
