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
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* l3_tmp = l3;
        
        ListNode* l1_tmp = l1;
        ListNode* l2_tmp = l2;

        int num1 =0, num2=0, total=0;

        bool flag = false;

        while(l1_tmp != NULL || l2_tmp != NULL){
            if(l1_tmp!=NULL){
                num1 = l1_tmp->val;
                l1_tmp = l1_tmp->next;
            }
            else{
                num1 = 0;
            }
            if(l2_tmp!=NULL){
                num2 = l2_tmp->val;
                l2_tmp = l2_tmp->next;
            }
            else{
                num2 = 0;
            }

            total = flag;
            
            if(total + num1+num2 >= 10){
                total = total + num2 + num1 -10;
                flag = true; 
            }
            else{
                total = total + num1 + num2;
                flag = false;
            }
             
            ListNode* tmp  = new ListNode(total);
            l3_tmp->next = tmp;
            l3_tmp = l3_tmp->next;
        }

        if(flag){
            ListNode* tmp  = new ListNode(flag);
            l3_tmp->next = tmp;
        }

        return l3->next;
    }
};
