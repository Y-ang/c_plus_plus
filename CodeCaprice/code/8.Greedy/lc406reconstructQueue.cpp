#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp (vector<int> a, vector<int> b) { // 该参数是vector向量中数据的类型
        if (a[0] == b[0]) return a[1] < b[1]; // 先按照身高排序，身高相同的按照人数排序
        return a[0] > b[0]; 
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 贪心：先按照身高排序，身高相同的按照人数排序；然后从前到后根据人数插入数据（（k, h）因为前面的都是比自己高的，所以插到第h位置，后面的再向前插也不会影响当前数）
        vector<vector<int>> res;
        sort(people.begin(), people.end());
        for (int i = 0; i < people.size(); i++) {
            int index = people[i][1];
            res.insert(res.begin() + index, people[i]); // 在下标为index之前插入元素
        }
        return res;
    }
};


// vector很耗时，用链表进行操作



int main () {

    return 0;
}