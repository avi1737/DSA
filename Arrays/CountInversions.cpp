#include<bits/stdc++.h>
using namespace std;

//count number of inversions in array

void BruteForceMethod(int a[],int size){
	
	/* Time complxity of this algorithm is o(n*n) because there are two for loops 
	   and space complexity would be o(1). we start i from 0 to size-1 and for 
	   each i we check on right side of array if a[i] > a[j] if yes then we increase
	   count
    */
	int count = 0;

	for(int i = 0; i < size-1; i++){

		for(int j = i+1; j < size; j++){

			if( a[i] > a[j] ){
				count++;
			}
		}
	}
	cout<<count<<endl;
}


int Merge(int arr[],int temp[],int low,int mid,int high){

	int count = 0;
	int i = low,j = mid, k = low;

	while( i <= (mid - 1) && j <= high){

		if( arr[i] <= arr[j] ){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			count = count + (mid-i);
		}
	}

	while( i <= (mid - 1) ){
		temp[k++] = arr[i++];
	} 
	while( j < high ){
		temp[k++] = arr[j++];
	}

	return count;

}

int MergeSort(int a[],int temp[],int low,int high){

	int count  = 0;
	if( low < high ){

		int mid = low + (high - low)/2;
		count+=MergeSort(a,temp,low,mid);
		count+=MergeSort(a,temp,mid+1,high);
		count+=Merge(a,temp,low,mid+1,high);

	}

	return count;

}

void MergeSortMethod(int a[], int size){
	

	// uses merge sort algorithm to find count inversions and reduces time complexity to 
	// o(nlogn) and space complexity would become o(n) as we need auxilary array 
	int high = size-1;
	int temp[size];
	int count = MergeSort(a,temp,0,high);
	cout<<count<<endl;
}

int main(){

	int t; // test cases
	cin>>t; 
	while( t-- ){
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}

		BruteForceMethod(arr,n); 
		MergeSortMethod(arr,n);
	}
	return 0;
}
