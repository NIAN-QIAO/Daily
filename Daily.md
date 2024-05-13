## C++笔记

- **C++20**新特性  <font color = 'red'>`include<ranges> ranges::sort `</font> 

  - 保有了 `std::sort`的使用方法，但比sort更加的灵活

  - 排序操作：

    - 传统：`std::sort(numbers.begin(),numbers.end)`
    - 现在：`std::ranges::sort(numbers)`

  - 逆序排序：

    - 传统：`std::sort(numbers.rbegin(),numbers.end())`
    - 现在：`std::ranges::sort(numbers,std::greater<>())`

  - 自定义排序：

    - 传统：

      ```
      bool customCompare(int a, int b) {
          // 自定义排序规则
          return a % 3 < b % 3;
      }
      
      int main() {
          std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
      
          // 传统自定义排序方式
          std::sort(numbers.begin(), numbers.end(), customCompare);
      
          // 其他操作...
          
          return 0;
      }
      ```

    - 现在：

      ```
      int main() {
          std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
      
          // 使用 ranges::sort 进行自定义排序
          std::ranges::sort(numbers, [](int a, int b) {
              // 自定义排序规则
              return a % 3 < b % 3;
          });
      
          // 其他操作...
          
          return 0;
      }//支持lambda表达式
      ```


- <font color = 'red'>**Lambda表达式**</font> :
  - Lambda表达式是C++11标准引入的一种简洁的定义匿名函数的方法。它们允许你在不声明标识符（即函数名）的情况下，快速定义一个函数。Lambda表达式在C++中非常有用，特别是在算法中提供自定义行为时。
  - `[capture](parameters) -> return_type { body }`
    - `[capture]`：捕获子句，用于指定Lambda表达式内部可以访问的外部变量。可以是值捕获、引用捕获或默认捕获（不写任何内容，表示不捕获任何变量）。
    - `(parameters)`：参数列表，定义了Lambda表达式可以接收的参数。如果Lambda不接收任何参数，可以省略这个括号。参数可以有类型声明，也可以省略，让编译器自动推断（使用`auto`关键字）。
    - `-> return_type`：返回类型。从C++14开始，如果Lambda的返回类型可以被编译器推断，可以省略这个部分。
    - `{ body }`：函数体，包含了Lambda表达式的代码。
  - Lambda表达式可以用于各种情况，包括但不限于：
    - 作为函数对象传递给STL算法，如`std::sort`、`std::for_each`等。
    - 作为回调函数。
    - 在初始化STL容器时提供默认值。


- **`#include <numeric>  itoa()   iota(v.begin(),v.end(),1);`** **C++中 iota() 是用来批量递增赋值vector的元素的。**

- **字符串分割**：`#include<sstream>     std::sstream`

  -  <font color = red>***stringstream*** </font> 是 **C++** 提供的专门用于处理字符串的 **输入输出** 流类。

  - <font color = red>***stringstream***</font>可以将存储于内部的字符串输出，但是需要调用  `str()` 函数, **不可以** 直接输出

  - ```
    //stringstream 的输入会拼接在后面
    stringstream ss1;
        ss1 << "fre";
        ss1 << "gre";
        cout << ss1.str() << endl;
    /*输出：
    fre
    gre
    */
    ```

  - ```
    //初始化之后stringstream输入，会覆盖原本的字符串，然后再进行拼接
    string str("asd");
        // 第二种构造
        stringstream ss2(str);
        cout << ss2.str() << endl;  
        // 第一种构造
        ss2 << "r";
        cout << ss2.str() << endl;
        ss2 << "13";
        cout << ss2.str() << endl; 
        ss2 << "hy";
        cout << ss2.str() << endl;
        /*
    输出：
    asd
    rsd
    r13
    r13hy
    */
    ```

  - ```
    //如果不想被覆盖，使用append方式追加
    	ostringstream ss("1 2 3 4 ", std::ios_base::ate);// append 方式追加
        cout << ss.str() << endl; 
        ss << "5 3 4";
        cout << ss.str() << endl;
    /*
    输出：
    1 2 3 4 
    1 2 3 4 5 3 4
    */
    ```

  -  <font color = red>***stringstream*** </font> 的修改可以用  `str()` 函数

  - <font color = red>***stringstream*** </font> 默认是以空格来分割字符串的，利用 **`stringstream`**非常方便

    ```
    
    int main()
    {
        stringstream ss("hello string and stringstream");
        cout << ss.str() << endl;
        
    	cout<< endl;
        
        string str;
        // 注意： stringstream 是一个单词一个单词 ”流入“ string 的
        while (ss >> str)
        {
            cout << str << endl;
        }
        
        return 0;
    }
     
    /*
    输出：
    hello string and stringstream
     
    hello 
    string 
    and
    stringstream
    
    ```

  - <font color= red>**stringstream**</font> 指定字符串分割，原型是`getline()`

    ```
    vector<string> split(const string &s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
    
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
    
        return tokens;
    }
    ```

  - 使用  <font color= red>**stringstream**</font> 进行类型转换

    ```
    //数字到字符串
    int num = 123;
        std::stringstream ss;
        ss << num; // 将整数放入流中
        std::string str = ss.str(); // 使用str()函数 从流中提取字符串
        std::cout << str << std::endl; // 输出：123
        
    //字符串到数字    
    std::string str = "456";
        std::stringstream ss(str); // 初始化stringstream
        int num;
        ss >> num; // 从流中提取整数
        std::cout << num << std::endl; // 输出：456
    ```

    

- C++使用`ctype`库判断字符类型 `#include<cctype>`

  - ```cpp
    isdigit()	// 判断是否为数字
    isalpha()	// 判断是否为字母
    isalnum()   // 判断是否为字母或者数字
    iscntrl()   // 判断是否为控制字符
    isgraph()   // 判断是否为除空格外的打印字符
    islower()   // 判断是否为小写字符
    isprint()   // 判断是否为打印字符
    ispunct()   // 判断是否为标点符号
    isspace()   // 判断是否为空格
    isupper()   // 判断是否为大写字母
    isxdigit()  // 如果参数是十六进制数字，0~9、a~f、A~F，返回true
    tolower()   // 如果参数是大写字符，返回其小写
    toupper()   // 如果参数是小写字符，返回其大写
    ```

- 哈希函数：能够将 **集合** 中任意可能的元素映射到一个固定范围的整数值，并将该元素存储到整数值对应的地址上。

  - 冲突处理：
    - **链地址法**：每个哈希值维护一个链表，具有相同哈希值的元素都放入这一链表当中
    - 开放地址法：当发现哈希值 h 处产生冲突时，根据某种策略，从 h 出发找到下一个不冲突的位置。例如，一种最简单的策略是，不断地检查 h+1,h+2,h+3,…… 这些整数对应的位置。
    - 再哈希法：当发现哈希冲突后，使用另一个哈希函数产生一个新的地址。

- 编译器内置函数`__builtin_clz` 

  - 如果 `n` 是 `1`（二进制表示为 `1`），那么 `__builtin_clz(n)` 将返回 `32`（在32位处理器上）或 `64`（在64位处理器上），因为只有一个1，前面有32个或64个0。
  - 如果 `n` 是 `2`（二进制表示为 `10`），那么 `__builtin_clz(n)` 将返回 `31`（在32位处理器上）或 `63`（在64位处理器上），因为有二进制位表示为 `10`，最高位的1前面有一个0。
  - 如果 `n` 是 `0`，那么 `__builtin_clz(n)` 将返回 `32`（在32位处理器上）或 `64`（在64位处理器上），因为0的二进制表示全为0，没有1。

- `std::vector.resize()`
  - `void resize(size_type n)` 
  - `void resize(size_type n,const value_type&val)`
  - **当操作后size减小，则直接减小vector空间大小，舍弃多出来的元素；**
  - **当操作后size增大，则以val对新增元素幅值，未指定val则赋默认值0。**

- `#include<functional>`
  - `<functional>`是一个函数包装器，该函数包装器模板能包装任何类型的可调用实体，如普通函数，函数对象，**lamda**表达式等。包装器可拷贝，移动等，并且包装器类型仅仅依赖于调用特征，而不依赖于可调用元素自身的类型。

- `map 和 unordered_map` **可以插入或删除，但不能更改，与键关联的值可以更改**
  - `unordered_map`
    - 优点：**哈希表，查找速度快**
    - 缺点：**哈希表的建立非常耗时间**
    - 适用问题：***查找问题***
  - `map`
    - 优点：**有序性，红黑树:操作可以在`lgn`的时间复杂度下可以实现，效率很高**
    - 缺点：空间占用率非常高
    - 适用问题 :***顺序问题***

- `STL set`**集合每个键都是唯一      可以插入或删除但不能更改 **      **键和值完全相同**

- `push_back()`和**直接赋值**
  - `push_back()` ：处理一个序列容器，例如`vector、deque、list`
  - 直接赋值：处理一个关联容器，例如 `map、unordered_map、set`

- `unique      #include<algorithm>`
  - 去除容器中或者数组中相邻元素的重复出现的元素
  - 并不是真正的`erase`，而是将重复的元素放容器的末尾，返回值是去重之后的尾地址（容器的末尾），**指向最后一个元素的下一个元素的迭代器**
  - `iterator unique(iterator it_1,iterator it_2,bool MyFunc);` **表示`[it_1,it_2)`内进行去重** 

- `include<string>      find()`  

  - 找到对应字符在数组中的位置，没有找到则返回-1

- ### **`priority_queue` 和`queue`**

  - <font color = 'red'>**`priority_queue`** </font>与 <font color = 'red'> **`queue`**</font>的区别在于，`priority_queue`可以定义数据的优先级，让优先级高的排在队列前面，优先出列。**本质是一个堆实现**
  - **`priority_queue<Type,Container,Functional>         eg priority_queue<int, vector<int>, greater<>> pq0, pq1;  `**
    - `priority_queue<int,vector<int>,greater<int>> Q` **升序对列**  小顶堆
    - `priority_queue<int,vector<int>,less<int>> Q` **降序队列**  大顶堆
    - `priority_queue a`默认是大顶堆
  - 和队列不一样的是，优先队列没有 `front()` 函数与 `back()` 函数，而只能通过 `top()` 函数来访问队首元素（也可以称为堆顶元素），也就是优先级最高的元素。

- ## **<font color = "orange">排序</font>**

  - ### **冒泡排序**

    - 外层循环，逐趟扫描
    - 内层循环，一趟扫描
    - **稳定**  **`O(n^2)`**

  - ### 插入排序

    - 外层循环，所有的元素
    - 内层循环，大的往右移
    - **`O(n^2)`**   **稳定**

  - ### **选择排序**

    - 外层循环，遍历所有元素
    - 内存循环，寻找最小值
    - **`O(n^2)`**   **稳定**

  - ### 希尔排序

    - 增量序列
    - 外圈循环，确定增量序列大小，一般设为数组长度的一半
    - 内圈循环，插入排序
    - **`O(n^2)`**  **不稳定**

  - ### 计数排序

    - <font color  = 'red'>**通过计数而不是比较来进行排序，适用于范围较小的整数序列**</font>
    - 从下标1开始计数
    - <font color ='blue'>多用于正数</font>

  - ### 快速排序

    - **分而治之**
    - **基准**

  - ### 归并排序

    - **分治、递归**
    - **稳定的**

  - ### 堆排序

    - 主要操作分为两步
      - 1.建堆/维护堆 `void adjust(int arr[], int len, int index)` 
      - 2.排序 `void heapSort(int arr[], int size)`
    - 下标为 i 的结点 的父亲结点下标： ( i - 1 ) / 2
    - 下标为 i 的节点左孩子下标： i * 2 + 1
    - 下标为 i 的节点右孩子下标： i * 2 + 2
    - **维护堆的复杂度为O(log n)**  
    - **不稳定**   **`O(nlogn)`**

- ### 背包问题

  - 0-1背包问题：背包可以装物品的总重量为W，现有N个物品，每个物品中w[i]，价值v[i]
  - **状态转移数组：dp [i] [j]，表示前i个物品，背包重量为j的情况下能装的最大价值**
  - **状态转移方程:`dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i])`**
    - `dp[i-1][j]`表示当前物品不放入背包
    - `dp[i-1][j-w[i]]+v[i]`表示当前物品放入背包

