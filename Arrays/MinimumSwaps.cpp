#include <bits/stdc++.h>
using namespace std;

void MinimumSwaps(int a[],int size,int number){

	int count = 0; // count the elements less then or equals to number
	//2 7 9 5 8 7 4
//  5
	for(int i = 0; i < size; i++){
		if( a[i] <= number ){
			count++;
		}
	}
	// 2 1 5 6 3  -- 3

	int min_swaps = INT_MAX;

	int i = 0 , j = count-1;  // 0  2

	while( j < size ){
		int curr_min = 0;
		for(int m = i ; m <= j ; m++){
			if( a[m] > number ){
				curr_min++;
			}
		}
		min_swaps = min(min_swaps,curr_min);
		i++;
		j++;
	}

	cout<<"MinimumSwaps :"<<min_swaps<<endl;

}

int main(){
	int T;
	cin>>T;
	while( T-- ){
		int size;
		cin>>size;
		int a[size];
		for(int i = 0; i < size; i++){
			cin>>a[i];
		}
		int number;
		cin>>number;
		MinimumSwaps(a,size,number);
	}
	return 0;
}