#include<bits/stdc++.h>
using namespace std;

int main(){

	stack<int> main_stack;
	stack<int> support_stack;

	cout<<"Push Element press 1"<<endl;
	cout<<"Pop Element press 2"<<endl;
	cout<<"Get Minimum press 3"<<endl;
	cout<<"Exit press 4"<<endl;

	while( true ){
		int ch;
		cin>>ch;
		switch( ch ){
			case 1:
			cout<<"Enter Element: "<<endl;
			int ele;
			cin>>ele;
			main_stack.push(ele);
			if( support_stack.empty()){
				support_stack.push(ele);
			}
			else if( main_stack.top() < support_stack.top()){
				support_stack.push(ele);
			}

			break;

			case 2:
			if( main_stack.top() == support_stack.top()){
				main_stack.pop();
				support_stack.pop();
			}
			else{
				main_stack.pop();
			}
			break;

			case 3:
			cout<<support_stack.top()<<endl;
			break;

			case 4:
			exit(0);
			break;

		}
	}
	return 0;
}