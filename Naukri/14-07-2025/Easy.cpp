// Problem
/*
You are given a singly linked list ‘HEAD’ consisting of ‘N’ nodes. The task is to group all the odd nodes together, followed by the even nodes, maintaining the relative order of nodes given in the input. Note that we are talking about the node’s positions and not the value stored in the node. Try to write an in-place algorithm (i.e., without using any extra space) to solve this problem.
*/

// Code

Node *oddEvenLinkedList(Node *head) {
    
    Node* oddhead = head;
    Node* evenhead = head->next;

    Node* oddtemp = oddhead;
    Node* eventemp = evenhead;

    while(oddtemp && eventemp && eventemp->next) {

        oddtemp->next = eventemp->next;
        eventemp->next = oddtemp->next->next;

        oddtemp = oddtemp->next;
        eventemp = eventemp->next;
    }

    oddtemp->next = evenhead;

    return oddhead;
}