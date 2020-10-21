#include<bits/stdc++.h>
using namespace std;
#define MAX 1000


/* 4  factorial   1
                  2
                  6
                  42
                  021


*/

void LargeFactorial(int n){

    int len = 1;
    int carry = 0;
    int A[MAX];
    A[0] = 1;
    for(int i = 1; i <= n; i++){

        for(int j = 0; j <= len; j++){
            A[j] = A[j]*i + carry;
            carry = A[j] / 10;
            A[j] = A[j] % 10;
        }

        while( carry ){
            len++;
            A[len] = carry % 10;
            carry /= 10;
        }
    }

    for(int m = len; m >= 0; m--){
        cout<<A[m];
    }
}

int main(){

	int number;           
	cin>>number;
	LargeFactorial(number);
	return 0;
}