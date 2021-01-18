#include <bits/stdc++.h>
using namespace std;

// suppose we are given head of sorted linked list which has duplicates
// exp. head->2->2->2->5->7->10->10->null;

void removeDuplicates(Node* head){

	Node* current = head;
	Node* nextNode = head->next;

	while( nextNode != NULL ){
		while( current->data == nextNode->data && nextNode != NULL){
			current->next = nextNode->next;
			nextNode = nextNode->next;
		}
		current = nextNode;
		nextNode = nextNode->next;
	}

}