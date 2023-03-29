class Solution {
public:
    ListNode* solve(ListNode* l1,ListNode* l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val < l2->val){
            l1->next = solve(l1->next,l2);
            return l1;
        }else{
            l2->next = solve(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* node = new ListNode (INT_MIN);
        for(auto &i: lists){
            node = solve(node,i);
        }
        return node->next;
    }
};
