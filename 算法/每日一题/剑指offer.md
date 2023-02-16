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

# 第 5 天 查找算法（中等）

## 剑指 Offer 04*. 二维数组中的查找

在一个 n * m 的二维数组中，每一行都按照从左到右 **非递减** 的顺序排序，每一列都按照从上到下 **非递减** 的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

---

[参考](https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solutions/95306/mian-shi-ti-04-er-wei-shu-zu-zhong-de-cha-zhao-zuo/?orderBy=most_votes)

![Picture1.png](https://pic.leetcode-cn.com/6584ea93812d27112043d203ea90e4b0950117d45e0452d0c630fcb247fbc4af-Picture1.png)

- 必须从左下角，因为万一matrix为空，matrix[0]是不存在的，无法找到j的下标——可以加条件判断

```c++
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] > target) i--;
            else if (matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};
```

```python
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        i = len(matrix) - 1
        j = 0
        while i >= 0 and j < len(matrix[0]):
            if matrix[i][j] > target:
                i -= 1
            elif matrix[i][j] < target:
                j += 1
            else:
                return True
        return False
```

## 剑指 Offer 11*. 旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

给你一个可能存在 **重复** 元素值的数组 `numbers` ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的**最小元素**。例如，数组 `[3,4,5,1,2]` 为 `[1,2,3,4,5]` 的一次旋转，该数组的最小值为 1。 

注意，数组 `[a[0], a[1], a[2], ..., a[n-1]]` 旋转一次 的结果为数组 `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]` 。

---

- 二分查找，在mid等于right值时，让right自减缩小范围

  ```c++
  class Solution {
  public:
      int minArray(vector<int>& numbers) {
          int left = 0, right = numbers.size() - 1;
          while (left < right) {
              int mid = (left + right) / 2;
              if (numbers[mid] > numbers[right]) left = mid + 1;
              else if (numbers[mid] < numbers[right]) right = mid;
              else right--;
          }
          return numbers[left];
      }
  };
  ```

- 二分查找，在mid等于right值时，使用线性查找

  ```python
  class Solution:
      def minArray(self, numbers: List[int]) -> int:
          left = 0
          right = len(numbers) - 1
          while left < right:
              mid = (left + right) // 2
              if numbers[mid] < numbers[right]:
                  right = mid
              elif numbers[mid] > numbers[right]:
                  left = mid + 1
              else:
                  return min(numbers[left:right])
          return numbers[left]
  ```

## 剑指 Offer 50. 第一个只出现一次的字符

在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

---

1. 无序哈希表（数组）+两次遍历字符串

   ```c++
   class Solution {
   public:
       char firstUniqChar(string s) {
           vector<int> dic(26, 0);
           for (int i = 0; i < s.size(); i++) {
               dic[s[i] - 'a']++;
           }
           for (char& c : s) {
               if (dic[c - 'a'] == 1) return c;
           }
           return ' ';
       }
   };
   ```

2. 有序哈希表+一次遍历字符串+一次遍历哈希表

   ——Python 3.6 后，默认字典就是有序的

   ```python
   class Solution:
       def firstUniqChar(self, s: str) -> str:
           dic = {}
           for c in s:
               dic[c] = c not in dic
           for k, v in dic.items():
               if v: return k
           return ' '
   ```

# 第 6 天 搜索与回溯算法（简单）

## 剑指 Offer 32 - I. 从上到下打印二叉树

从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

---

层序遍历

```c++
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                res.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return res;
    }
};
```

```python
class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        res = []
        if not root: return res

        from collections import deque
        que = deque([root])
        while que:
            size = len(que)
            for _ in range(size):
                node = que.popleft()
                res.append(node.val)
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
        return res
```

## 剑指 Offer 32 - II. 从上到下打印二叉树 II

从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

---

和上一题基本相同

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
```

```python
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root: return res

        from collections import deque
        que = deque([root])
        while que:
            size = len(que)
            temp = []
            for _ in range(size):
                node = que.popleft()
                temp.append(node.val)
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
            res.append(temp)
        return res
```

## 剑指 Offer 32 - III. 从上到下打印二叉树 III

请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

---

设置双端队列，判断奇偶层，奇数层正向添加，偶数层逆向添加

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            deque<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (res.size() % 2) {
                    temp.push_front(node->val);
                } else {
                    temp.push_back(node->val);
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(vector<int>(temp.begin(), temp.end()));
        }
        return res;
    }
};
```

```python
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root: return res

        from collections import deque
        que = deque([root])
        while que:
            size = len(que)
            temp = deque()
            for _ in range(size):
                node = que.popleft()
                if len(res) % 2:
                    temp.appendleft(node.val)
                else:
                    temp.append(node.val)
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
            res.append(list(temp))
        return res
```

# 第 7 天 搜索与回溯算法（简单）

## 剑指 Offer 26*. 树的子结构

输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

---

先序遍历：注意 根节点子结构 和 包含子结构 的不同

- 根节点子结构：从根节点开始，A包含B（根节点必须相同或B为空）
- 包含子结构：本题要求的，即根节点不一定相同，可以在左右子树中找到B的结构

```c++
class Solution {
public:
    bool rootSubStructure(TreeNode* A, TreeNode* B) {
        if (!B) return true;
        if (!A || A->val != B->val) return false;
        return rootSubStructure(A->left, B->left) && rootSubStructure(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;  // 特殊情况
        return rootSubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
```

```python
class Solution:
    def rootSub(self, A: TreeNode, B: TreeNode) -> bool:
        if not B:
            return True
        if not A or A.val != B.val:
            return False
        return self.rootSub(A.left, B.left) and self.rootSub(A.right, B.right)
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not A or not B:
            return False
        return self.rootSub(A, B) or self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B)
```

## 剑指 Offer 27. 二叉树的镜像

请完成一个函数，输入一个二叉树，该函数输出它的镜像。

---

- 后序遍历，交换左右节点即可

```c++
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return root;
        mirrorTree(root->left);
        mirrorTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};
```

```python
class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return root
        self.mirrorTree(root.left)
        self.mirrorTree(root.right)
        root.left, root.right = root.right, root.left
        return root
```

## 剑指 Offer 28. 对称的二叉树

请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

---

- 递归后序

```c++
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val == right->val && compare(left->left, right->right) && compare(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return compare(root, root);
    }
};
```

```python
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def compare(p, q):
            if not p and not q:
                return True
            if not p or not q:
                return False
            return p.val == q.val and compare(p.left, q.right) and compare(p.right, q.left)
        return compare(root, root)
```

# 第 8 天 动态规划（简单）

## 剑指 Offer 10- I. 斐波那契数列

写一个函数，输入 `n` ，求斐波那契（Fibonacci）数列的第 `n` 项（即 `F(N)`）。斐波那契数列的定义如下：

```
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
```

斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

---

```c++
class Solution {
public:
    const int MOD = 1e9 + 7;
    int fib(int n) {
        if (n <= 1) return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            int sum = (dp[0] + dp[1]) % MOD;
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};
```

```python
class Solution:
    def fib(self, n: int) -> int:
        if n <= 1: return n
        MOD = 10 ** 9 + 7
        dp = [0, 1]
        for i in range(2, n + 1):
            sumNum = (dp[0] + dp[1]) % MOD
            dp[0] = dp[1]
            dp[1] = sumNum
        return dp[1]
```

## 剑指 Offer 10- II. 青蛙跳台阶问题

一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 `n` 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

---

- dp[i] = dp[i - 1] + dp[i - 2]
- 初始条件：dp[1] = 1, dp[2] = 2
- 规定dp[0] = 1

```c++
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numWays(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        return dp[n];
    }
};
```

```python
class Solution:
    def numWays(self, n: int) -> int:
        MOD = 10 ** 9 + 7
        if n <= 1: return 1
        dp = [0] * (n + 1)
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n + 1):
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD
        return dp[n]
```

## 剑指 Offer 63. 股票的最大利润

假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

---

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[n - 1][1];
    }
};
```

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n == 0: return 0
        dp = [[0, 0] for _ in range(n)]
        dp[0][0] = -prices[0]
        for i in range(1, n):
            dp[i][0] = max(dp[i - 1][0], - prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
        return dp[-1][1]
```

# 第 9 天 动态规划（中等）

## 剑指 Offer 42. 连续子数组的最大和

输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

---

- dp[i]表示下标为i的数字之前（包括自己）的最大子数组和值
- dp[i - 1] + nums[i] < nums[i]时：dp[i] = nums[i]；否则：dp[i] = dp[i - 1] + nums[i]
- 初始值：dp[0] = nums[0]
- 从前往后遍历，记录产生的最大值

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxNum = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dp[i - 1] + nums[i] < nums[i]) dp[i] = nums[i];
            else dp[i] = dp[i - 1] + nums[i];
            maxNum = max(maxNum, dp[i]);
        }
        return maxNum;
    }
};
```

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [0] * (len(nums))
        dp[0] = nums[0]
        res = dp[0]
        for i in range(1, len(nums)):
            dp[i] = max(dp[i - 1] + nums[i], nums[i])
            res = max(res, dp[i])
        return res
```

## 剑指 Offer 47. 礼物的最大价值

在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

---

- `dp[i][j]`表示对应位置能获得的最大收益
- `dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]`
- 初始化：`dp[0][0] = grid[0][0]`，最上行和最左列都是对应值累加
- 从左到右、从上到下遍历

——可以缩减空间，只保留行，加一行最左侧为0填补边界条件

```c++
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j + 1] = max(dp[j], dp[j + 1]) + grid[i][j];
            }
        }
        return dp[n];
    }
};
```

```python
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m == 0: return 0
        n = len(grid[0])
        if n == 0: return 0
        dp = [0] * (n + 1)
        for i in range(m):
            for j in range(n):
                dp[j + 1] = max(dp[j], dp[j + 1]) + grid[i][j]
        return dp[n]
```

# 第 10 天 动态规划（中等）

## 剑指 Offer 46. 把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

---

```c++
class Solution {
public:
    int translateNum(int num) {
        string nums = to_string(num);
        int n = nums.size();
        if (nums.size() <= 1) return n;
        vector<int> dp(n, 0);
        dp[0] = 1;
        int subnum = stoi(nums.substr(0, 2));
        dp[1] = (subnum > 9 && subnum < 26) ? 2 : 1;
        for (int i = 2; i < n; i++) {
            subnum = stoi(nums.substr(i - 1, 2));
            if (subnum > 9 && subnum < 26) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};
// 省空间版
class Solution {
public:
    int translateNum(int num) {
        int a = 1, b = 1;
        int c;
        int temp, x, y = num % 10;
        while (num) {
            num /= 10;
            x = num % 10;
            temp = 10 * x + y;
            c = (9 < temp && temp < 26) ? a + b : a;
            b = a;
            a = c;
            y = x;
        }
        return a;
    }
};
```

```python
class Solution:
    def translateNum(self, num: int) -> int:
        a, b = 1, 1
        y = num % 10
        while num:
            num //= 10
            x = num % 10
            temp = 10 * x + y
            c = (a + b) if 9 < temp < 26 else a
            a, b = c, a
            y = x
        return a
```

## 剑指 Offer 48. 最长不含重复字符的子字符串

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int lastPos, dp = 0;
        int res = 0;
        unordered_map<char, int> pos;
        for (int i = 0; i < s.size(); i++) {
            if (pos.find(s[i]) != pos.end()) lastPos = pos[s[i]];
            else lastPos = -1;
            pos[s[i]] = i;
            dp = i - lastPos > dp ? dp + 1 : i - lastPos;
            res = max(res, dp);
        }
        return res;
    }
};
```

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0: return 0
        dp, res = 1, 1
        pos = {s[0]:0}
        for i in range(1, len(s)):
            if s[i] in pos:
                last = pos[s[i]]
            else:
                last = -1
            pos[s[i]] = i
            dp = dp + 1 if i - last > dp else i - last
            res = max(dp, res)
        return res
```

