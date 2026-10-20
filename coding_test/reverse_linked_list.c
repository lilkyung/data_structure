struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL) return head;
    else{
        struct ListNode *stack=NULL;
        for(struct ListNode *p=head; p!=NULL;p=p->next){
            struct ListNode *q=(struct ListNode *)malloc(sizeof(struct ListNode));
            q->val = p->val;
            q->next = stack;
            stack=q;
        }
        return stack;
    }
}   
