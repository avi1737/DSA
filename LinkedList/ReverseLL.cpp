/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Node {

public:
    int data;
    Node* next;
    
	Node(int data){
		this->data = data;
		this->next = NULL;
	}

};

class LinkedList {

private:
	Node* head = NULL;

public:

	void insert(int data){
		Node* n = new Node(data);
		if(this->head == NULL ){
			head = n;
		}
		else{
			Node* current = this->head;
			while(current->next != NULL){
				current = current->next;
			}
			current->next = n;
		}

	}

	void display(){
		Node* current = this->head;
		while(current != NULL){
			cout<<current->data<<endl;
			current = current->next;
		}
		cout<<endl;
	}
	
	// iterative manner 
	
	void reverse(){

		Node* current = this->head;
		Node* previous = NULL;
		Node* next = NULL;

		while( current != NULL ){
			
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;

		}

		this->head = previous;

	}
	
	void ReverseUsingRecursion(Node* address){
	    
	    if( address->next == NULL ){
	        head = address;
	        return;
	    }
	   
	    ReverseUsingRecursion(address->next);
	    Node* q = address->next;
	    q->next = address;
	    address->next = NULL;
	    
	}
	
	Node* getHead(){
	    return this->head;
	}

	void addOne(Node* headAfterReverse){

		int carry = 1;
		int sum = 0;

		while( headAfterReverse != NULL ){

			sum = headAfterReverse->data + carry;

			if( sum >= 10 ){
				carry = 1;
			}
			else{
				carry = 0;
			}

			int ans = sum % 10;

			headAfterReverse->data = ans;

			headAfterReverse = headAfterReverse->next;

		}
	}

	void addTwoNumbersLL(Node* head1 ,Node* head2){

	//first we will reverse both linked list and return head

	int carry = 0;
	int addition = 0;
	int remainder = 0;
	int devide_by_10;

	LinkedList llres;

	while( head1 != NULL || head2 != NULL ){

		addition = head1->data + head2->data;

		devide_by_10 = addition/10;

		if( devide_by_10 != 0 ){
            
            if( carry == 0){
            	remainder = addition%10;
            }
            else{
            	remainder = (addition + carry) % 10;
            }

			llres.insert(remainder);
			carry = devide_by_10;

		}
		else{
			llres.insert(addition);
		}


		head1 = head1->next;
		head2 = head2->next;
	}

}


};

int main(){

	LinkedList LL;
	LL.insert(2);
	LL.insert(2);
	LL.insert(3);
	LL.insert(5);
	LL.insert(10);
	LL.insert(10);

	Node* head = LL.getHead();

	LL.removeDuplicates(head);
	
	LL.display();
}