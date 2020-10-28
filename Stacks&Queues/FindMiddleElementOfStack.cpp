#include<bits/stdc++.h>
using namespace std;

int main(){

	stack<int> s;

	cout<<"Press 1 to start<<"<<endl;

	cout<<"press 2 to Find Middle: <<"<<endl;

	cout<<"press 3 to exit <<"<<endl;

	while( true ){
		int choice;
		cin>>choice;

		switch(choice){
			case 1:cout<<"Enter Element<<"<<endl;
			int num;
			cin>>num;
			s.push(num);
			break;

			case 2:
			cout<<"Stack Size"<<endl;
			cout<<s.size()<<endl;
			break;

			case 3:exit(0);
			break;
		}
	}
	return 0;
}