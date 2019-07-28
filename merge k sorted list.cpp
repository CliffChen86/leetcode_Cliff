/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    const int INF=0x3f3f3f3f;
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        
        int length = lists.size();
        
        while(1){
            int index = -1;
            int minn = INF;
            int cnt = 0;
            for(int i = 0; i < length; i++){
                if(lists[i]){
                    if(lists[i]->val <= minn){
                        index = i;
                        minn = lists[i]->val;
                    }
                }
                else
                    cnt += 1;
            }
            if(cnt == length)
                break;
            res->next = lists[index];
            res = res->next;
            lists[index] = lists[index]->next;
        }
        
        return head->next;
    }
};

// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6