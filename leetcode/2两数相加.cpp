/*
这个写法和官方题解思路其实是一样的，但是废话比较多使得更容易理解一点
*/
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
        ListNode* l3 = new ListNode(0); //开一个新的链表L3， 用于储存结果。
        
        ListNode* l3_tmp = l3; //使用tmp在链表中移动
        ListNode* l1_tmp = l1;
        ListNode* l2_tmp = l2;

        int num1 =0, num2=0, total=0; //num1、num2代表两个链表当前位置上的数字， total表示进位加上两数字的和

        bool flag = false;//flag表示是否存在进位

        while(l1_tmp != NULL || l2_tmp != NULL){     //执行遍历，当两个链表不同时遍历到末尾时进行遍历
            if(l1_tmp!=NULL){                        //如果链表1没有遍历至末尾，取出当前数字，并向后移动；
                num1 = l1_tmp->val;
                l1_tmp = l1_tmp->next;
            }
            else{                                    //否则，将num1置0，同时不移动L1
                num1 = 0;
            }
            if(l2_tmp!=NULL){                        //与前面同理
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
