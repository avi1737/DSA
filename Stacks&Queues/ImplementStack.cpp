#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000

class Stack{
public:
	int top = -1;
	int Arr[MAX_SIZE];

	void push(int x){

		if( isFull() ){
			cout<<"Cant Push , as stack is full"<<endl;
		}
		else{
			top = top + 1;
			Arr[top] = x;
			cout<<"You have Pushed "<<x<<" on to stack"<<endl;
		}

	}

	void pop(){

		if(!isEmpty()){
			int x = Arr[top];
			top = top - 1;
			cout<<"Popped Element is "<<x<<endl;
		}
		else{
			cout<<"Stack is Empty , Cant Pop!"<<endl;
		}

	}

	void peek(){

		cout<<Arr[top]<<endl;
	}

	bool isEmpty(){
		if( top == -1){
			return true;
		}
		else{
			return false;
		}
	}

	bool isFull(){
		if( top == MAX_SIZE-1){
			return true;
		}
		else{
			return false;
		}
	}

};

int main(){

	cout<<"---------------- Welcome To Stack Program ----------------"<<endl;
	cout<<"Push Element : Press 1 :"<<endl;
	cout<<"Pop Element : Press 2 :"<<endl;
	cout<<"Check Peek : Press 3 :"<<endl;
	cout<<"Is Empty : Press 4 :"<<endl;
	cout<<"Is Full : Press 5 :"<<endl;
	cout<<"Exit : Press 6 :"<<endl;
	Stack st;
	while( true ){
		int choice;
		cin>>choice;

		switch( choice ){
			case 1:
			cout<<"Enter The Element : "<<endl;
			int x;
			cin>>x;
			st.push(x);
			break;

			case 2:
			st.pop();
			break;

			case 3:
			st.peek();
			break;

			case 4:
			if(st.isEmpty()){
				cout<<"Stack is Empty !"<<endl;
			}
			else{
				cout<<"Stack is Not Empty"<<endl;
			}
			break;

			case 5:
			if(st.isFull()){
				cout<<"Stack is Full !"<<endl;
			}
			else{
				cout<<"Stack is Not Full"<<endl;
			}
			break;

			case 6:
			exit(0);
		}
	}




	return 0;
}