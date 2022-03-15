#include<bits/stdc++.h>
using namespace std;

// class Solution {
// private:
//     unordered_map<string, int> ticketNumMap;  // 同一个地方的机票的个数
//     unordered_map<string, set<string>> ticketMap;  // 机票的始终点
// public:
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
        
//         for (auto ticket : tickets) {
//             if (ticketNumMap.find(ticket[0] + ticket[1]) == ticketNumMap.end()){
//                 ticketNumMap[ticket[0] + ticket[1]] = 1;
//             } else {
//                 ticketNumMap[ticket[0] + ticket[1]]++;
//             }
//             ticketMap[ticket[0]].insert(ticket[1]);
//         }
//         vector<string> res;
//         vector<string> path = {"JFK"};
//         backtracking("JFK", path, res);
//         return res;
//     } //["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]
//     void backtracking(string cur, vector<string> path, vector<string>& res) {
//         if (ticketNumMap.size() == 0) {
//             res = path;
//             return;
//         }
//         if (ticketMap.find(cur) == ticketMap.end()) {
//             return;
//         }
//         for (auto city : ticketMap[cur]) {
//             if (ticketNumMap.find(cur + city) == ticketNumMap.end()) continue;
//             ticketNumMap[cur + city]--; //机票数自减
//             if (ticketNumMap[cur + city] == 0) ticketNumMap.erase(cur+city);

//             path.push_back(city);
//             backtracking(city, path, res);

//             //回溯
//             path.pop_back();

//             if (ticketNumMap.find(cur + city) == ticketNumMap.end()) {
//                 ticketNumMap[cur + city] = 1; 
//             } else {
//                 ticketNumMap[cur + city]++;
//             }

//             if (!res.empty()) {
//                 return;
//             }

//         }
//     }
// };


// 方法二：数据结构map<string, map<string, int>> ticketMap
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int ticketNum = 0;
        map<string, map<string, int>> ticketMap;
        vector<string> res = {"JFK"}; // 起始机场
        for (auto ticket : tickets) {
            ticketNum++;  // 保存总机票的张数
            ticketMap[ticket[0]][ticket[1]]++; //保存机票的对应关系
        }
        backtracking(ticketNum, "JFK", ticketMap, res);
        return res;
    }//["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]
    bool backtracking(int ticketNum, string preAirport, map<string, map<string, int>>& ticketMap, vector<string>& res) {
        if (ticketNum == 0) {
            // 该路线满足直接返回
            return true;
        }
        // 遍历前一个机场起飞的所有机票
        for (auto& cur : ticketMap[preAirport]) {  //需要加上引用&，不然无法修改ticketMap的值
            string curAirport = cur.first;
            if (cur.second == 0) continue;  // 机票已用完，遍历该从pre机场起飞的下一张机票
            cur.second--;
            res.push_back(curAirport);
            if(backtracking(ticketNum - 1, curAirport, ticketMap, res)) return true;
            res.pop_back();
            cur.second++;
        }
        return false;  //该机场没有合适的机票
    }
};

int main() {
    Solution su;
    vector<vector<string>> tickets = {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    su.findItinerary(tickets);
    return 0;
}