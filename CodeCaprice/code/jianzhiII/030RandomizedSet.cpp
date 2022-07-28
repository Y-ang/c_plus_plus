class RandomizedSet {
    /*
    对于 getRandom 方法，如果想「等概率」且「在 O(1) 的时间」取出元素，一定要满足：底层用数组实现，且数组必须是紧凑的。

    这样我们就可以直接生成随机数作为索引，从数组中取出该随机索引对应的元素，作为随机元素。

    但如果用数组存储元素的话，插入，删除的时间复杂度怎么可能是 O(1) 呢？可以做到！对数组尾部进行插入和删除操作不会涉及数据搬移，时间复杂度是 O(1)。

    所以，如果我们想在 O(1) 的时间删除数组中的某一个元素 val，可以先把这个元素交换到数组的尾部，然后再 pop 掉。
    */
private:
    vector<int> nums;  // 存储元素值
    unordered_map<int, int> valToIndex; // 存储元素值和元素下标之间的映射关系，即索引
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        nums = {};
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            return false;
        }
        // 将需要删除的元素交换到数组末尾
        int index = valToIndex[val];   // 记录最后一个元素值和带交换位置
        valToIndex[nums.back()] = index;   // 添加新索引
        swap(nums[index], nums.back()); // 交换
        nums.pop_back();              // 删除元素和索引
        valToIndex.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % (nums.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */