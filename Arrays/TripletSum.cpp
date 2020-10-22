#include<bits/stdc++.h>
using namespace std;

// 1. naive solution  2. two pointer techniuqe 3. hashing method

bool FindTriplet(int arr[],int size,int k){

	for(int i = 0; i < size-2; i++){
		for(int j = i+1; j < size-1; j++){
			for(int m = i+2; m < size; m++){
				int sum = arr[i]+arr[j]+arr[m];
				if( sum == k ){
					return true;
				}
			}
		}
	}
	return false;

	// Time Complexity: o(n^3)
}


bool FindTriplet(int a[],int size,int k){

	//12, 3, 4, 1, 6, 9
	sort(a,a+size);
	 //i  m          //n
	// 1  3  4  6  9  12

	//Time complexity : o(n^2) here, we are using two pointer technique
	for(int i = 0; i < size-2; i++){

		int m = i+1;
		int n = size-1;

		while( m < n ){
			if( a[m]+a[n]+a[i] == k ){
				return true;
			}
			else if( a[m] + a[n] + a[i] < k ){
				m++;
			}
			else{
				n--;
			}
		}
	}
  return false;
}

int main(){

	int size;
	cin>>size;
	int a[size];
	for(int i = 0; i < size; i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	FindTriplet(a,size,k)?cout<<"YES":cout<<"NO";
	return 0;
}