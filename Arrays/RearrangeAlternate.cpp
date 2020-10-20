#include<bits/stdc++.h>
using namespace std;

void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void RearrangeElements(int a[],int size){

	// here we are using pivot element concept from Quick sort Algorithm to move all 
	// Elements to left side of array in o(n) time complexity

	int pivot = 0;
	int i = -1;
	for(int j = 0; j < size; j++){
		if( a[j] < pivot ){
			i++;
			swap(&a[i],&a[j]);
		}
	}

	int start_positive = i+1; // i+1 contains index where positive element starting

	// After This our job is to make their position alternative

	for(int n = 0;( n < start_positive && start_positive < size );start_positive++,n+=2){
		swap(&a[i],&a[start_positive]);
	}

	for(int i = 0; i < size; i++){
		cout<<a[i]<<" ";
	}

}

int main(){

	int n;
	cin>>n;
	int A[n];
	for(int i = 0; i < n; i++){
		cin>>A[i];
	}
	RearrangeElements(A,n);
	return 0;
}