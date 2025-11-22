/* REVERSE LINKED LIST
Problem statement
Given a singly linked list of integers. Your task is to return the head of the reversed linked list.

For example:
The given linked list is 1 -> 2 -> 3 -> 4-> NULL. Then the reverse linked list is 4 -> 3 -> 2 -> 1 -> NULL and the head of the reversed linked list will be 4.
Follow Up :
Can you solve this problem in O(N) time and O(1) space complexity?
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5
0 <= L <= 10^5
1 <= data <= 10^9 and data != -1

CODE:-
*/

LinkedListNode<int> *reverse(LinkedListNode<int> *head){
    //base case
    if(head == NULL || head->next == NULL ){
        return head;
    }
    LinkedListNode<int> *newHead = reverse(head->next);
    head->next->next = head ; 
    head->next = NULL;
    return newHead;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    return reverse(head);
}
