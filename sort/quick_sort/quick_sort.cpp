#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

//递归快速排序
template <typename anytype>
void QuickSort(anytype element[], int left, int right);

//打印数组元素
template <typename anytype>
inline void Print(anytype element[], int n);

int main()
{
    int num[] = {2, 5, 3, 45, 9, 123, 34, 6, 2};
    Print(num, sizeof(num) / sizeof(num[0]));
    QuickSort(num, 0, sizeof(num) / sizeof(num[0]));
    Print(num, sizeof(num) / sizeof(num[0]));
    return 0;
}

template <typename anytype>
void QuickSort(anytype element[], int left, int right)
{
    if(left >= right)
        return;
    int left_cursor = left; //从左到右移动的索引
    int right_cursor = right;   //从右到左移动的索引
    anytype pivot = element[left];  //确定枢轴

    //将将位于左侧不小于枢轴和位于右侧不大于枢轴的元素交换
    while(true)
    {
        while(element[++left_cursor] < pivot);   //寻找左侧不小于枢轴的元素
        while(element[--right_cursor] > pivot);  //寻找右侧不大于枢轴的元素

        if(left_cursor >= right_cursor) //没有找到交换的元素对
            break;
        swap(element[left_cursor], element[right_cursor]);
    }

    //放置支点
    element[left] = element[right_cursor];
    element[right_cursor] = pivot;

    QuickSort(element, left, right_cursor - 1);     //对左侧的数段排序
    QuickSort(element, right_cursor + 1, right);    //对右侧的数段排序
}

template <typename anytype>
void Print(anytype element[], int n)
{
    copy(element, element + n, ostream_iterator<anytype>(cout, " "));
    cout << endl;
}
 
