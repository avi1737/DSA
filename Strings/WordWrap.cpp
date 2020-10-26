#include<bits/stdc++.h>
using namespace std;

void WordWrap(int arr[],int len,int width){

	int dp[len][len];
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++){
			dp[i][j] = 0;
		}
	}

	// filled 2-d array with 0s
	/* 0 1 2 3    0-1-2-3 represents words and we check like 0--0 0--1 0--2
    0  
    1
    2
    3

    */

    for(int i = 0; i < len; i++){
    	int sum = 0;
    	for(int j = i; j < len; j++){
    		sum += arr[j];
    		int no_of_words = j-i+1;
    		int spaces = no_of_words - 1;

    		if( sum + spaces <= width ){
    			dp[i][j] = (width - (sum+spaces))*(width - (sum+spaces));
    		}
    		else{
    			dp[i][j] = 0;
    		}
    	}
    }

    // We have filled dp 2d array here , each i,j value is filled with cost to store word from i to j 
    // for ex.  0-2 so we check word 0,1,and 2 can it fit in one line with spaces if it fits we store
    // square of cost otherwise infinity

    int cost[len];
    int result[len];

    for(int i = len-1; i >= 0; i--){

    	cost[i] = dp[i][len-1];
    	result[i] = len;
    	
    }

    for(int i = 0; i < len; i++)
    	cout<<cost[i]<<" ";

}

int main(){

	int arr[5] = {6,3,5,2,4};
	int line_width = 10;

	WordWrap(arr,5,line_width);

	return 0;
}