#include<bits/stdc++.h>
using namespace std;

// Print Subsequence using recursion

/* Subsequence of strings are part of strings with or withour space but in order where order matters
   int recursive solution we write code by doing yes or no for every charater in string either we include
   that char or exclude

   abc 
*/

void PrintSubSe(string q,string ans){

	if( q.length() == 0 ){
		cout<<ans<<" ";
		return;
	}
	char c = q[0];  // a
	string ques = q.substr(1);  // bc    this would be our ques now

	PrintSubSe(ques,ans+c);
	PrintSubSe(ques,ans+"");

	// Time complexity : 2^n where n is size of string and 
}

int main(){

	string s;
	cin>>s;
	PrintSubSe(s,"");

	return 0;
}