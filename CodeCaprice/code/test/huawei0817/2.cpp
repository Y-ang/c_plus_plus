
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: 考生实现代码
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include <iostream>
#include <string>
using namespace std;

class MiniMemoryPool {
private:
    vector<int> resource;
    map<int, int> used;  // 保存已经使用的内存的开始地址和大小

    // map<int, int> unused; // 保存内存池从当前位置开始，往后可使用的内存大小
public:
    MiniMemoryPool () {
        
        for (int i = 0; i < 100; ++i) {
            resource[i] = 100 - i;
        }
    }

    // 返回分配的内存首地址,失败返回 -1
    int Request(int size)
    {
        for (int i = 0; i < resource.size(); ++i) {
            if (resource[i] >= size) {
                for (int j = i; j < i + size; ++j) {
                    resource[j] = 0;
                }
                // 标记一使用
                used[i] = size;
                return i;
            }
        }
       
        return -1;
    }
  10 9 8 7 6 5 4 3 2 1
4 3 2 1 
    // 释放内存地址, 成功返回 true, 失败返回 false
    bool Release(int startAddr)
    {
        if (used[startAddr] == used.endl()) return false;
        int index = 0;
        for (int i = startAddr; i < used[startAddr]; ++i) {
            resource[i] = used[startAddr] - index;
            index++;
        }
        used.erase(pair<int, int>{startAddr, used[startAddr]});

        return true;
    }
};

int main()
{
    int num;
    cin >> num;

    MiniMemoryPool pool;
    for (int loop = 0; loop < num; loop++) {
        string line;
        cin >> line;

        string commond = line.substr(0, line.find_first_of('='));
        if (commond == "REQUEST") {
            int size = stoi(line.substr(line.find_first_of('=')+1));
            int result = pool.Request(size);
            if (result != -1) {
                cout << result << endl;
            } else {
                cout << "error" << endl;
            }
        } else if (commond == "RELEASE") {
            int addr = stoi(line.substr(line.find_first_of('=')+1));
            if (!pool.Release(addr)) {
                cout << "error" << endl;
            }
        }
    }

    return 0;
}
对:
