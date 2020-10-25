#include<bits/stdc++.h>
using namespace std;


void PrintPermutation(string s, int left,int right){

	if( left == right )
		cout<<s<<endl;
	else
		for(int i = left; i <= right; i++){

			swap(s[left],s[i]);
			PrintPermutation(s,left+1,right);
			swap(s[left],s[i]);

		}
		
}


int main(){

	string s;
	cin>>s;
	PrintPermutation(s,0,s.length()-1);

	return 0;
}