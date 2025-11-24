// Middle Of Linked List
// Problem statement
// Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly linked list. However, if the list has an even number of nodes, we return the second middle node.

// Note:
// 1. If the list is empty, the function immediately returns None because there is no middle node to find.
// 2. If the list has only one node, then the only node in the list is trivially the middle node, and the function returns that node.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 5
// 1 2 3 4 5
// Sample Output 1 :
// 3 4 5
// Explanation Of Sample Input 1 :

// We can clearly see that there are 5 elements in the linked list therefore the middle node is the node with value '3'.
// Sample Input 2 :
// 6
// 1 2 3 4 5 6
// Sample Output 2 :
// 4 5 6
// Explanation Of Sample Input 2 :

// We can clearly see that there are 6 elements in the linked list and the middle nodes are  nodes with values 3 and 4 hence we return a second middle node having value '4'.
// Constraints :
// 1 <= 'N' <= 10^4
// 0 <= 'data' <= 10^3 

// Where 'N' is the length of the linked list.

// Time Limit: 1 sec

// CODE:-
  
Node *getMiddle(Node *head){
    if( head == NULL || head->next == NULL ){
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

Node *findMiddle(Node *head) {
    return getMiddle(head);
}
