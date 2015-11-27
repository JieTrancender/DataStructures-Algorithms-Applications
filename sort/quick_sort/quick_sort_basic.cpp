#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

//递归快速排序的驱动程序
template <typename anytype>
void QuickSort(anytype element[], int n);

//返回数组最大元素的索引
template <typename anytype>
inline int IndexOfMax(anytype element[], int n);

//打印数组元素
template <typename anytype>
inline void Print(anytype element[], int n);

int main()
{
    int num[] = {2, 5, 3, 45, 9, 123, 34, 6, 2};
    Print(num, sizeof(num) / sizeof(num[0]));
    QuickSort(num, sizeof(num) / sizeof(num[0]));
    Print(num, sizeof(num) / sizeof(num[0]));
    return 0;
}

template <typename anytype>
void QuickSort(anytype element[], int n)
{
    if(n <= 1)
        return;
    int max_index = IndexOfMax(element, n);
    swap(element[n - 1], element[max_index]);
    QuickSort(element, n - 1);
}

template <typename anytype>
int IndexOfMax(anytype element[], int n)
{
    int index = 0;
    for(int i = 1; i < n; ++i)
    {
        if(element[index] < element[i])
            index = i;
    }
    return index;
}

template <typename anytype>
void Print(anytype element[], int n)
{
    copy(element, element + n, ostream_iterator<anytype>(cout, " "));
    cout << endl;
}
