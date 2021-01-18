#include <bits/stdc++.h>
using namespace std;


// (n*n) time complexity
int subarraySUM0(int arr[],int size){

	// 1 -2 3 4 -1 

	for(int i = 0; i < size; i++){
		int sum = 0;

		for(int j = i; j < size; j++){
			sum += arr[j];
			if( sum == 0 ){
				return 1;
			}
		}

		sum = 0;
	}

	return -1;
}

// efficient solution

int subarraySUM0Linear(int arr[],int size){

	set<int> s;
	int sum = 0;
	for(int i = 0; i < size; i++){

		sum += arr[i];
		s.insert(sum);

		if( s.find(sum) != s.end()){
			return 1;
		}

	}

	return -1;
}


int findPairWithKDiff(int arr[],int n,int k){

	for(int i = 1; i < n; i++){
		if(abs(arr[i]-arr[i-1]) == k){
			return 1;
		}
	}
	return -1;
}

void findMissingAndRepeate(int arr[],int n){
	// n = 5
	// 1 2 3 3 4
	int repeating,missing;

	bool temp[n+1] = false;

	for(int i = 0; i < n; i++){
		if(temp[arr[i]] == false){
			temp[arr[i]] = true;
		}
		else{
			repeating = arr[i];
		}
	}

	for(int i = 1; i < n+1; i++){
		if( temp[i] == false ){
			missing = i;
		}
	}

	cout<<"repeating : "<<repeating<<endl;
	cout<<"missing : "<<missing<<endl;  


}

int main(){

	int N,k;
	cin>>N>>k;
	int arr[N];
	for(int i = 0; i < N; i++){
		cin>>arr[i];
	}

	findMissingAndRepeate(arr,N);
	cout<<findPairWithKDiff(arr,N,k)<<endl;

	return 0;
}