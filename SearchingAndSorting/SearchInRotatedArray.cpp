#include <bits/stdc++.h>
using namespace std;

// 1 2 3 4 5 6 7
//after rotation ..  4 5 6 7 1 2 3

int findIndexOfMinElement(int arr[],int low,int high){

	// array is not rotated

	if( arr[low] < arr[high] )
		return 0;

	// if there is only 1 element in array
	if( high == low )
		return low;

	int mid = (low + high) / 2;

	if( mid < high && arr[mid] > arr[mid+1] )
		return mid+1;

	if( mid > low && arr[mid] < arr[mid-1])
		return mid;

	if (arr[high] > arr[mid])  
    return findIndexOfMinElement(arr, low, mid - 1);  
    return findIndexOfMinElement(arr, mid + 1, high); 


}

int search(int arr[],int low,int high,int x){
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
		}
	}

	return res;

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
		int min_index = findIndexOfMinElement(arr,0,n-1);
		int res1 = search(arr,0,min_index-1,number);
		int res2 = search(arr,min_index,n-1,number);

		if( res1 == -1 && res2 == -1){
			cout<<"Element Not Present"<<endl;
		}
		else if( res1 != -1)
			cout<<"present at index :"<<res1<<endl;
		}
		else if( res2 != -1){
			cout<<"present at index :"<<res2<<endl;
		}
	}

	return 0;
}