#include<bits/stdc++.h>
using namespace std;

void printArray(int a[],int size){
	for(int i = 0; i < size; i++) cout<<a[i]<<" ";
		cout<<endl;
}

void TrappingWaterOp(int arr[],int size){

	int left[size];
	int right[size];

	// 3 0 2 5 4

	// we are going to fill left array with o(n)

	int maxleftsofar = 0;
	for(int i = 0; i < size; i++){

		if( arr[i] > maxleftsofar ){
			maxleftsofar = arr[i];
			left[i] = maxleftsofar;
		}
		else{
			left[i] = maxleftsofar;
		}

	}

	int maxrightsofar = 0;
	for(int i = size-1; i >=0 ; i--){

		if( arr[i] > maxrightsofar ){
			maxrightsofar = arr[i];
			right[i] = maxrightsofar;
		}
		else{
			right[i] = maxrightsofar;
		}
	}

	int water = 0;

	for(int i = 0; i < size; i++){
		water += min(left[i],right[i]) - arr[i];
	}

	cout<<"Water (optimal) :"<<water<<endl;

}

void TrappingWater(int arr[],int size){

	// 3 0 2 0 4
	int left[size];
	int right[size];
	left[0] = arr[0];
	int lmax,rmax;

	for(int i = 1; i < size; i++){
		lmax = arr[i];
		for(int j = i-1; j>= 0; j--){
			lmax = max( lmax,arr[j]);
		}
		left[i] = lmax;
	}

	right[size-1] = arr[size-1];

	for(int i = size-2; i >= 0; i--){
		rmax = arr[i];
		for(int j = i+1; j < size; j++){
			rmax = max(rmax,arr[j]);
		}
		right[i] = rmax;
	}

	printArray(left,size);
	printArray(right,size);

	int water = 0;
	for(int i = 0; i < size; i++){
		water += min(left[i],right[i]) - arr[i];
	}

	cout<<"Water : "<<water<<endl;

	//Time Complexity : o(n^2) + o(n^2) + o(n)
	// space Complexity : o(n) + o(n) = o(2n)
}

int main(){

	int size;
	cin>>size;
	int a[size];
	for(int i = 0; i < size; i++){
		cin>>a[i];
	}

	TrappingWater(a,size);
	TrappingWaterOp(a,size);
	return 0;
}