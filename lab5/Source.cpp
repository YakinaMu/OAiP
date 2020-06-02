#include "Node.h"
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include "Queue.h"
#include <fstream>
#include "List.h"
#include <random>
#include <string>

int rand_int(int a, int b)
{
	return rand() % (b - a + 1) + a;
}

// TASK 1
void create(Node*& root, int value)
{
	if (value == 0) return;
	root = new Node();
	root->value = value;
	create(root->left, value - 1);
	create(root->right, value - 1);
}

void printBT(const std::wstring& prefix, const Node* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::wcout << prefix;
		std::wcout << (isLeft ? L"???" : L"???");
		std::wcout << node->value << std::endl;
		printBT(prefix + (isLeft ? L"? " : L" "), node->left, true);
		printBT(prefix + (isLeft ? L"? " : L" "), node->right, false);
	}
}

// TASK 1
bool copmareStrings(string str1, string str2)
{
	if (str1.size() != str2.size()) return false;
	for (int i = 0; i < str1.size(); i++)
		if (str1[i] != str2[i]) return false;
	return true;
}

int main()
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	wcout << "Task 1" << endl;

	// TASK 1
	int n;
	std::wcin >> n;
	Node* root = nullptr;
	create(root, n);
	system("cls");
	printBT(L"", root, false);

	// TASK 1
	wcout << "\n\nTask 2" << endl;

	// TASK 2
	Queue<int> q1;
	Queue<int> q2;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q2.push(1);
	q2.push(2);
	q2.push(3);
	wcout << (q1 == q2) << endl;

	// TASK 2
	wcout << "\n\nTask 3" << endl;

	// TASK 3
	List<char> list;
	list.push('p');
	list.push('r');
	list.push('i');
	list.push('v');
	list.push('e');
	list.push('t');
	ofstream file("res.txt");
	for (int i = 0; i < list.size; i++)
		file << list[i];

	// TASK 3
	wcout << "\n\nTask 4" << endl;

	// TASK 4
	string text = "Test";
	string text2 = "Text";
	wcout << copmareStrings(text, text2) << endl;

	// TASK 4
	wcout << "\n\nTask 5" << endl;

	// TASK 5
	vector<int> M = { 1, 5, -2, -22, -213, 32, 1 };
	for (int i = 0; i < M.size(); i++)
		if (M[i] < 0) M.erase(M.begin() + i), i--;
	for (int i : M)
		wcout << i << " ";

	// TASK 5

	return 0;

}