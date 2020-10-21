#include<bits/stdc++.h>
using namespace std;

#define InputArray(size) for(int i = 0; i < size; i++) { cin>>A[i];}
#define DisplayArray(A) for(int i = 0; i < size; i++) { cout<<A[i];}

void MaximumProductSubarray(int arr[],int size){
	// brute force solution would be we can find all subarrays and return maximum product of them
	// 2 -4 5 -7 3
	// time complexity would be o(n*n) which is inefficient basically we are generating all possible
	//subarrays and calculating there sum and  check max sum
	int maximumps = INT_MIN;

	for(int i = 0; i < size; i++){
		int local = 1;
		for(int j = i ; j < size; j++){
			local = local * arr[j];
			maximumps = max(local,maximumps);
		}
	}

	cout<<maximumps<<endl;

}

void KadanesAlgorithmToFindIt(int a[],int size){

	/*
	-2 -3 0 -2 -40
	this algorithm works by finding maximum possible product ending at every index
	for this we need to consider 2 things
	1. minproduct 
	2. maxproduct
	3. choose between ( A[i], A[i] * minproduct, A[i] * maxproduct)

	*/
	int minproduct = a[0]; // at index 0 min and max products would be a[o] only
	int maxproduct = a[0];
	int answer = a[0];
	for(int i = 1; i < size; i++){

		maxproduct = max( a[i], max(a[i]*minproduct, a[i]*maxproduct));
		minproduct = min( a[i], min(a[i]*minproduct, a[i]*maxproduct));

		answer = max(maxproduct,minproduct);
	}

	cout<<maxproduct<<endl;
}

int main(){

	int size;
	cin>>size;
	int A[size];
	InputArray(size);
	MaximumProductSubarray(A,size);
	KadanesAlgorithmToFindIt(A,size);
	return 0;
}