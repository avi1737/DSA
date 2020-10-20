// C++ program to print common elements in three arrays 
#include <bits/stdc++.h> 
using namespace std; 

// This function prints common elements in ar1 
void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3) 
{ 
	// first we are going to find intersection of elements between ar1 and ar2
	// we store those elements in result[] array
	int i = 0, j = 0;
	vector<int> result;
	while( i < n1 && j < n2 ){
		if( ar1[i] < ar2[j] ){
			i++;
		}
		else if( ar1[i] > ar2[j] ){
			j++;
		}
		else{
			result.push_back(ar1[i]);
			i++;
			j++;
		}
	}

	// Now we will find intersection between result[] and ar3 and that is our
	// answer. Time complexity of algorithm would be o(n1+n2+n3); 

	i = 0; j = 0;
	while( i < result.size() && j < n3 ){
		if( result[i] < ar3[j] ){
			i++;
		}
		else if( result[i] > ar3[j] ){
			j++;
		}
		else{
			cout<<result[i]<<" ";
			i++;
			j++;
		}
	}

} 

// Driver program to test above function 
int main() 
{ 
	int ar1[] = {1, 5, 10, 20, 40, 80,100}; 
	int ar2[] = {6, 7, 20, 80, 100}; 
	int ar3[] = {3, 4, 15, 20, 30, 70, 80, 100,120}; 
	int n1 = sizeof(ar1)/sizeof(ar1[0]); 
	int n2 = sizeof(ar2)/sizeof(ar2[0]); 
	int n3 = sizeof(ar3)/sizeof(ar3[0]); 

	cout << "Common Elements are "; 
	findCommon(ar1, ar2, ar3, n1, n2, n3); 
	return 0; 
} 
