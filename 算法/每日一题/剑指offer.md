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

