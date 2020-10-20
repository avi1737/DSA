#include<bits/stdc++.h>
using namespace std;

//check if subarray sum of an array is 0 or not

bool linearSolution(int a[],int size){
	
	// to solve this in linear time we are going to use hashset
	// Time complexity is o(n) and space complexity becomes o(n)
	// idea behind this is if we get comulative sum which is present 
	// in set then we know that there is 0 sum in between and it added 
	// nothing to sum

	unordered_set<int> u_set;
	int sum = 0;
	for(int i = 0; i < size; i++){
		sum += a[i];

		if( sum == 0 || u_set.find(sum) != u_set.end()){
			return true;
		}
		u_set.insert(sum);
	}

	return false;
}

void SubarraySumIs0(int a[],int size){

	// 4 2 -1 3 1  brute force solution runs in o(n*n) time complexity 
	for(int i = 0; i < size; i++){
		int sum = 0;
		for(int j = i; j < size; j++){
			sum = sum + a[j];
			if( sum == 0 ){
				cout<<"Index From :"<<i<<" "<<j<<endl;
			}	
		}
		sum = 0;
	}
}


int main(){

	int n;
		cin>>n;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
	SubarraySumIs0(arr,n);
	if(linearSolution(arr,n)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}