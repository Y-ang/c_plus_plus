#include<bits/stdc++.h>
using namespace std;


// vector实现很耗时
// class Solution {
//     static bool cmp (vector<int> a, vector<int> b) { // 该参数是vector向量中数据的类型
//         if (a[0] == b[0]) return a[1] < b[1]; // 先按照身高排序，身高相同的按照人数排序
//         return a[0] > b[0]; 
//     }
// public:
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         // 贪心：先按照身高排序，身高相同的按照人数排序；然后从前到后根据人数插入数据（（k, h）因为前面的都是比自己高的，所以插到第h位置，后面的再向前插也不会影响当前数）
//         vector<vector<int>> res;
//         sort(people.begin(), people.end());
//         for (int i = 0; i < people.size(); i++) {
//             int index = people[i][1];
//             res.insert(res.begin() + index, people[i]); // 在下标为index之前插入元素
//         }
//         return res;
//     }
// };


// vector很耗时，用链表进行操作
class Solution {
    static bool cmp(const vector<int> a, const vector<int> b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 按身高排序
        sort(people.begin(), people.end(), cmp);
        // 按人数插入元素
        list<vector<int>> que;
        for (int i = 0; i < people.size(); i++) {
            int index = people[i][1];
            list<vector<int>>::iterator it = que.begin();   // list插入函数与vector不同，不能随机访问所以不能实现+n操作，需要遍历it，找到插入位置
            while (index--) it++;
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};




int main () {

    return 0;
}