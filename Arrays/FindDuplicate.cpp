#include<bits/stdc++.h>
using namespace std;

int NaiveSolution(int a[],int size){

    sort(a,a+size); // sort array o(nlogn)

    for(int i = 1; i < size; i++){ // o(n) for traversal
        if( a[i] == a[i-1]){
            return a[i];
        }
    }

}

int InterMediateApproach(int a[],int size){
    // 2 1 4 2 3   n+1 = 5 so n would be 4   1 to 4 numbers
    int HashArray[size] = {0};

    for(int i = 0; i < size ; i++){
        if( HashArray[a[i]] == 1){
            return a[i];
        }
        HashArray[a[i]] = 1;
    }

    // o(n) space complexity and o(n) time complexity
}

int main(){
    int n;
    cin>>n;
    int Arr[n];
    for(int i = 0; i < n; i++){
        cin>>Arr[i];
    }

    int ans = NaiveSolution(int Arr,n);
    int ans = InterMediateApproach(int Arr,n);
    return 0;
}