#include <bits/stdc++.h>
using namespace std;

int first(int arr[],int size,int number){

	int low = 0;
	int high = size - 1;
	int res = -1;

	while( low <= high ){

		int mid = ( low + high ) / 2;

		if( arr[mid] > number ){
			high = mid - 1;
		}
		else if( arr[mid] < number ){
			start = mid + 1;
		}
		else{
			res = mid;
			high = mid - 1;
		}
	}

	return res;
}

int last(int arr[],int size,int number){

	int low = 0;
	int high = size - 1;
	int res = -1;

	while( low <= high ){

		int mid = ( low + high ) / 2;

		if( arr[mid] > number ){
			high = mid - 1;
		}
		else if( arr[mid] < number ){
			start = mid + 1;
		}
		else{
			res = mid;
			high = mid + 1;
		}
	}

	return res;
}

// 1 2 2 2 5

void first_recursive(int arr[],int start,int end,int x){

	int mid = (start + end)/2;
	if( start == end ){
		return mid;
	}

	if( arr[mid] > x ){
		first_recursive(arr,start,mid-1,x);
	}
	else if( x > arr[mid] ){
		first_recursive(arr,mid+1,end,x);
	}
	else{
		first_recursive(arr,start,mid-1,x);
	}

}

void last_recursive(int arr[],int start,int end,int x){

	int mid = (start + end)/2;
	if( start == end ){
		return mid;
	}
	if( arr[mid] > x ){
		last_recursive(arr,start,mid-1,x);
	}
	else if( x > arr[mid] ){
		last_recursive(arr,mid+1,end,x);
	}
	else{
		last_recursive(arr,mid+1,end,x);
	}

}

int main(){

	int T;
	cin>>T;

	while( T-- ){
		int n,number;
		cin>>n>>number;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}

		int first_occ = first(arr,n,number);
		int last_occ = last(arr,n,number);

		int first_re = first_recursive(arr,0,size-1,number);

	}

	return 0;
}