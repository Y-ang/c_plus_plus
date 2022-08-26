class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > foundMonotoneStack(vector<int>& nums) {
        // stack保存单调递增序列的下标，一旦出现小于栈顶下标对应元素的元素，则出栈并保存出栈元素的下一个最小值
        // 正反判断两次，则可保存左右下标
        stack<int> st;
      
        vector<vector<int>> res(nums.size(), vector<int>(2, -1));
        for (int i = 0; i <nums.size(); ++i) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                res[st.top()][1] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        
        for (int i = nums.size() -1; i >= 0; --i) {
            while(!st.empty() && nums[i] < nums[st.top()]) {
                res[st.top()][0] = i;
                st.pop();
            }
            st.push(i);
        }
        
        return res;
        
    }
};