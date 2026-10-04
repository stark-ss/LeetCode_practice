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
    struct compare{
     bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
     }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
       priority_queue<ListNode*,vector<ListNode*>,compare> q;
       for(auto& i:lists){
        if(i)
        q.push(i);
       }

       ListNode* res=new ListNode(0);
       ListNode* tail=res;
       while(!q.empty()){
        auto cur=q.top();
        q.pop();
        tail->next=cur;
        tail=tail->next;
        if(cur->next)
        q.push(cur->next);
       }
      return res->next;
    }
};