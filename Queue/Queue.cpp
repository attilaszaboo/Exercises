// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// Queue As an array
struct Queue
{
	static const int kQueueSize = 3;
	int queue[kQueueSize];
	int mFront;
	int mCount;

	Queue() : mFront(0), mCount(0) { ; };
	bool Enqueue(int e);
	bool Dequeue(int& e);
	int Count();
	bool IsFull() { return (kQueueSize == mCount);}
	bool IsEmpty() { return (0 == mCount); }
	void Print();

};

bool Queue::Enqueue(int e)
{
	if (IsFull()) return false;
	// Base case
	queue[(mFront + mCount)%kQueueSize] = e;
	mCount++;
	return true;
}

bool Queue::Dequeue(int& e)
{
	if (IsEmpty()) return false;
	e = queue[mFront];
	mFront = (mFront + 1) % kQueueSize;
	mCount--;
	return true;
}

void Queue::Print()
{
	if (IsEmpty())
		cout << "Queue is empty" << endl;
	for (int i = mFront; i < (mFront+mCount); i++)
		cout << queue[i%kQueueSize] << " ";
	cout << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Queue q;
	q.Enqueue(10);
	q.Enqueue(12);
	q.Enqueue(16);
	q.Enqueue(20);	// won't add 20
	q.Print();

	int e = 0;
	q.Dequeue(e);
	cout << e << endl;
	q.Dequeue(e);
	cout << e << endl;
	q.Dequeue(e);
	cout << e << endl;
	q.Print();

	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Print(); // 1 2 3
	q.Dequeue(e); // dequeue 1
	q.Enqueue(4); 
	q.Dequeue(e); // dequeue 2
	q.Dequeue(e); // dequeue 3
	q.Print(); // 4 
	q.Enqueue(100);
	q.Print(); // 4 100
	return 0;
}

