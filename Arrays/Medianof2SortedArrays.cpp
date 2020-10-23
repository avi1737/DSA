#include<bits/stdc++.h>
using namespace std;

void Median2SortedArray(int a[],int m,int b[],int n){

	vector<int> result;
	int i = 0, j = 0;
	while( i < m && j < n ){

		if( a[i] < b[j]){
			result.push_back(a[i]);
			i++;
		}
		else if( a[i] > b[j]){
			result.push_back(b[j]);
			j++;
		}
		else if( a[i] == b[j] ){
			result.push_back(a[i]);
			i++;
			j++;
		}
	}

	while( i < m ){
		result.push_back(a[i]);
		i++;
	}

	while( j < n ){
		result.push_back(b[j]);
		j++;
	}

	int size = result.size();

	if( size % 2 == 1){
		cout<<result[size/2];
	}
	else{
		int median = result[size/2] + result[size/2-1];
		cout<<median/2<<endl;
	}
}

int main(){

	int m,n;
	cin>>m>>n;
	int a[m],b[n];
	for(int i = 0; i < m ; i++) cin>>a[i];
	for(int i = 0; i < n ; i++) cin>>b[i];
	Median2SortedArray(a,m,b,n);

	return 0;
}