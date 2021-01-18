/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int findMajority(int arr[],int size){
	// 4 2 4 3 4 5 4

	map<int,int> umap;
	int halfsize = size/2;

	for(int i = 0; i < size; i++){
		if( umap.find(arr[i]) != umap.end()){
			umap[arr[i]]++;
			if(umap[arr[i]] > halfsize){
			    return arr[i];
			}
		}
		else{
			umap.insert(pair<int,int>(arr[i],1));
		}
	}

	return -1;
}


int main(){

	int T;
	cin>>T;

	while( T-- ){
		int n,number;
		cin>>n;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}

		int element = findMajority(arr,n);
		cout<<element<<endl;
	}
	return 0;
}