// Problem
/*
You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.

Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', then the last group of nodes should remain unchanged.

For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.

Implement a function that performs this reversal, and returns the head of the modified linked list.
*/

// Code

Node* reverse(Node* root, Node* final) {

        if(root == final)   return root;

        Node* newhead = reverse(root->next, final);

        root->next->next = root;
        root->next = NULL;

        return newhead;
}

Node* kReverse(Node* head, int k) {

   	Node* dummy = new Node(-1, head);

        Node* prev = dummy;
        Node* slow = head;

        while(true){

            if(slow == NULL)    break;

            Node* fast = slow;
            int count = 1;

            while(count < k && fast != NULL && fast->next != NULL)
            {
                fast = fast->next;
                count ++;
            }

            if(count < k)
            {
                prev->next = slow;
                break;
            }

            Node* front = NULL;
            if(fast != NULL)    front = fast->next;

            prev->next = reverse(slow, fast);

            prev = slow;
            slow = front;
        }
        
        return dummy->next;
}