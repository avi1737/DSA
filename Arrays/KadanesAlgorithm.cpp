#include<bits/stdc++.h>
using namespace std;

int kadanesAlgorithm(int a[],int size){
    
    // idea is to find maximum possible sum at every index of the array

    int max_ending_here = a[0];  // for 0th index maximum sum is a[0]
    int max_so_far = a[0];       // max sum so far is a[0] as we have not checked further

    for(int i = 1; i < size ; i++){  // we iterate from 1 to size - 1 

        max_ending_here = max( a[i], a[i] + max_ending_here);
        max_so_far = max(max_ending_here,max_so_far);

    }
    
    return max_so_far;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }

    int maximum_subarray_sum = kadanesAlgorithm(arr,n);
    cout<<maximum_subarray_sum<<endl;
    return 0;
}