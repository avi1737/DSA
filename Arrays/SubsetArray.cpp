#include<bits/stdc++.h>
using namespace std;

#define InputArray(X,size) for(int i = 0; i < size; i++) { cin>>X[i];}
#define DisplayArray(A) for(int i = 0; i < size; i++) { cout<<A[i];}


bool usingHashing(int a[],int m,int b[],int n){

	set<int> hashset;

	for(int i = 0; i < m; i++){
		hashset.insert(a[i]);
	}

	for(int j = 0; j < n; j++){
		if( hashset.find(a[j]) == hashset.end() ){
			return false;
		}
	}

	return true;

	//Time Complexity : o(m) for traversing a and o(n) for b 
	// Space Complexity : o(n) for hashset
}

bool usingSorting(int a[],int m,int b[],int n){

	sort(a,a+m);  // mlogm
	sort(b,b+n);  // nlogn

	int i = 0, j= 0;
	int count = 0;

	while( i < m && j < n ){
		if(a[i] < b[j] ){
			i++;
		}
		else if( a[i] > b[j] ){
			j++;
		}
		else{
			count++;
		}
	} 

	if( count == n ){
		return true;
	}
	else{
		return false;
	}

}


bool bruteforce(int a[],int m,int b[],int n){
	// let a = [1,5,6,9,34,67];  b = [5,34];
	int count = 0;
	for(int i = 0; i < n; i++){ 

		for(int j = 0; j < m; j++){

			if( b[i] == a[j] ){
				count++;
			}
		}
	}

	if( count == n ){
		return true;
	}
	else{
		return false;
	}

	/* this solution we traverse b small array and for every element of b we check if its there
	int a or not if its there we increase count , simply if all element of b are in a so count would 
	be equal to array b size 
	Time Complexity : o(n*m) */
}

int main(){

	int m,n;
	cin>>m>>n;
	int A[m];
	int B[n];
	InputArray(A,m);
	InputArray(B,n);
	bruteforce(A,m,B,n)?cout<<"YES":cout<<"NO";
	usingSorting(A,m,B,n)?cout<<"YES":cout<<"NO";
	return 0;
}