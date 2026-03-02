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
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;

        int minVal = INT_MAX, maxVal = INT_MIN;
        for (ListNode * curr = head; curr; curr = curr->next) {
            minVal = min(minVal, curr->val);
            maxVal = max(maxVal, curr->val);
        }

        vector<ListNode*> buckets(maxVal - minVal + 1, nullptr);
        auto bucketsHead = buckets;
        for (ListNode * curr = head; curr;) {
            int ind = curr->val - minVal;
            ListNode * currNext = curr->next;
            curr->next = nullptr;
            if (!buckets[ind]) {
                buckets[ind] = curr;
                bucketsHead[ind] = curr;
            } else {
                buckets[ind]->next = curr;
                buckets[ind] = curr;
            }
            curr = currNext;
        }

        ListNode * ret = nullptr, * retBack = nullptr;
        for (int i = 0; i < (int) buckets.size(); i++) {
            if (!buckets[i]) continue;
            if (!ret) {
                ret = bucketsHead[i];
            } else {
                retBack->next = bucketsHead[i];
            }
            retBack = buckets[i];
        }
        return ret;
    }
};