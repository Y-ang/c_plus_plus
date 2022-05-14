#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   static bool cmp(const vector<int> a, const vector<int> b) {
      return a[0] < b[0];
   }

   int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
      int n = tiles.size();
      if (!n)
         return 0;
      sort(tiles.begin(), tiles.end(), cmp);
      vector<int> sum(n, 0);
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
         cnt += tiles[i][1] - tiles[i][0] + 1;
         sum[i] = cnt;
      }
      int left = 0, right = 0;
      int ans = INT_MIN;
      while (left < n && right < n) {
         int temp = tiles[right][1] - tiles[left][0] + 1;
         if (temp <= carpetLen) {
            if (left > 0)
               ans = max(ans, sum[right] - sum[left - 1]);
            else
               ans = max(ans, sum[right]);
            right++;
         } else if (temp > carpetLen) {
            left++;
         }
         if (left > right)
            right = left;
      }
      ans = max(ans, sum[right] - sum[left - 1]);
      return ans;
   }
};

int main() {
   Solution solution;
   vector<vector<int>> tiles = {
      {1,5},{10,11},{12,18},{20,25},{30,32}
   };
//    int carpetLen = 10;
   // vector<vector<int>> tiles = {
   //    {10,11},{1,1}
   // };
   // int carpetLen = 10;
   // vector<vector<int>> tiles = {
   //    {3745,3757},{3663,3681},{3593,3605},{3890,3903},{3529,3539},{3684,3686},{3023,3026},{2551,2569},{3776,3789},{3243,3256},{3477,3497},{2650,2654},{2264,2266},{2582,2599},{2846,2863},{2346,2364},{3839,3842},{3926,3935},{2995,3012},{3152,3167},{4133,4134},{4048,4058},{3719,3730},{2498,2510},{2277,2295},{4117,4128},{3043,3054},{3394,3402},{3921,3924},{3500,3514},{2789,2808},{3291,3294},{2873,2881},{2760,2760},{3349,3362},{2888,2899},{3802,3822},{3540,3542},{3128,3142},{2617,2632},{3979,3994},{2780,2781},{3213,3233},{3099,3113},{3646,3651},{3956,3963},{2674,2691},{3860,3873},{3363,3370},{2727,2737},{2
   int carpetLen = 10;
   // vector<vector<int>> tiles = {
   //    {10,11},{1,1}
   // };
   // int carpetLen = 10;
   // vector<vector<int>> tiles = {
   //    {3745,3757},{3663,3681},{3593,3605},{3890,3903},{3529,3539},{3684,3686},{3023,3026},{2551,2569},{3776,3789},{3243,3256},{3477,3497},{2650,2654},{2264,2266},{2582,2599},{2846,2863},{2346,2364},{3839,3842},{3926,3935},{2995,3012},{3152,3167},{4133,4134},{4048,4058},{3719,3730},{2498,2510},{2277,2295},{4117,4128},{3043,3054},{3394,3402},{3921,3924},{3500,3514},{2789,2808},{3291,3294},{2873,2881},{2760,2760},{3349,3362},{2888,2899},{3802,3822},{3540,3542},{3128,3142},{2617,2632},{3979,3994},{2780,2781},{3213,3233},{3099,3113},{3646,3651},{3956,3963},{2674,2691},{3860,3873},{3363,3370},{2727,2737},{2


// #include <bits/stdc++.h>
// using namespace std;


// class Solution {
// public:
//     static bool cmp (vector<int>& a, vector<int>& b) {
//         if (a[0] == b[0]) return a[1] < b[1];
//         else return a[0] < b[0];
//     }
//     int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
//         sort(tiles.begin(), tiles.end(), cmp);
//         int startIndex = tiles[0][0];
//         int endIndex = tiles[0][1];
//         int maxLen = endIndex - startIndex + 1;
//         cout << maxLen << endl;
//         // if (maxLen >= carpetLen) return carpetLen;
//         int left = tiles[0][0];
//         int right = left;
//         int ans = 0;
//         int tmp = 0;
//         for (int i = 0; i < tiles.size(); ++i) {
//             if (right - left + 1 < carpetLen && tiles[i][0] < left + carpetLen) {
//                 right = tiles[i][0];
//                 while (right <= tiles[i][1] && tiles[i][1] < left + carpetLen) {
//                     tmp++;
//                     right++;
//                 }
//                 if (tmp > ans) ans = tmp;
//             } else if (right - left + 1 >= carpetLen)
//             if (right - left + 1 > carpetLen) {
//                 left = tiles[i][0];
//                 right = left;
//             }
//         }
//         return maxLen < carpetLen ? maxLen : carpetLen; 
//     }
// };


// /* 
// {7917,7925} 7930,7950 {7969,7987} {7994,7995} {8003,8011}
//  */

// int main() {
//     vector<vector<int>> nums = {{8051,8057},{8074,8089},{7994,7995},{7969,7987},{8013,8020},{8123,8139},{7930,7950},{8096,8104},{7917,7925},{8027,8035},{8003,8011}};
//     Solution su;
//     int res = su.maximumWhiteTiles(nums, 9854);
//     cout << res ;
//     return 0;
// }
