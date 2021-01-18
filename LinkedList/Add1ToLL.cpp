
// first we will reverse the linked list for example
// we have 1->2->3   3->2->1 then from left side add 1

// 1->2->3  3->4->0   1<-2<-3

Node* reverse(Node* head){
	Node* current = head;
	Node* prev = NULL;
	Node* Next = NULL;

	while( current != NULL ){
		Next = current->next;
		current->next = prev;
		current = Next;
		prev = current;
	}

	return prev;
}

// we get 5 4 3
//        3 6 9

void addTwoNumbersLL(Node* head1 ,Node* head2){

	//first we will reverse both linked list and return head

	int carry = 0;
	int addition = 0;
	int remainder = 0;
	int devide_by_10;

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

			head2->data = remainder;
			carry = devide_by_10;

		}
		else{
			head2->data = addition;
		}


		head1 = head1->next;
		head2 = head2->next;
	}

}


// find the middle element of linked list

//  head->1->3->56->78->34->null

Node* findMiddleElement(Node* head){

	int count = 0;
	Node* current = head;

	while( current != NULL ){
		current = current->next;
		count++;
	}

	current = head;
	count = count/2;

	while( count-- ){
		current = current->next;
	}

	return current->data;
}


// move last element to front of linked list in dsa

// 1->2->3->4->5->null

void moveFront(Node* head){

	Node* current = head;
	Node* prev = NULL;

	while( current->next != NULL ){
		prev = current;
		current = current->next;
	}

	current->next = head;
	head = current;
	prev->next = NULL;

}

// check if LL is circular or not

bool isCircular(Node* head){
	// head->1->2->3->2
	unorder_set<Node*> address;

	Node* current = head;
	while( current != NULL ){
		if( address.find(current) != address.end()){
			return true;
		}
		else{
			address.insert(current);
		}
		current = current->next;
	}

	return false;

}


// reverse LL in group size of k
// head -> 1->2->3->4->5->6->null now k = 2

Node* reverseK(Node* head, int k){

	Node * curr = head;
	Node * next = NULL;
	Node * prev = NULL;

	int count = 0;

	while( curr != NULL && count < k ){
		next = curr->next;
		curr->next = prev;
		curr = next;
		prev = curr;
		count++;
	} 

	if( next != NULL){
	head->next = reverseK(next,k);
    }

	return prev;
}


// intersection point of two linked lists

// method 1 Tc - m*n

Node* Intersection(Node* head1, Node* head2){

	Node* curr1 = head1;
	Node* curr2 = head2;

	while( curr1 != NULL ){
		while( curr2 != NULL){
			if( curr1 == curr2 ){
				return curr1;
			}
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	}

	return NULL;
}

// method 2 - making visited TC - o(n) + o(m) but extra space

Node* Intersection(Node* head1, Node* head2){

	Node* curr1 = head1;
	Node* curr2 = head2;

	while( curr1 != NULL ){
		curr1->isVisited = true;
		curr1 = curr1->next;
	}

	while( curr2 != NULL ){
		if( curr2->isVisited == true){
			return curr2;
		}
	}
}

// method 3 - calc diff

Node* Intersection(Node* head1, Node* head2){

	Node* curr1 = head1;
	Node* curr2 = head2;
	int len1 = 0;
	int len2 = 0;

	while( curr1 != NULL ){
		len1++;
		curr1 = curr1->next;
	}

	while( curr2 != NULL ){
		len2++;
		curr2 = curr2->next;
	}

	if( len1 > len2 ){
		int diff = (len1-len2);
		Node* curr = head1;
		while( diff != 0 ){
			curr = curr->next;
			diff--;
		}

		while( curr != NULL ){
			if( curr == head2 ){
				return curr;
			}
			curr = curr->next;
			head2 = head2->next;
		}
	}
	else{
		int diff = (len2-len1);
		Node* curr = head2;
		while( diff != 0 ){
			curr = curr->next;
			diff--;
		}

		while( curr != NULL ){
			if( curr == head1 ){
				return curr;
			}
			curr = curr->next;
			head1 = head1->next;
		}
	}
}


// check if LL is Palindrom (singly LL)
// head->a->b->a->d->a->b->a->null

Node* reverse(Node* head){
	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;

	while( curr != NULL ){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

bool isPalindrome(Node* head){

	Node* slow = head;
	Node* fast = head;
	Node* second_ll;

	while( true ){
		
		slow = slow->next;
		fast = fast->next->next;

		// odd LL
		if( fast->next == NULL ){
			second_ll = slow->next;
			slow->next = NULL;
			break;
		}

		if( fast == NULL ){
			second_ll = slow;
			slow->next = NULL;
			break;
		}		
	}

	Node* head_second = reverse(second_ll);

	while( head_second && head ){
		if( head_second->data != head->data){
			return false;
		}
		head = head->next;
		head_second->head_second->next;
	}

	return true;
}