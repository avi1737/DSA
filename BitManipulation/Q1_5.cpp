#include<bits/stdc++.h>
using namespace std;


/*  Calculate square of a number without using *, / and pow()  */

int squareOfNumber(int number){

	if( number == 0 )
		return 0;

	if ( number  < 0 )
		n = -n;

    if( (number ^ 1) == (number + 1) ){
		// if number is even number then square = 4 * square(n/2)
		int x = number >> 1;

		int ans = squareOfNumber(x) << 2;

		return ans;
	}
	if( (number ^ 1) == (number - 1) ){
		// if number is odd then square = 4*square(n/2) + 4*(n/2) + 1
		int x = number >> 1;

		int ans = squareOfNumber(x) << 2 + x << 2 + 1;

		return ans;
	}
}

/* count all set bits from 1 to N */

int largestPowerBeforeNumberF(int number){
	// in case of 11 it will give 1<<x = 8  x = 3
	int x = 0;
	while( 1<<x <= number ){
		x++;
	}

	return x-1;
}

int countBitsFrom1ToN(int number){

	if(  number == 0 )
		return 0;
	
	int x = largestPowerBeforeNumberF(number);

	int countTill2RaiseTox = (1<<(x-1) * x);
	int countFrom2RaiseToxToNumber = number - ((1<<x)) + 1;
	int remain = number - (1 << x);
	int ans = countTill2RaiseTox + countFrom2RaiseToxToNumber + countBitsFrom1ToN(remain);
	
	return ans;

}

//count total set bits from 1 to number
// time complexity of this is o(n^2)

int oneToNSetBits(int number){
	int count = 0;
	while( number != 1 ){
		count += countSetBit(number);
		number = number-1;
	}
}

// using recursion
bool powerOfTwo(int number){

	if(number == 1)
		return true;
	else if( number % 2 != 0){
		return false;
	}

	return powerOfTwo(number>>1);
}

// using iteration
bool powerOfTwo(int number){

	if( number == 0 )
		return false;
	while( number != 1 ){
		if( number % 2 != 0 )
			return false;
		n = n>>1;
	}
	return true;
}

// because when you & on n (n-1) it gives 0 if n is power of two
bool powerOfTwo(int number){

	return number && ( !(number & (number-1)));
}

// every time we do & with number and (number-1) we remove 1 set bit from number
// we loop until n becomes zero to get number of bits
int countSetBit(int number){

	if( number == 1){
		return 1;
	}

	int count = 0;
	while( number != 0 ){
		number = number & (number-1);
		count++;
	}
	return count;
}

int main(){
	int n;
	cin>>n;

	cout<<countSetBit(n)<<endl;

	if(powerOfTwo(n)){
		cout<<"Number is power of 2"<<endl;
	}
	else{
		cout<<"Number is not power of 2"<<endl;
	}

	return 0;
}