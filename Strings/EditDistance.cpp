#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string s,t;
    cin>>s>>t;
    
    int len_s = s.length(); // 3  abc
    int len_t = t.length(); // 3  acd
    
    int dp[len_s+1][len_t+1];
    
    for(int i = 0; i < len_s+1; i++){
        for(int j = 0; j < len_t+1; j++){
            
            if( i == 0 && j == 0){
                dp[i][j] = 0;
            }
            else if( i == 0 ){
                dp[i][j] = dp[i][j-1] + 1;
            }
            else if( j == 0 ){
                dp[i][j] = dp[i-1][j] + 1;
            }
            else{   // case for 1,1  1,2 1,3 .. or 2,1 2,2 2,3
                if( s[i-1] == t[j-1] ){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                }
            }
        }  
    }
    
    for(int i = 0; i < len_s+1;i++){
        for(int j = 0; j < len_t+1; j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}