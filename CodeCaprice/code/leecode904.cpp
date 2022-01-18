#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0;
        int subLength = 0;
        int maxLength = 0;
        queue<int> subfruits;
        for(int end = 0; end < fruits.size(); end++){
            insertFruit(fruits[end], subfruits);
            int tmp = subfruits.front();
            subLength = end - start + 1;
            maxLength = maxLength > subLength ? maxLength : subLength;
            if (subfruits.size() == 3){
                tmp = subfruits.front();
                subfruits.pop();
            }
            while (subfruits.size() == 3){
                while(fruits[start] == tmp){
                    start++;
                }
            }            
        }
        return maxLength;
    }
    void insertFruit(int target, queue<int>& nums){
        if(!nums.empty() && (nums.front() == target || nums.back() == target)){
            return;
        }
        nums.push(target);
        return;
    }
};


int main(){
    Solution su;
    vector<int> arr = {1, 2, 1};
    int num = su.totalFruit(arr);
    cout << num;
    return 0;
}