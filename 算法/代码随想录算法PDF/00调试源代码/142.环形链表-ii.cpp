/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        if (!fast) return nullptr;  // 为空的特殊情况
        if (fast->next) {  // 初始化
            slow = slow->next;
            fast = fast->next->next;
        } else {
            return nullptr;
        }
        while (slow != fast) {  // 若相等了，说明有环
            if (fast == nullptr || fast->next == nullptr) {  // 无环
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
// @lc code=end

