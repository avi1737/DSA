#include <bits/stdc++.h>
using namespace std;


// using hashmap head->1->2->3->4->5->null
// head->1->2->3->4---!
//          !----------!
// o(n) space complexity and o(n) time complexity

bool detectLoop(Node* head){

	unordered_set<Node*> uset;

	while( head != NULL ){

		if( uset.find(head) != uset.end())
			return true;
		uset.insert(head);
		head = head->next;

	}

	return false; 

}

//floydd marshal method

bool detectLoop(Node* head){

	Node* slow = head;
	Node* fast = head;

	while( fast->next->next != NULL ){
		slow = slow->next;
		fast = fast->next;

		if(slow == fast)
			return true;
	}

  return false;
}

void deleteLoop(Node* head){
	Node* slow = head;
	Node* fast = head;

	while( fast->next->next != NULL ){
		slow = slow->next;
		fast = fast->next;

		if(slow == fast)
			fast->next = NULL;
		// when slow and fast node meets then, make address->next == NULL
	}

}
