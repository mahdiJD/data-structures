#include <iostream>
class Queue
{
private:
	int rear, front;
	int size;
	int *arr;
public:
	Queue(int s)
	{
	front = rear = -1;
	size = s;
	arr = new int[s];
	}

    bool isEmpty();
    bool isFull();
	void enQueue(int value);
	int deQueue();
};

bool Queue::isEmpty() 
{
	return (front == rear);
}
	
bool Queue::isFull() 
{
	return (front == (rear + 1)%size);
}

void Queue::enQueue(int value)
{
	int temp = (rear + 1)%size;
	if (front == temp)
		std::cout << "\nQueue is Full";
    else 
	{
		rear = temp;
		arr[rear] = value;
	}
}

int Queue::deQueue()
{
	if (front == rear)
		std::cout << "\nQueue is Empty";
    else
    {
    	front = (front + 1)%size;
    	int data = arr[front];
    	return data;
	}
}
