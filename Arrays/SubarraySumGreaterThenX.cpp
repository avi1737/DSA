#include <bits/stdc++.h>
using namespace std;

void funct(int arr[],int size,int X){

	//1, 4, 45, 6, 0, 19  x= 51
	int min_length = INT_MAX;
	for(int i = 0; i < size; i++){\
		int sum = 0;
		for(int j = i; j < size; j++){
			sum += arr[j];
			if( sum > X ){
				min_length = min(min_length,j-i+1);
			}
		}
	}

	cout<<min_length<<endl;

	// Time complexity : o(n^2)
}

int main(){
	int T;
	cin>>T;
	while( T-- ){
		int size;
		cin>>size;
		int a[size];
		for(int i = 0; i < size; i++){
			cin>>a[i];
		}
		int X;
		cin>>X;
		funct(a,size,X);
	}
	return 0;
}