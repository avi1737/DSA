#include<bits/stdc++.h>
using namespace std;
#define InputArray(X,size) for(int i = 0; i < size; i++) { cin>>X[i];}

// return the length of longest consecutive subsequence in an given array

void optimalSolution(int a[],int size){
	set<int> hashset;
	for(int i = 0; i < size; i++){
		hashset.insert(a[i]);
	}
	int max_count = 0;

	for(int i = 0; i < size; i++){
		
		if( hashset.find(a[i]-1) == hashset.end()){
			int j = a[i];
			while( hashset.find(j) != hashset.end()){
				j++;
			}
			max_count = max(j-a[i],max_count);
		}

	}

	cout<<max_count<<endl;
	// Time complexity : o(n) + o(n) + o(n) = o(3n)
	// space complexity : o(n)
}

void NavieSolution(int a[],int size){

	// 1, 9, 3, 10, 4, 20, 2
	sort(a,a+size);
	// 1  2  3  4  9  10  20

	int max_count = 0;
	int count = 1;
	for(int i = 0; i < size; i++){
		if( a[i+1] == a[i] + 1){
			count++;
		}
		else{
			max_count = max(count,max_count);
			count = 1;
		}
	}

	cout<<max_count<<endl;
	//Time complexity : o(nlogn) + o(n)
}


int main(){
	int size;
	cin>>size;
	int A[size];
	InputArray(A,size);
	NavieSolution(A,size);
	optimalSolution(A,size);
	return 0;
}