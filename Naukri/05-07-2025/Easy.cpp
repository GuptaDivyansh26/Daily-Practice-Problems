// Problem
/*
You are given two LinkedList of length ‘N’. Your task is to insert the elements of the second LinkedList in the first LinkedList at the alternate positions.

For example: Let 1 -> 3 -> 5 be the first LinkedList and 2 -> 4 -> 6 be the second LinkedList. Then after merging the first LinkedList will look like 1 -> 2 -> 3 -> 4 -> 5 -> 6.
*/

// Code

void merge(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 && temp2) {

        Node* front = temp2->next;
        temp2->next = temp1->next;
        temp1->next = temp2;
        
        temp2 = front;
        temp1 = temp1->next->next;
    }
}