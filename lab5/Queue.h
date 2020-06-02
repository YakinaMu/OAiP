#pragma once
#include <vector>

using namespace std;

template <class T>
class Queue
{
	vector<T> queue;
public:
	void push(T item);
	T pop();
	bool operator==(Queue<T> queue2)
	{
		if (queue.size() != queue2.queue.size()) return false;
		for (int i = 0; i < queue.size(); i++)
			if (this->pop() != queue2.pop()) return false;

		return true;
	}
};

template<class T>
T Queue<T>::pop()
{
	T element = queue.front();
	queue.erase(queue.begin());
	return element;
}

template<class T>
void Queue<T>::push(T item)
{
	queue.push_back(item);
}