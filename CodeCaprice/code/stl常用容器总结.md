# 容器分类

- 顺序式容器
  - vector：动态数组
    - 从**尾部**可以快速插入和删除
    - **直接访问**元素
  - list：双链表
    - 从**任何地方**快速插入和删除
  - deque：双向队列
    - 从**前面或者后面**快速插入和删除
    - **直接访问**任何元素
  - queue：队列
    - **先进先出**
  - priority_queue：优先队列
    - 每次只能取出**最高优先级**元素
  - stack：栈
    - **后进先出**
- 关联式容器
  - set：集合
    - 不允许重复值
  - multiset：多元集合
    - 允许重复值
  - map：一对多映射
    - 基于**关键字**快速查找
    - 不允许重复值
  - multimap：一对多映射
    - 基于**关键字**快速查找
    - 允许重复值

# vector

- 定义
  - vector<int> a：定义一个 a 向量
  - vector<int> a ( b )：用 b 向量定义 a 向量
  - vector<int> a ( 100， 0)：定义 a 向量，并用 0 来初始化
  - vector<vector<int>> a (4, vector<int> ( 5, 0) )：定义一个二维向量，维数分别是4 和 5，并且都用 0 来初始化
  - **vector<vector<vector<int>>> a(4, vector<vector<int>>(5, vector<int>(6, 0)))：定义一个三维向量，维数分别为4，5，6，并且都用 0 来初始化**
- 常用操作
  - 操作分类
    - 通用操作：size()  empty() 	
    - 非通用操作(按使用频率排序)：push_back()  pop_back()  sort()  clear()  reverse() insert()  erase()  remove() resize()  
  - 注意：
    - sort  reverse  remove函数是 **algorithm 头文件里面的**，**不是 vector 容器的函数**
    - **remove 和 erase 函数区别**：
      - `remove` 是 `algorithm` 头文件函数，`erase` 是 `vector` 的函数：`remove(val)    a.erase(pos)`
      - `remove` 传入的是元素值，`erase` 传入的是位置（或者位置区间）
  - ![image.png](https://upload-images.jianshu.io/upload_images/23971463-d7ced673d6a6523b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

# list

- 基本介绍
  - 数据结构是双向链表，内存空间占用不连续，用指针进行数据访问，适用于删除和插入（常数级复杂度）
  - 与`vector`相反
    - `vector`:：适用于插入与删除操作少，随机访问多
    - `list`：适用于随机访问少，插入与删除多
- 有关操作
  - 通用操作：`size()  empty()`
  - 不通用操作：
    - `push_back`()：向 `list` 容器最后一个元素后添加新元素；
    - `push_front`()：向 `list` 容器首个元素前添加新元素；
    - `clear`()：清空所有元素
    - 初始化赋值：`list<int> values{1, 2, 3}`
    - 位置迭代器：【注意，返回的是迭代器，不是元素，不能直接访问，**得用 * 符号**】
      - `begin()`：第一个元素的位置**迭代器**，可以访问
      
      - `end()`：末尾元素的后面位置**迭代器**，不可以访问
      
      - ```C++
        list<int> values{1, 2, 3};
        cout << *(values.begin()) << endl;  // 输出1
        cout << *(values.end()--) << endl;  // 输出3，不可以用 -1,只能用自减符
        ```
      
        

# stack

- 有关操作
  - 操作分类
    - 通用操作：size()  empty()
    - 非通用操作(按使用频率排序)：push()  pop()  top()
  - ![image-20220216223755934](https://www.codechicken.asia/img/image-20220216223755934.png)

# queue

- 有关操作
  - 操作分类
    - 通用操作：size()  empty()
    - 非通用操作：push()  pop()  front()  back()
  - ![image-20220216223849483](https://www.codechicken.asia/img/image-20220216223849483.png)
  - ![image-20220216223951615](https://www.codechicken.asia/img/image-20220216223951615.png)

# priority_queue

- 有关操作

  - 操作分类：
    - 通用操作：size()   empty()
    - 非通用操作：push()  pop()  top()【**注意不是front，注意与 queue 区分开来**】
  - ![image-20220216224156563](https://www.codechicken.asia/img/image-20220216224156563.png)

- 自定义优先级

  - 原理解释

    - 优先队列priority_queue<,,>,实际上有**三个参数**：
    - 第一个就是你要插入的类`type`，比如`int`，`char`什么的
      - 第二个是选择容纳元素的容器 `container<type>`，这里的`type`就是第一个参数, 该容器默认为`vector`
    - 第三个是比较器
  
- 我们通常用的只需要输入第一个参数，后面都是默认的；实际上完整的是 **priority_queue<类型，vector<类型>，less<类型> >**
  
- 结构体 自定义优先级的两种方式：
  
  - 在结构体外面**用类或者结构体定义cmp**，重构半圆括号（）【**建议使用**】
  
      - ```c++
        struct node
        {
            int to,cost;
            node(int x1, int x2)
            {
                to = x1;
                cost = x2;
            }
            // 上面的构造函数可以用下面的方式写，更简洁
            // node(int x1, int x2): to(x1), cost(x2) {}
        };
        struct cmp
        {
            // !!! 注意重载的是半圆括号()，不是小于号<
            bool operator() (const node &a,const node &b)
            {
                return a.cost > b.cost;  // 大于号 >> 升序排序(与sort函数相反)
            }
        };
        priority_queue<node,vector<node>,cmp> priq;
        ```
  
  - 在结构体里面重构小于号 <  
  
       - ```c++
         struct node
              {
                  int to,cost;
                  node(int x1,int x2)
                  {
                      to = x1;
                      cost = x2;
                  }
                  // 上面的构造函数可以用下面的方式写，更简洁
                  // node(int x1, int x2): to(x1), cost(x2) {}
                  friend bool operator<(const node &a , const node &b)
                  {
                      return a.cost > b.cost;   // 大于号 >> 升序排序(与sort函数相反)
                  }
          };
          priority_queue<node> priq;
      ```
    
  
- 基本类型 自定义优先级
  
  - 定义比较函数`cmp`  【**建议使用**】
  
    - 因为优先队列模板是有三个参数，后两个是两个默认参数，所以按c++语法规则：如果你要显式地重新定义第三个参数，则**第二个参数也必须被显式指明**
  
      - ```C++
        struct cmp
        {
            bool operator() (const int &a, const int &b)
            {
                //因为优先出列判定为!cmp，所以反向定义实现最小值优先出列
                return a > b;  // 大于号 >> 升序排序(与sort函数相反)
            }
        };
        
        //创建队列的时候,三个参数都要显示地指明
        priority_queue<int, vector<int>, cmp> Q;
        ```
        
      
    - 使用内置的比较函数 less<type>()  greater<type>()
    
    - 默认使用的是`less<type>` (),  从大到小排序（和 sort 函数相反），使用 `top`函数输出最大（也就是优先级高的）的元素
      - 使用 `greater<type>`()，从小到大排序，使用`top`函数输出最小（优先级最低的）的元素

# set

- 基本介绍
  - **二叉搜索树**实现的，集合中每个元素只能出现一次，并且是排好序的
  - 访问、查找、删除的复杂度都是 `O(logn)`
- 有关操作
  - 通用操作：`size()  empty()`
  - 非通用操作：
    - `st.insert(val)：` 插入元素 `val`
    - `st.erase(val):`   插入元素 `val`
    - `st.find(val)：`查找元素`val`，返回**位置迭代器**，**找不到返回 `end()`**
    - `st.begin()，st.end()：`位置迭代器，遍历时用
  - `st.upper_bound(k), st.lower_bound(k)`: 二分查找
      - **upper_bound(k)** 返回**大于 k** 的第一个元素
      - **lower_bound(k)** 返回**大于等于k** 的第一个元素
  
- 注意：`set`的`erase`函数和`vector`的`erase`的区别
  - `set.erase(val)`  传入的是元素值
  - `vector.erase(pos)`  传入的是位置（或者位置区间）

- 自定义排序方式
  
  - 定义比较函数`cmp`  【**建议使用**】
  
    - ```c++
      //定义函数对象模板类
      template <typename T>
      struct cmp {
          //重载 () 运算符
          bool operator ()(const T &a, const T &b) {
              //按照值的大小，做升序排序, 从小到大
              return  a < b;
          }
      };
      set<T, cmp>myset {value1, value2};
      ```

# multiset

与 `set` 区别在于允许重复值

# map

- 基本介绍

  - 数据结构是**红黑树**,类似于哈希表,由键值对组成
  - `map<string, int> student;`  存储学生的 `name` 和 `id`

- 有关操作

  - 通用操作: size()  empty()

  - 非通用操作:

    - 初始化: 用**键值对**初始化

      - ```C++
        map<string, int> student = {
                // 键值对
                {"wang", 1},
                {"zhang", 2}
            };
        ```

        

    - 插入:

      - [] = :  【**建议使用**】

        - ```c++
          student["yang"] = 4;
          ```

      - insert:

        - ```c++
          student.insert({"li", 3});   // 推荐使用
          student.insert(pair<string, int>("lii", 3));
          ```

    - `find(key):` 在`map`中 查找 关键字等于 `key`的元素,返回位置迭代器,找不到返回 `end()`

    - `clear`(): 清空所有元素

    - `erase()`

      - `map.erase(key):`  【**建议使用**】

        - 删除 关键字等于 key的元素 , **删除成功返回 1, 失败返回 0**

      - `map.erase(pos)`:

        - ```C++
          cout << student.size() << endl;  // 输出 5
          map<string, int>::iterator iter = student.find("li");
          student.erase(iter);            /// 可以合并写成 student.erase(student.find("li")); 
                                          /// 但是存在问题, 如果找不到“li"，find 返回 end()，这时候erase(map::end())会报错, 正确做法是erase之前,先判断是否为end()
          cout << student.size() << endl; // 输出 4
          ```

    - `map.upper_bound(key), map.lower_bound(key)`: 二分查找

      - **upper_bound(key)** 返回**关键字大于 key** 的第一个元素**位置迭代器**
      - **lower_bound(key)** 返回**关键字大于等于key**的第一个元素**位置迭代器**

- 自定义排序方式

  - 定义比较函数`cmp`  【**建议使用**】

    - ```c++
      //注意 operator是(),不是＜
      struct cmp
      {
          bool operator () (IntPlus const &a,IntPlus const &b)
          {
              if(a.num != b.num)		// 优先用 num 从小到大排序
                  return a.num < b.num;
              else return a.i < b.i;	// 其次再用 i 从小到大排序
          }
      };
      ```

      

# mutlimap

与 `mutlimap` 区别在于允许重复**关键字**

# stl 容器 两个常用函数

## sort 函数

- 定义

  - `void sort(first_pos, end_pos);`
  - `void sort(first_pos, end_pos, cmp);`
  - 复杂度: `O(nlogn)`
  - 注意: 排序范围是 **[first_pos, end_pos)**,  **左闭右开**

- 使用

  - 对 `vector`: 
    - `sort(vector.begin(), vector.end())`
  - 对 数组
    - `sort(array, array + n)` 对[array[0] ,  array[n-1]] 排序

- 自定义排序函数

  - ```c++
    bool cmp(const int& a, const int& b) {
    	return a < b;		// 小于号 >> 从小到大排序
    	// return a > b;    // 大于号 >> 从大到小排序
    }
    // 也可以用 类或者结构体 重载()
    // 定义函数对象模板类
    template <typename T>
    struct cmp {
        //重载 () 运算符
        bool operator ()(const T &a, const T &b) {
            //按照值的大小，做升序排序, 从小到大
            return  a < b;
        }
    };
    ```

  - 使用内置的比较函数 less<type>()  greater<type>()

    - 默认使用的是`less<type>` (),  从小到大排序
    - 使用 `greater<type>`()，从大到小排序

## next_permutation 函数

- 基本介绍

  - 求下一个排列函数

- 使用

  - 注意: 使用前提是数组或者`vector`**有序!!!**,所以使用前得**先排序!!!**

  - 接收参数: [`pos_begin`, `pos_end`), **左闭右开!!!**

  - 返回值: 如果没有下一个排列组合,返回`false`,否则返回`true`

  - ```c++
    int arr[1001];
    for (int i = 1; i <= n; ++i)	a[i] = i;
    do{
    	for (int i = 1; i <= n; ++i)	cout << arr[i];		// 输出本次组合结果
    }while(next_permutation(arr + 1, arr + n + 1));			// 注意范围,左闭右开
    ```

    

# 自定义排序总结

- 统一通过**定义类或者结构体cmp, 重载 ()** 方式

  - 正常情况

    - ```c++
      // 定义函数对象模板类
      template <typename T>
      struct cmp {
          //重载 () 运算符
          bool operator ()(const T &a, const T &b) {
              //按照值的大小，做升序排序, 从小到大
              return  a < b;
          }
      };
      ```

  - 针对优先队列: 和正常情况相反

    - ```c++
      // 定义函数对象模板类
      template <typename T>
      struct cmp {
          //重载 () 运算符
          bool operator ()(const T &a, const T &b) {
              //按照值的大小，做降序排序, 从大到小, 与正常相反 top()返回最大元素
              return  a > b;
          }
      };
      ```

      

