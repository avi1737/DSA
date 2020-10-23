#include<bits/stdc++.h>
using namespace std;
#define CHAR_SIZE 26

void findDuplicate(string s){

	int characters[CHAR_SIZE];
	for(int i = 0 ; i < CHAR_SIZE; i++){
		characters[i] = 0;
	}
	int len = s.size();
	for(int i = 0; i < len; i++){
		characters[(int)s[i] - 97]++;
	}

	for(int i = 0; i < CHAR_SIZE; i++){
		if( characters[i] > 1){
			cout<<char(i+97)<<" "<<characters[i]<<endl;
		}
	}

	// Time Complexity : o(n) 
	// Space Complexity : o(n)
}

int main(){

	string s;
	cin>>s;
	findDuplicate(s);
	return 0;
}