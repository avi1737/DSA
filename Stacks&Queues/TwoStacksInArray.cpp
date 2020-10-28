#include<bits/stdc++.h>
using namespace std;
#define size 100
 //               top1 top2
//  [ 1 , 2 , 56, 78   5 , 6 , 32 ,34]

class TwoStacks{

public:
	int arr[size];
	int top1 = -1;
	int top2 = size;

	void push1(int x){
		top1 = top1 + 1;
		arr[top1] = x;
		cout<<"Element "<<x<<" is push onto stack 1"<<endl;
	}

	void push2(int x){
		top2 = top2 - 1;
		arr[top2] = x;
		cout<<"Element "<<x<<" is push onto stack 2"<<endl;
	}

	void pop1(){
		top1 = top1-1;
	}

	void pop2(){
		top2 = top2+1;
	}

	bool StackEmpty(){
		if( top2 - top1 > 1){
			return true;
		}
		else{
			return false;
		}
	}

	void showS1(){
		for(int i = top1; i >= 0; i--){
			cout<<arr[i]<<endl;
			cout<<"^"<<endl;
		}
	}
};

int main(){

	TwoStacks ts;
	ts.push1(1);
	ts.push1(2);
	ts.push2(1);
	ts.push2(2);
	ts.showS1();

	return 0;
}