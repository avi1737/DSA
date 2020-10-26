#include<bits/stdc++.h>
using namespace std;

bool ParanthesisCheck(string s){

	stack<char> st;

	for(int i = 0; i < s.length(); i++){

		char ch = s[i];

		if( ch == '(' || ch == '[' || ch == '{'){
			st.push(ch);
		}
		else if( ch == ')'){
			if( st.size() == 0){
				return false;
			}
			else if( st.top() != '('){
				return false;
			}
			else{
				st.pop();
			}
		}
		else if( ch == ']'){
			if( st.size() == 0){
				return false;
			}
			else if( st.top() != '['){
				return false;
			}
			else{
				st.pop();
			}
		}
		else if( ch == '}'){
			if( st.size() == 0){
				return false;
			}
			else if( st.top() != '{'){
				return false;
			}
			else{
				st.pop();
			}
		}
	}

	if( st.size() == 0 ){
	    return true;
	}
	else{
	    return false;
	}

	// Time Complexity : o(n) and o(n) space 

}

int main(){

	int T;
	cin>>T;
	while( T-- ){
		string s;
		cin>>s;
		if(ParanthesisCheck(s)){
			cout<<"Balanced"<<endl;
		}
		else{
			cout<<"Not Balanced"<<endl;
		}
	}

	return 0;
}