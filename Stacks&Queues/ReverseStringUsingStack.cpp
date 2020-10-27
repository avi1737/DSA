#include<bits/stdc++.h>
using namespace std;

void Reverse(string str){
	stack<char> S;
	for(int i = 0; i < str.length(); i++){
		char ch = str[i];
		S.push(ch);
	}

	string result = "";
	while(!S.empty()){
		char c = S.top();
		result+=c;
		S.pop();
	}

	cout<<"Reverse String : "<<result<<endl;
}

int main(){

	int T;
	cin>>T;
	while( T-- ){
		string s;
		cin>>s;
		Reverse(s);
	}
	return 0;
}