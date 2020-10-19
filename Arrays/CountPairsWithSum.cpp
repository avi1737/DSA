#include<bits/stdc++.h>
using namespace std;

void countPairs(int a[],int size,int k){

	// brute force approach is simple we use 2 for loops and check for every pair if sum
	// is equals to required sum with time complexity of o(n*n)
	int count = 0;
	for(int i = 0; i < size-1; i++){
		for(int j = i+1; j < size; j++){
			int sum = a[i] + a[j];
			if( sum == k ){
				count++;
			}
		}
	}

	cout<<count<<endl;

}

void countPairsOptimal(int a[],int size,int k){

	//we need to do it in one pass o(n) and space complexity of o(n) for stroring set
	unordered_set<int> uset;
	uset.insert(a[0]);
	int count=0;

	for(int i = 1; i < size; i++){

		int complement = k - a[i];

		if( uset.find(complement) != uset.end() ){
			count++;
		}
		uset.insert(a[i]);
	}

	cout<<count<<endl;
}

int main(){

	int n;
		cin>>n;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int k;
		cin>>k;
	//countPairs(arr,n,k);
	countPairsOptimal(arr,n,k);
	return 0;
}