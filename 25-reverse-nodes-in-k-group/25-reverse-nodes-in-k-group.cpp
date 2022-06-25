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
class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* &head, int k) 
    {
        //empty list
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* temp = head;
        for(int i = 0; i < k; i++)
        {
            if(temp == NULL) return head;
            temp = temp->next;
        }
        
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int count = 0;
        
        // Step1: reverse firts kth nodes
        while(curr!=NULL && count<k)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        //next pointer will be pointing at the head of the remaning list
        if(next!= NULL)
        {
            //Step2: recursion will get ans for remaining list
            ListNode* rem = reverseKGroup(next, k);
            
            //step3: connection list in step 1 and step 3
            head -> next = rem;
        }
        //Step4: return head of entire list
        return prev;
    }
     
};