class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // // 优先队列
        // priority_queue<int, vector<int>, greater<int>> priQue;
        // for (int i = 0; i < nums.size(); ++i) {
        //     priQue.push(nums[i]);
        //     if (priQue.size() > k) priQue.pop();
        // }
        // return priQue.top();

        // 堆排序
        // log(n)  从后向前，每个节点adjustDown建立大根堆
        int heapSize = nums.size();
        for (int i = heapSize - 1; i >= 0; --i) {
            heapify(i, heapSize, nums);   
        }
        // klog(n) 建立k个大根堆，每次堆顶元素就是第i大元素
        swap(nums[0], nums[--heapSize]);
        while (--k) {
            heapify(0, heapSize, nums);
            swap(nums[0], nums[--heapSize]);
        }
        return nums[heapSize];
    }
    void heapify(int index, int heapSize, vector<int>& nums) {
        int left = index * 2 + 1;
        while (left < heapSize) {
            int largest = left + 1 < heapSize && nums[left + 1] > nums[left]
                            ? left + 1
                            : left;
            if (nums[index] > nums[largest]) break;
            swap(nums[index], nums[largest]);
            index = largest;
            left = index * 2 + 1;
        }
    }
};