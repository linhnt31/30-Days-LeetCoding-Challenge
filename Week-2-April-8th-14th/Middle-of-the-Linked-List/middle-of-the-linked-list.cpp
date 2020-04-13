/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Method 1 :Time complexity: O(n)-n is the number of nodes in the given list.... Space complexity: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* tmp = head;
        ListNode* move = head;
        int leng = 0;
        while(tmp != NULL){
            leng++;
            tmp = tmp->next;
        }
        leng /= 2;
        while(leng){
            move = move->next;
            leng -= 1;
        }
        return move;
    }
};

//Method 2: Time complexity: O(n)-n is the number of nodes in the given list.... Space complexity: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* moveOne = head;
        ListNode* moveTwo = head;
        
        while(moveTwo != NULL){
            moveTwo = moveTwo->next;
            if(moveTwo == NULL){
                return moveOne;
            }
            moveTwo = moveTwo->next;
            moveOne = moveOne->next;
        }
        return moveOne;
    }
};