#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while( T-- ){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
	    }
	    int no_of_students;
	    cin>>no_of_students;
	    
	    sort(a,a+n);
	    int i = 0;
	    int j = no_of_students-1;
	    
	    int mini = a[j] - a[i];
	    
	    while( a[i+1] > a[i] && a[j+1] == a[j] ){
	        i++;
	        j++;
	    }
	    
	    cout<<a[j] - a[i]<<endl;
	}
	return 0;
}