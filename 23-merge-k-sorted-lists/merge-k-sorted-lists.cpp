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
class Solution { // using lisked-list
public:
    // func to merge two sorted liked list
    ListNode* mergeTwo(ListNode* L1, ListNode* L2){
        if(!L1)
        return L2;

        if(!L2) return L1;

        if(L1->val <= L2->val){
            L1->next = mergeTwo(L1->next, L2);

            return L1;
        }

        else{
            L2->next = mergeTwo(L1, L2->next);

            return L2;
        }

        return NULL;
    }
    // func to divide lists and merge them 
    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists){
        if(start > end)
        return NULL;

        if(start == end) // means only one list is present, so return that
        return lists[start];

        int mid = start + (end - start)/2;

        ListNode* L1 = partitionAndMerge(start, mid, lists); // partition lists from start to mid 
        ListNode* L2 = partitionAndMerge(mid + 1, end, lists); // partition lists from mid + 1 to end

        return mergeTwo(L1, L2); // call function to merge two sorted linked list
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        return partitionAndMerge(0, k-1, lists);
    }
};