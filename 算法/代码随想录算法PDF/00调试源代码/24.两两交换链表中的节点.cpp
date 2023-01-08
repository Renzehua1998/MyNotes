/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next && cur->next->next) {  // 满足迭代条件
            ListNode* temp1 = cur->next;  // 临时变量保存后两个节点指针
            ListNode* temp2 = cur->next->next->next;
            // 开始交换
            cur->next = cur->next->next;
            cur->next->next = temp1;
            temp1->next = temp2;
            // 更新cur
            cur = cur->next->next;
        }
        head = dummyHead->next;  // 释放虚拟头节点
        delete dummyHead;
        return head;
    }
};
// @lc code=end

