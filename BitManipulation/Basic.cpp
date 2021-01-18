#include<bits/stdc++.h>
using namespace std;

void findBit(int number, int pos){
	// 110010 if and pos = 2
    // left shift 1 by pos bits   00001  to  <<  00100
    int mul = 1<<pos;

    mul &= number;

    if( mul ){
    	cout<<"bit is 1"<<endl;
    }
    else{
    	cout<<"bit is 0"<<endl;
    }
}

void setBit(int number,int pos){
	// make bit at pos to 1  1000  pos = 1  1001
	int mul = 1<<pos;

    mul ^= number;

    cout<<mul<<endl;
}

void clearBit(int number,int pos){
	// 100101 pos = 3 then  100001

	int mul = 1<<pos;  // 000100
	mul = ~(mul);      // 111011 & 100101
	mul &= number;     // 100001

	cout<<mul<<endl;
}

int main(){

	int n,pos;
	cin>>n>>pos;
	findBit(n,pos);

}