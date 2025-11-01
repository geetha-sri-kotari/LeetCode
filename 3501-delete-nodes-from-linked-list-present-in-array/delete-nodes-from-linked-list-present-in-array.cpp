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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* ans=NULL;
        unordered_map<int,int> frq;
        for(int i=0; i<nums.size(); i++) frq[nums[i]]++;
        ListNode* temp1 = head;
        ListNode* temp2;
        while(temp1 != NULL) {
            if(frq[temp1->val] == 0) {
                if(ans == NULL) {
                    ans = temp1;
                    temp2 = temp1;
                }
                else {
                    temp2->next = temp1;
                    temp2 = temp2->next;
                }
                // temp2->next = NULL;
            }
            temp1 = temp1->next;
        }
        temp2->next=NULL;
        return ans;
    }
};