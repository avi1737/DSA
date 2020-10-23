#include <bits/stdc++.h>
using namespace std;

void PalindromicArray(int arr[],int size){

	int mini_operation = 0;

	int i = 0, j = size -1;

	while ( i < j ){

		if( arr[i] == arr[j] ){
			i++;
			j--;
		}

		else if( arr[i] > arr[j] ){
			j--;
			arr[j] += arr[j+1];
			mini_operation++;
		}

		else if( arr[j] > arr[i] ){
			i++;
			arr[i] += arr[i-1];
			mini_operation++;
		}

	}

	cout<<mini_operation<<endl;

	// Time Complexity : o(n)
}

int main() {
	//code
	int T;
	cin>>T;
	while( T-- ){
	    int n;
	    cin>>n;
	    int A[n];
	    for(int i = 0; i < n; i++){
	        cin>>A[i];
	    }
	    PalindromicArray(A,n);
	}
	return 0;
}