/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);  // 虚拟头节点
        dummyHead->next = head;
        ListNode* right = dummyHead, *left = dummyHead;
        while (n-- && right != nullptr) {  // 可以不加判断，因为条件里有1 <= n <= sz
            right = right->next;
        }
        right = right->next;
        while (right) {
            right = right->next;
            left = left->next;
        }
        ListNode* del = left->next;
        left->next = left->next->next;
        delete del;
        return dummyHead->next;
    }
};
// @lc code=end

