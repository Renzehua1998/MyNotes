/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {  // 每次递归把当前head头节点和下一个节点调换
        if (head == nullptr) return nullptr;  // 特殊情况
        if (head->next == nullptr) return head;  // 边界条件（递归到最后一个节点）

        ListNode* newHead = reverseList(head->next);  // 调用自己，返回当前头后面链表调转的结果
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
// @lc code=end

