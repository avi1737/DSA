#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming Efficient Solution

void printSubStr(string str, int low, int high) 
{ 
    for (int i = low; i <= high; ++i) 
        cout << str[i]; 
} 

void dp_solution(string s){

	// example suppose len is 5 the
	int len = s.length();
    bool dp[len][len];
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            dp[i][j] = false;
        }
    }
    
    // for filling place where i == j
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if( i == j )
            	dp[i][j] = true;
        }
    }

    // for filling place where length of string is two

    for(int i = 0; i < len-1; i++){
    	if( s[i] == s[i+1] )
    		dp[i][i+1] = true;
    	    
    }
    // for lengths greater then 2 

    //aaaabbaa
    // aaa aaa aab abb bba baa
    // aaaa aaab aabb abba bbaa
    // aaaab aaabb aabba abbaa
    // aaaabb aaabba aabbaa

    for(int k = 3; k <= len; k++){

    	for(int i = 0; i < len-k+1; i++){

    		int j = i+k-1;

    		if( s[i] == s[j] && dp[i+1][j-1] == true)
    			dp[i][j] = true;
    	}
    }


    int diff = INT_MIN;
    int start,end;
    for(int i = 0; i < len; i++){
    	for(int j = i; j < len; j++){
    		if( dp[i][j] == 1 && j-i > diff){
    			start = i;
    			end = j;
    			diff = j-i;
    		}
    	}
    }

    cout<<s.substr(start,end+1)<<endl;

}


bool is_palindrome(string s){
    int len = s.length();
    for(int i = 0; i < len; i++){
        if( s[i] != s[len-1-i])
        return false;
    }
    return true;
}

void longest_pstr(string s){

	string longest_str = ""; int si = 0;
	    int len = s.length();
	    for(int i = 0; i < len; i++){
	        for(int j = i; j < len; j++){
	            string temp = s.substr(i,j+1);
	            if(is_palindrome(temp)){
	            	
	                if( temp.length() > si){
	                    si = temp.length();
	                    longest_str = temp;
	                }
	            }
	        }
	    }
	    cout<<longest_str<<endl;
	     
	    // brute force approach to generate all palindromic substrings and then find longest one
	    // with time complexity of o(n^3) considering palindromic fucntion inside two for loops


}

int main() {
	//code
	int T;
	cin>>T;
	while( T-- ){
	    string s;
	    cin>>s;
	    //longest_pstr(s);
	    dp_solution(s);
	}
	return 0;
}