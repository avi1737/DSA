#include<bits/stdc++.h>
using namespace std;

void printArray(int a[],int size){
	for(int i = 0; i < size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

// Efficient Method
void NextGreaterElement(int arr[],int size){
	stack<int> s;
	
	s.push(arr[0]);

	for(int i = 1; i < size; i++){
		if( s.empty()){
			s.push(arr[i]);
			continue;
		}

		while( !s.empty() && arr[i] > s.top()){
			cout<<s.top()<<"--->"<<arr[i]<<endl;
			s.pop();
		}

		s.push(arr[i]);
	}

	while( !s.empty()){
		cout<<s.top()<<"--->"<<-1<<endl;
		s.pop();
	}
}

void NextGreaterElement(int arr[],int size){
	// 4 1 2 8 10 23
	int result[size];
	for(int i = 0; i < size; i++){
		result[i] = -1;
	}
	for(int i = 0; i < size; i++){
		for(int j = i+1; j < size; j++){
			if( arr[j] > arr[i]){
				result[i] = arr[j];
				break;
			}
		}
	}

	// Time Complexity is o(n^2)

	printArray(arr,size);
	printArray(result,size);
} 

int main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	NextGreaterElement(arr,n);
	return 0;
}