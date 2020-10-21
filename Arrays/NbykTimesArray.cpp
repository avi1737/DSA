
//Given an array of size n and a number k, fin all elements that appear more than " n/k " times.

#include<bits/stdc++.h>
using namespace std;

#define InputArray(X,size) for(int i = 0; i < size; i++) { cin>>X[i];}
#define DisplayArray(A) for(int i = 0; i < size; i++) { cout<<A[i];}


void NavieSolution(int a[],int size,int k){

	// 2 2 3 3 3 4 4 4 9 10  
	// Time complexity : 0(nlogn) + o(n)
	sort(a,a+size);
	int count = 1;
	int times = size/k;
	for(int i = 0; i < size; i++){
		if( a[i+1] == a[i] ){
			count++;
		}
		else{
			count = 1;
		}
		if( count > times ){
			cout<<a[i]<<" ";
			int m = a[i];
			while( a[i] <= m ){
				i++;
			}
		}
	}
}


int main(){

	int size;
	cin>>size;
	int A[size];
	for(int i = 0; i < size; i++){
		cin>>A[i];
	}
	int k;
	cin>>k;
	NavieSolution(A,size,k);

	return 0;
}