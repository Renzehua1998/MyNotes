/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int head = 0; // 窗口头指针
        int next = 0; // 指示下一个窗口开头的指针
        int basket1 = fruits[0];  // 第一个篮子放上一个果树的种类
        int basket2 = -1; // 第二个篮子放另外一个果树的种类
        int num = 0; // 最多摘水果数目
        for (int i = 0; i < fruits.size(); i++) { // 遍历果树
            if (fruits[i] == basket1) continue; // 此果树和上一个果树种类相同，pass，继续下一个
            if (fruits[i] != basket2 && basket2 != -1) {
                // 出现了第三种果树类型，需要更新窗口，使用上一个窗口的长度更新num
                // 注意此处basket2 != -1是为了防止刚开头第二种水果出现时basket2还为初始值-1，此时不应当更新窗口
                num = i - head > num ? i - head : num;
                head = next;  // 下一个窗口从next部分开始
            }
            // 出现和上一个不同的果树，需要更新果篮和next
            basket2 = basket1;
            basket1 = fruits[i];  // 篮子1始终存放上一个果树的种类
            next = i;  // 下次若更新窗口，头指针从此处开始
        }
        // 更新最后一个窗口的长度
        num = fruits.size() - head > num ? fruits.size() - head : num;
        return num;
    }
};
// @lc code=end

