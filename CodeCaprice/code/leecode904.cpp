#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0;
        int subLength = 0;
        int maxLength = 0;
        set<int> subfruits;
        for(int end = 0; end < fruits.size(); end++){
            subfruits.insert(fruits[end]);
            if(subfruits.size() <= 2){
                subLength = end - start + 1;
                maxLength = maxLength > subLength ? maxLength : subLength;
            }else{
                start = end - 1;
                int tmp = fruits[start];
                while(fruits[start - 1] == tmp){
                    start--;
                }
                subfruits.erase(fruits[start - 1]);
            }
        }
        return maxLength;
    }
    
};


int main(){
    Solution su;
    vector<int> arr = {1,0,1,4,1,4,1,2,3};
    int num = su.totalFruit(arr);
    cout << num;
    return 0;
}