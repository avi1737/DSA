#include <bits/stdc++.h>
using namespace std;

void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int arr[],int size){
	for(int i = 0; i < size; i++) cout<<arr[i]<<" ";
}

void ThreeWayPartition(int arr[],int size,int range[]){
	// suppose array from 1...100 and range [ 30, 50]

	int low = 0, mid = 0, high = size-1;

	while( mid < high ){

	    if( arr[mid] < range[0] ){
	    	swap(&arr[low++],&arr[mid++]);
	    }
	    else if( arr[mid] >= range[0] && arr[mid] <= range[1] ){
	    	mid++;
	    }	
	    else{
	    	swap(&arr[mid],&arr[high--]);
	    }
	}

	print(arr,size);

	// Navie Solution: would be sorting array in o(nlogn)

	// This is efficient solution with o(n) time complexity using concept of
	// dutch national flag algorithm

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
		int range[2];
		for(int i = 0; i < 2; i++){
			cin>>range[i];
		}
		ThreeWayPartition(a,size,range);
	}
	return 0;
}