/*
 * Problem: Merge k sorted Lists (#23)
 * Difficulty: Hard
 * Topic: LinkedList
 * Link: https://leetcode.com/problems/merge-k-sorted-lists/
 *
 * Time Complexity:  O(k log k)
 * Space Complexity: O(k)
 *
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        ListNode* ans = new ListNode(-1);
        ListNode* iter = ans;
        int k = lists.size();
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr)
                pq.push(lists[i]);
        }
        while (!pq.empty()) {
            ListNode* node = pq.top();
            iter->next = new ListNode(node->val);
            pq.pop();
            iter = iter->next;
            if (node->next) {
                pq.push(node->next);
            }
        }
        return ans->next;
    }
};