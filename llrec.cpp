#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if (head == NULL){
		smaller = nullptr;
    larger = nullptr;
    return;
	}
	// if the head's value is smaller than pivot's value
	Node* temp = head -> next;

	if ((head -> val) > pivot){
		larger = head;
		larger -> next = NULL;
		llpivot(temp, smaller,larger -> next, pivot);
	}
	else{
		smaller = head;
		smaller -> next = NULL;
		llpivot(temp, smaller->next,larger, pivot);	
	}
	// else if larger
	
	
	head = nullptr;
	
	

}


