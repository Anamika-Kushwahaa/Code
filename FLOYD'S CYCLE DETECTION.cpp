//FLOYD'S CYCLE DETECTION

//Code to detect loop
Node * detectloop(Node *head){
  if(head == NULL)
    return NULL;
  Node * slow = head;
  Node * fast = head;
  while(slow != NULL && fast != NULL){
    fast=fast->next;
    if(fast != NULL)
      {         
        fast=fast->next;
      }
     slow=slow->next;
    if(slow == fast){
      cout<<"loop present at" << slow->data << endl;
      return slow;
    }
  }
return NULL;
}
  
