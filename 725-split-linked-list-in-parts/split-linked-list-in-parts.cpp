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
    int getLength(ListNode *head) {
        int len = 0;
        while (head != nullptr) {
            len += 1;
            head = head->next;
        }
        return len;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int totalLength = getLength(head);
        int partSize = totalLength / k;
        int remainder = totalLength % k;

        vector<ListNode*> result(k, nullptr);
        ListNode* current = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < k; ++i) {
            result[i] = current;
            int currentPartSize = partSize + (remainder > 0 ? 1 : 0);
            remainder--;

            for (int j = 0; j < currentPartSize; ++j) {
                if (current != nullptr) {
                    prev = current;
                    current = current->next;
                }
            }

            if (prev != nullptr) {
                prev->next = nullptr;
            }
        }

        return result;
    }
};