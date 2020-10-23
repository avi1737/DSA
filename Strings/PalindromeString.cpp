	
// Just The Fucntion which checks if string is palindrome or not
// there are other method like using stack also or creating new string 
// but this is most efficient method runs in o(n/2)

	int isPlaindrome(string S)
	{
	    // Your code goes here
	    for(int i = 0; i < S.size()/2;i++){
	        if( S[i] != S[S.size()-1-i]){
	            return 0;
	        }
	    }
	    
	    return 1;
	}