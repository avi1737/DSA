#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }

    if( A[0] == 0 ){
        cout<<-1<<endl;
        return 1;
    }
    // initilialize minimum jump array with maximum value or infinity must be more then n

    int minimum_jump_array[n];
    for(int i = 0; i < n; i++){
        minimum_jump_array[i] = n+30;  
    }

    // 0th index of array should be zero hard coded because to reach at 0th index 0 jumps
    // required

    minimum_jump_array[0] = 0;

    int path_array[n];
    path_array[0] = 0;

   // 2 3 1 1 2 4 2 0 1 1

   //main logic of code here in two for loops where i goes from 1 ---- n and j goes for 0 to < i for
   // every single i , idea is to see this problem as small subproblem and try to get minimup jumps 
   // required to reach at every point

   for(int i = 1; i < n; i++){
       for(int j = 0; j < i; j++){
           if( i <= A[j]+j){
               // so its in range
               minimum_jump_array[i] = min(minimum_jump_array[j]+1,minimum_jump_array[i]);
           }
       }
   }

   cout<<minimum_jump_array[n-1]<<endl;

    return 0;
}