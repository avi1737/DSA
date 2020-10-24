#include <bits/stdc++.h>
using namespace std;

bool checkSimilar(string s,string p){
	if( s.length() != p.length()){
		return false;
	}

	for(int i = 0; i < s.length(); i++){
		if( s[i] != p[i] ){
			return false;
		}
	}

	return true;
}

bool Solve(string s1,string s2,int len){

	for(int i = 0; i < len; i++){
		string t1 = s1.substr(i+1,len);
		string t2 = s1.substr(0,i+1);
		string temp = t1+t2;
		cout<<temp<<endl;
		if( checkSimilar(temp,s2)){
			return true;
		}
	}
	// Time Complexity of Algorithm will be o(n^2)
	return false;
}

bool EfficientSolution(string s1,string s2,int len){

	// we are going to use KMP Algorithm 
	// First We concate s1 with s1

	// s1 = "javaprogrammer"
	// After Concetination s1+s1  = "javaprogrammerjavaprogrammer";

	string temp = s1 + s1;
	
}

int main(){

	string s1,s2;
	cin>>s1>>s2;

	int len = s1.length();

	if(Solve(s1,s2,len)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

	return 0;
}