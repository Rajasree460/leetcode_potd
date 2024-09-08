/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize){

    *returnSize = k;
    struct ListNode **ListArr = (struct ListNode *)malloc(sizeof(struct ListNode)*k);

    int n=0; struct ListNode *temp=head; // To find no. of elements
    while(temp){
        n++; temp=temp->next;
    }

    int r=n%k, size; n/=k;
    ListArr[0]=temp=head;

    for(int i=1; i<k; i++){
        if(!temp && r<1) ListArr[i] = NULL;
        else{
            size = r--<1? n : n+1;
            while(--size)
                temp=temp->next;
            ListArr[i] = temp->next;
            temp->next=NULL;
            temp=ListArr[i];
        }
    }
    return ListArr;
}
