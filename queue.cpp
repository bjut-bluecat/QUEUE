// queue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
#define MAX 50
typedef int Elemtype;
class SqQueue
{
public:
	SqQueue();
	~SqQueue();
	bool isEmpty();
	bool isFull();
	int elemNum();
	bool EnQueue(Elemtype x);
	bool DeQueue(Elemtype x);
	void makeEmpty();
	void output();
private:
	Elemtype data[MAX];
	int rear, front;
};

SqQueue::SqQueue()
{
	rear = front = 0;
}

SqQueue::~SqQueue()
{
	makeEmpty();
}
void SqQueue::makeEmpty() 
{
	rear = front = 0;
};
bool SqQueue::isEmpty() 
{
	if (rear == front) 
	{
		return true;
	}
	else 
	{
		return false;
	}
};
bool SqQueue::isFull() 
{
	if ((rear + 1) % MAX == front) //ѭ������ ����һ��λ���ж������� 
	{
		return true;
	}
	else 
	{
		return false;
	}
};
int SqQueue::elemNum() 
{
	return (rear + MAX - front) % MAX;
};
bool SqQueue::EnQueue(Elemtype x)
{
	if (isFull()) 
	{
		return false;
	}
	else 
	{
		data[rear] = x;
		rear = (rear + 1) % MAX;
		return true;
	}
};
bool SqQueue::DeQueue(Elemtype x) 
{
	if (isEmpty()) 
	{
		return false;
	}
	else 
	{
		x = data[front];
		front = (front + 1) % MAX;
		return true;
	}
};
void SqQueue::output() 
{
	int i;
	for ( i = front; i < rear; i++)
	{
		cout << data[i]<< " ";
	}
	cout << endl;
};
int main()
{
	SqQueue *q = new SqQueue();
	
	while (true)
	{
		int ch;
		cout << "1.�������" << endl; 
		cout << "2.���г���" << endl;
		cout << "3.�������" << endl;
		q->output();
		cout << "��������Ҫ�Ĳ���"<< endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			int a;
			cout << "������Ҫ�����Ԫ��"<< endl;
			cin >> a;
			q->EnQueue(a);
			break;
		case 2:
			int x;
			x = 0;
			q->DeQueue(x);
			break;
		case 3:
			q->output();
			_getch();
			break;
		default:
			break;
		}
		system("cls");
	}
	_getch();
    return 0;
}

