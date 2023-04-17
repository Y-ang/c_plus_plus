#include <bits/stdc++.h>
using namespace std;

//使用数组的形式，实现栈的几个操作函数

 typedef struct {
        int stackSize;    /* 栈的大小 */
        char *data;       /* 栈元素数组 */
        int topIdx;       /* 栈顶指针 */
    }SeqStack;


class Stack {
private:
    SeqStack seq;

public:
    /* 创建一个指定大小的栈 */
    SeqStack *Create(int stackSize)
    {
        seq.data = new char[stackSize];
        seq.stackSize = stackSize;
        seq.topIdx = -1;
        return &seq;
    }

    /* 往栈中push一个元素，成功返回0，失败返回-1 */
    int Push(char e)
    { 
        if (seq.topIdx == seq.stackSize - 1) return -1;
        seq.data[++seq.topIdx] = e;
        return 0;
    }

    /* 从栈中pop一个元素，成功返回0，失败返回-1 */
    int Pop( )
    {
        if (seq.topIdx < 0) return -1;
        char res = seq.data[seq.topIdx];
        seq.topIdx--;

        return res;
    }

};

int main() {
    
    Stack st;
    SeqStack vec;
    st.Create(5);
    st.Push('1');
    st.Push('2');
    st.Push('3');
    st.Push('4');
    st.Push('5');

    vector<char> nums(5);
    for (int i = 0; i < 5; ++i) {
        nums[i] = st.Pop();

    }

    for (auto& ch : nums) {
        cout << ch << endl;
    }

    return 0;
}

