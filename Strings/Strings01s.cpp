#include<bits/stdc++.h>
using namespace std;

void SplitS(string s){

	//01 0011 0101

	int count_of_0s = 0;
	int count_of_1s = 0;

	int count = 0;

	//01 0011 110101 0101
	int start = 0;

	for(int i = 0; i < s.length(); i++){
		if( s[i] == '0'){
			count_of_0s++;
		}
		else{
			count_of_1s++;
		}

		if(count_of_0s == count_of_1s){
			count++;
			cout<<s.substr(start,i+1)<<endl;
			start = i+1;
		}
		
	}

	cout<<count<<endl;

	// Time Complexity : O(N) for traversal
}

int main(){

	int T;
	cin>>T;
	while( T-- ){
		string s;
		cin>>s;
		SplitS(s);
	}

	return 0;
}