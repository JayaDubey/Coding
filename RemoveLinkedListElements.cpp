/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    //Recursive approach
    //    if(head == 0){
    //        return head;
    //    }
   //     if(head->val == val){
   //         return removeElements(head->next, val);//ignore val values
   //     }
   //     else{
   //     head->next = removeElements(head->next, val); 
   //link other values in head other than val and return it
   //     return head;
   // }
        //or iterative approach
        if(head == 0)
            return head;
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
        if(temp->next->val == val)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }
    if(head->val == val)
            head = head->next;
    return head;
    }
};