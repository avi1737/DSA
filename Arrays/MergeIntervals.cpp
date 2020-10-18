#include<bits/stdc++.h>
using namespace std;

#define COL 2 

void MergeIntervals(vector<vector<int>> vec){
    sort(vec.begin(),vec.end());
    vector<vector<int>> result;
    for(int i = 0; i < vec.size(); i++){
        for(int j = i; j < vec.size(); j++){
            if( vec[i][1] > vec[j][0] ){
                vector<int> temp;
                temp.push_back(vec[i][0]);
                temp.push_back(max(vec[i][1],vec[j][1]));
                result.push_back(temp);
            }
        }

    }

    for(int i = 0; i < result.size(); i++){
            cout<<result[i][0]<<" "<<result[i][1]<<endl;
    }
}

int main(){
    
    vector<vector<int> > vec; 
    int ROW;
    cin>>ROW;
    for (int i = 0; i < ROW; i++) { 
        vector<int> v1; 
        for (int j = 0; j < COL-1; j++) { 
            int i1,i2;
            cin>>i1;
            v1.push_back(i1);
            cin>>i2;
            v1.push_back(i2); 
        } 
        vec.push_back(v1); 
    } 

    MergeIntervals(vec); // passing vector of vector in function
  
    /*for (int i = 0; i < vec.size(); i++) { 
        for (int j = 0; j < vec[i].size(); j++) 
            cout << vec[i][j] << " "; 
        cout << endl; 
    } */
    return 0;
}