class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
     */
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
        // 先按照开始时间进行排序，优先队列保存不同的主持人的结束时间
        // 如果前一个队列中最早结束时间大于当前开始时间（因为开始时间已经排序，所以早结束的完成早开始的主持），
            // 向最小堆中添加新主持人的结束时间，
        // 如果堆中最早结束时间小于当前结束时间，不需要增加主持人，更新该主持人的结束时间
        // 返回优先队列中主持人的人数
        sort(startEnd.begin(), startEnd.end(), [] (const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
        
        priority_queue<int, vector<int>, greater<int>> endQue;  // 小顶堆保存主持人的结束时间
        endQue.push(INT_MIN);
        
        for (auto& se : startEnd) {
            int curStart = se[0];
            int curEnd = se[1];
            if (curStart >= endQue.top()) {   // 队列中主持人的最早结束时间小于当前开始时间，不需要新的主持人
                endQue.pop();  // 主持人主持当前活动
            }
            endQue.push(curEnd);  // 情况一 新增主持人，直接push结束时间；情况二：没有新增主持人，更新主持人的结束时间
        }
            
        return endQue.size();
    }
};