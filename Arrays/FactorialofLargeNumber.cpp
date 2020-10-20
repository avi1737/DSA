#include<bits/stdc++.h>
using namespace std;

int fact(int number){
	if( number == 1 )
		return 1;
	return number*fact(number-1);
}

int main(){

	int number;
	cin>>number;
	int factorial = fact(number);
	cout<<factorial<<endl;
	return 0;
}