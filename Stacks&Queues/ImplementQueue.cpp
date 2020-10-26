#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000

class Queue{
public:
	int Arr[MAX_SIZE];
	int front = 0;
	int rear = -1;

	void Enqueue(int x){
		rear = rear + 1;
		Arr[rear] = x;
	}

	void Dequeue(){
		int x = Arr[front];
		front = front + 1;
	}

	void Display(){
		for(int i = front; i <= rear; i++){
			cout<<Arr[i]<<" ";
		}
	}

};

int main(){

	Queue q;
	q.Enqueue(45);
	q.Enqueue(56);
	q.Enqueue(22);
	q.Enqueue(56);
	q.Enqueue(1);
	q.Enqueue(67);

	q.Display();

	q.Dequeue();
	q.Dequeue();

	q.Display();

	return 0;
}