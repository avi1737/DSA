#include<bits/stdc++.h>
using namespace std;

void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void SelectionSort(int arr[],int size){
	// 23 56 1 2 67 9

	for(int i = 0; i < size-1; i++){

		int min_index = i;

		for(int j = i+1; j < size; j++){
			if( arr[j] < arr[min_index] ){
				min_index = j;
			}
		}

		swap(&arr[min_index],&arr[i]);

	}
}

int main(){

	int size;
	cin>>size;
	int A[size];
	for(int i = 0; i < size; i++){
		cin>>A[i];
	}
	SelectionSort(A,size);

	for(int i = 0; i < size; i++){
		cout<<A[i]<<"  ";
	}

	return 0;
}