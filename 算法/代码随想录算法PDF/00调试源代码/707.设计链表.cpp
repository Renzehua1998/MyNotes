/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    // 链表节点
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    // 初始化链表
    MyLinkedList() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }
    
    // 获取对应下标节点值
    int get(int index) {  // 注意判断，从0开始size是开区间，index==size也是超界
        if (index < 0 || index >= _size) return -1;
        ListNode* cur = _dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    // 头部加
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = _dummyHead->next;
        _dummyHead->next = node;
        _size++;
    }
    // 尾部加
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = node;
        _size++;
    }
    // 中间加
    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;
        ListNode* node = new ListNode(val);
        ListNode* cur  = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        _size++;
    }
    // 中间删
    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size) return;
        ListNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        ListNode* del = cur->next;
        cur->next = cur->next->next;
        delete del;
        _size--;
    }
private: 
    int _size;
    ListNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

