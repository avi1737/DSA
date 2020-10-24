#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
	int len = s.size()/2;
	for(int i = 0; i < len; i++){
		if( s[i] != s[len-1-i]){
			return false;
		}
	}
	return true;
}

void BruteForce(string s){

	// we can generate all possible substrings in given string and check if its palindrome

	// 
	int longest = INT_MIN;
	for(int i = 0; i < s.length(); i++){
		for(int j = i; j < s.length(); j++){
			string temp = s.substr(i,j+1);
			if( isPalindrome(temp)){
				int len = temp.length();
				longest = max(longest,len);
			}
		}
	}

	cout<<"Longest palindromic substring: "<<longest<<endl;
}

int main(){

	string s;
	cin>>s;
	BruteForce(s);
	return 0;
}