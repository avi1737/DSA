#include <bits/stdc++.h>
using namespace std;

class Pair {
	int min;
	int max;
};

Pair findMinMax(int arr[],int size){

	int max = arr[0];
	int min = arr[0];
    // 23 1 56 32 78
	for(int i = 1; i < size; i++){

		if( arr[i] > max ){
			max = arr[i];
		}
		else if( arr[i] < min ){
			min = arr[i];
		}

	}

	Pair p;
	p.min = min;
	p.max = max;

	return p;
}

int main(){

	int T;
	cin>>T;

	while( T-- ){
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}

		Pair p = findMinMax(arr,n);
		cout<<p.min<<" "<<p.max<<endl;
	}

	return 0;
}