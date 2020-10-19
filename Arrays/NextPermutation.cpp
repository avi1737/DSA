#include<bits/stdc++.h>
using namespace std;


void printArray(int a[],int size){  // print array function
	for(int i = 0; i < size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void swap(int* a,int* b){  // swap function for swapping array elements
	int temp = *a;
	*a = *b;
	*b = temp;
}

void nextPermutation(int a[],int size){

    /*
    main function to find next permutation of given permutation

    */

    // here we start traversing from end of array and we find a index where a[i-1] < a[i]
	int index1 = -1;
	for(int i = size-1; i >= 0; i--){
		if( a[i-1] < a[i] ){
			index1 = i-1;
			break;
		}
	}


	// here we start iteration from index+1 as we need to find smallest number which is greater then a[index]

	int data = a[index1];
	int index2 = -1;
	int minimum_max = INT_MAX;
	for(int i = index1+1; i < size; i++){
		if( a[i] > data ){
			minimum_max = min(a[i],minimum_max);
			index2 = max(index2,i);
		}
	}

	//after we got both index we swap array elements 

	swap(&a[index1],&a[index2]);

	// here we sort array after index1 

	sort(a+index1+1,a+size);

	//this is our answer
	printArray(a,size);
}


void permute(int a[],int start,int size){     
	if( start >= size ){
		printArray(a,size);
	}
	else{
		for(int i = start; i < size; i++){
			swap(&a[start],&a[i]);
			permute(a,start+1,size);
			swap(&a[start],&a[i]);
		}
	}
}

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	nextPermutation(arr,n);
	return 0;
}