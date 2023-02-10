# 第一天 栈与队列（简单）

## 剑指 Offer 09. 用两个栈实现队列

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 `appendTail` 和 `deleteHead` ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，`deleteHead` 操作返回 -1 )

---

```c++
class CQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    CQueue() {

    }
    
    void appendTail(int value) {
        stIn.push(value);
    }
    
    int deleteHead() {
        if (stIn.empty() && stOut.empty()) return -1;
        if (stOut.empty()) {
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();
        stOut.pop();
        return res;
    }
};
```

```python
class CQueue:

    def __init__(self):
        self.stIn = []
        self.stOut = []

    def appendTail(self, value: int) -> None:
        self.stIn.append(value)

    def deleteHead(self) -> int:
        if not self.stIn and not self.stOut:
            return -1
        if not self.stOut:
            while self.stIn:
                self.stOut.append(self.stIn.pop())
        return self.stOut.pop()
```

## 剑指 Offer 30. 包含min函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

---

辅助栈 B ： 栈 B 中存储栈 A 中所有 非严格降序 的元素，则栈 A 中的最小元素始终对应栈 B 的栈顶元素，即 min() 函数只需返回栈 B 的栈顶元素即可。

```c++
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> A;
    stack<int> B;

    MinStack() {

    }
    
    void push(int x) {
        A.push(x);
        if (B.empty() || x <= B.top()) B.push(x);
    }
    
    void pop() {
        if (A.top() == B.top()) B.pop();
        A.pop();
    }
    
    int top() {
        return A.top();
    }
    
    int min() {
        return B.top();
    }
};
```

```python
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.A = []
        self.B = []

    def push(self, x: int) -> None:
        self.A.append(x)
        if not self.B or self.B[-1] >= x:
            self.B.append(x)

    def pop(self) -> None:
        if self.A[-1] == self.B[-1]:
            self.B.pop()
        self.A.pop()

    def top(self) -> int:
        return self.A[-1]

    def min(self) -> int:
        return self.B[-1]
```

# 第 2 天 链表（简单）

## 剑指 Offer 06. 从尾到头打印链表

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

---

1. 使用递归回溯来反向
2. 先放到栈，再pop
3. 调reverse库
4. 改变链表结构

```c++
class Solution {
public:
    vector<int> res;
    void traversal(ListNode* root) {
        if (!root) return;
        traversal(root->next);
        res.push_back(root->val);
    }
    vector<int> reversePrint(ListNode* head) {
        traversal(head);
        return res;
    }
};
```

```python
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        def traversal(root):
            if not root: return
            traversal(root.next)
            res.append(root.val)
            
        res = []
        traversal(head)
        return res
```

## 剑指 Offer 24. 反转链表

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

---

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
```

```python
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre = None
        cur = head
        while cur:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        return pre
```

## 剑指 Offer 35*. 复杂链表的复制

请实现 `copyRandomList` 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 `next` 指针指向下一个节点，还有一个 `random` 指针指向链表中的任意节点或者 `null`。

---

- *深拷贝*
- **本题难点：** 在复制链表的过程中构建新链表各节点的 `random` 引用指向。

### 哈希表

- （原：新）映射

```c++
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> map;
        Node* cur = head;
        while (cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
};
```

```python
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head: return None
        dic = {}
        cur = head
        while cur:
            dic[cur] = Node(cur.val)
            cur = cur.next
        cur = head
        while cur:
            dic[cur].next = dic.get(cur.next)
            dic[cur].random = dic.get(cur.random)
            cur = cur.next
        return dic[head]
```

### 拼接 + 拆分

```c++
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* cur = head;
        while (cur) {  // 构建串数组
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        cur = head;
        while (cur) {  // 填充random
            if (cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        cur = head->next;
        Node* pre = head, *res = head->next;
        while (cur->next) {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return res;
    }
};
```

```python
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head: return None
        cur = head
        while cur:
            tmp = Node(cur.val)
            tmp.next = cur.next
            cur.next = tmp
            cur = tmp.next
        cur = head
        while cur:
            if cur.random:
                cur.next.random = cur.random.next
            cur = cur.next.next
        cur = head.next
        res = cur
        pre = head
        while cur.next:
            pre.next = pre.next.next
            cur.next = cur.next.next
            pre = pre.next
            cur = cur.next
        pre.next = None
        return res
```

# 第 3 天 字符串（简单）

## 剑指 Offer 05. 替换空格

请实现一个函数，把字符串 `s` 中的每个空格替换成"%20"。

---

- 先统计空格个数，给字符串扩容：加2×空格数
- 双指针法从后往前，遇到空格就换成%20

```c++
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0; // 统计空格个数
        int slen = s.size(); // 字符串原始长度
        for (char c : s) {
            if (c == ' ') {
                count++;
            }
        }
        s.resize(slen + count * 2);  // 重新分配空间
        for (int i = s.size() - 1, j = slen - 1; i > j; i--,j--) {
            if (s[j] == ' ') {
                s[i] = '0';
                s[--i] = '2';
                s[--i] = '%';
            } else {
                s[i] = s[j];
            }
        }
        return s;
    }
};
```

```python
class Solution:
    def replaceSpace(self, s: str) -> str:
        count = s.count(' ')
        res = list(s)
        res.extend(' ' * count * 2)
        slow = len(s) - 1
        fast = len(res) - 1
        while slow >= 0:
            if s[slow] != ' ':
                res[fast] = s[slow]
                fast -= 1
                slow -= 1
            else:
                res[fast - 2 : fast + 1] = '%20'
                fast -= 3
                slow -= 1
        return ''.join(res) 
```

## 剑指 Offer 58 - II. 左旋转字符串

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

---

1. 三次反转

```c++
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
```

```python
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        s = s[:n][::-1] + s[n:]
        s = s[:n]+ s[n:][::-1]
        s = s[::-1]
        return s
```

2. 拼接+截取（一行）

```c++
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return (s + s).substr(n, s.size());
    }
};
```

```python
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return (s + s)[n : len(s) + n]
```

# 第 4 天 查找算法（简单）

## 剑指 Offer 03. 数组中重复的数字

找出数组中重复的数字。
 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

---

1. 一个萝卜一个坑：重头扫描数组，遇到下标为i的数字如果不是i的话，（假设为m),那么我们就拿与下标m的数字交换。在交换过程中，如果有重复的数字发生，那么终止返回ture

   ```c++
   class Solution {
   public:
       int findRepeatNumber(vector<int>& nums) {
           for (int i = 0; i < nums.size(); i++) {
               while (nums[i] != i) {
                   if (nums[i] == nums[nums[i]]) return nums[i];
                   int temp = nums[i];
                   nums[i] = nums[temp];
                   nums[temp] = temp;
               }
           }
           return -1;
       }
   };
   ```

   ```python
   class Solution:
       def findRepeatNumber(self, nums: List[int]) -> int:
           for i in range(len(nums)):
               while nums[i] != i:
                   if nums[i] == nums[nums[i]]:
                       return nums[i]
                   temp = nums[i]
                   nums[i] = nums[temp]
                   nums[temp] = temp
           return -1
   ```

2. 哈希表（略）

## 剑指 Offer 53* - I. 在排序数组中查找数字 I

统计一个数字在排序数组中出现的次数。

-- -

- 二分查找（分布查左边界和右边界）

```c++
class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target) - binarySearch(nums, target - 1);
    }
};
```

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binarySearch(target):
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] <= target:
                    left = mid + 1
                else:
                    right = mid - 1
            return left
        return binarySearch(target) - binarySearch(target - 1)
```

## 剑指 Offer 53 - II. 0～n-1中缺失的数字

一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

---

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == mid) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};
```

```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] == mid:
                left = mid + 1
            else:
                right = mid
        return left
```

