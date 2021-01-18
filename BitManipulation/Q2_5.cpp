#include<bits/stdc++.h>
using namespace std;

/* devide 2 numbers without using / , *, % */
// time complexity is o(n) 

int devideNumbers(int a,int b){
	// we can use - operator a = 10 b = 3
	int remainder;
	int q = 0;
	while( a > b ){
		a = a - b;
		q++;
	}
	remainder = a;
	cout<<"Quan"<<" "<<q<<" "<<"remainder"<<" "<<remainder<<endl;
}

int countBitsToChangeAtoB(int a, int b){
	// a = 1000  b = 1001  ans = 1
	// a ^ b  ans if bits are diffrenet then we need to increase count
	// we get 0001
	int count = 0;
	int ans = a ^ b;

	while( ans != 0 ){
		ans = ans & (ans-1);
		count++;
	}

	return count;
}

void find2Numbers(int arr[],int size){

	int Xor = arr[0];
	for(int i = 1; i < size; i++){
		Xor ^= arr[i];
	}

	int xor_sum_bit = Xor & ~(Xor-1);

	int number1 = 0;
	int number2 = 0;

	for(int i = 0; i < size; i++){
		if( arr[i] & xor_sum_bit ){
			number1 ^= arr[i];
		}
		else{
			number2 ^= arr[i];
		}
	}

	cout<<"Numbers are "<<number1<<" "<<number2<<endl;
	
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	find2Numbers(arr,n);
	return 0;
}