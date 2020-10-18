#include<bits/stdc++.h>
using namespace std;


void swap(int* a,int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int i = 0,j = 0;
	    while( i < n && j < m ){
	        if( arr1[i] > arr2[j] ){
	            swap(&arr1[i],&arr2[j]);
                i++;
	            sort(arr2,arr2+m);
	        }
            else{
            swap(&arr1[i],&arr2[j]);
                j++;
	            sort(arr2,arr2+m);    
            }
	    }
	    
	    for(int i = 0; i < n;i++){
	        cout<<arr1[i]<<" ";
	    }
	    for(int i = 0; i < m;i++){
	        cout<<arr2[i]<<" ";
	    }
	    
	}

int main(){

    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < m; i++){
        cin>>b[i];
    }
    merge(a,b,n,m);
    return 0;
}