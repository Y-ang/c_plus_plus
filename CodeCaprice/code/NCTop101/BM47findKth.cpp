#include<bits/stdc++.h>
using namespace std;


// // 法一：快排
// class Solution {
// public:
//     int findKth(vector<int> a, int n, int K) {
//         return quickSort(a, 0, n - 1, K - 1);  // K-1表示下标
//     }
//     int quickSort(vector<int>& a, int left, int right, int K) {
//         if (left >= right) return a[left];
//         // 随机选择一个数作为划分值
//         srand((int)time(NULL));
//         int randIndex = rand() % (right - left + 1) + left;
//         swap(a[randIndex], a[right]);
//         vector<int> index(2);
//         index = partition(left, right, a);  // 划分值的位置
//         if (index[0] <= K && index[1] >= K) {
//             return a[index[0]];
//         } else if (index[1] < K){
//             left = index[1] + 1;
//         } else if (index[0] > K){
//             right = index[0] - 1;
//         }
//         return quickSort(a, left, right, K);
//     }
//     vector<int> partition(int left, int right, vector<int>& a) {
//         int more = left - 1;
//         int less = right;
//         while (left < less) {
//             if (a[left] < a[right]) {
//                 swap(a[--less], a[left]);
//             } else if (a[left] > a[right]) {
//                 swap(a[++more], a[left++]);
//             } else {
//                 left++;
//             }
//         }
//         swap(a[less], a[right]);
//         return vector<int>({more + 1, less});
//     }
// };


// // 法二：优先队列
// class Solution {
// public:
//     int findKth(vector<int> a, int n, int K) {
//         priority_queue<int, vector<int>, greater<int>> priQue;
//         for (int i = 0; i < n; ++i) {
//             priQue.push(a[i]);
//             if (priQue.size() > K) priQue.pop();
//         }
//         return priQue.top();
//     }
// };

// 堆排序
class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        int heapSize = n;
        // log(n)
        for (int i = n - 1; i >= 0; --i) {
            heapify(i, heapSize, a);   // 建立大根堆
        }
        // klog(n)
        swap(a[--heapSize], a[0]);
        while (--K) {
            heapify(0, heapSize, a);
            swap(a[--heapSize], a[0]);
        }
        return a[heapSize];
    }
    void heapify(int index, int heapSize, vector<int>& nums) {
        int left = 2 * index + 1;
        while (left < heapSize) {
            int largest = left + 1 < heapSize && nums[left + 1] > nums[left] ?
                            left + 1 :
                            left;
            if (nums[index] > nums[largest]) break;  // 根节点较大，不再往下遍历
            swap(nums[index], nums[largest]);
            index = largest;
            left = 2 * index + 1;
        }
    }
};
int main () {
    Solution su;
    vector<int> a = {13,11,5,6,12,13,5};
    su.findKth(a, 7, 4);
    return 0;
}