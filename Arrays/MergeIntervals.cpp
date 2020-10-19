#include<bits/stdc++.h>
using namespace std;

// stack method for solving this

class Intervals{
public:
    int start;
    int end;

    Intervals(int start,int end){
        this->start = start;
        this->end = end;
    }
};

void MergeIntervals(int intervals[4][2],int size){

    // time complexity of this algorithm is o(n) for n intervals and 
    // space complexity of algorithm would be o(n) because we are using
    // stack to store it

    if( size <= 1 ){
        cout<<-1<<endl;
    }

    

    stack<Intervals> s;

    Intervals I = Intervals(intervals[0][0],intervals[0][1]);
    s.push(I);

    for(int i = 1; i < size; i++){

        Intervals top = s.top();
        Intervals current = Intervals(intervals[i][0],intervals[i][1]);

        if( top.end < current.start ){
            Intervals temp = Intervals(intervals[i][0],intervals[i][1]);
            s.push(temp);
        }

        else if( top.end > current.start ){
            top.end = max(top.end , current.end);
        }

    }

     while (!s.empty())
    {
        Intervals t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }


}

int main(){

    int intervals[4][2] = { {1,3}, {2,6}, {8,10}, {15,18}};
    int size = sizeof(intervals)/sizeof(intervals[0]);
    MergeIntervals(intervals,size);
    return 0;
}