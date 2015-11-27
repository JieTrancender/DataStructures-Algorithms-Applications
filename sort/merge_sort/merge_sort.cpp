#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

//归并排序
template <typename anytype>
void MergeSort(anytype element[], int n);

//把相邻的两个数据段从x到y归并
template <typename anytype>
void MergePass(anytype x[], anytype y[], int n, int segment_size);

//把相邻的数据段从c到d归并
template <typename anytype>
void Merge(anytype c[], anytype d[], int first_start, int first_end, int second_end);

//打印数组元素
template <typename anytype>
inline void Print(anytype element[], int n);

int main()
{
    int num[] = {2, 5, 3, 45, 9, 123, 34, 6, 2};
    Print(num, sizeof(num) / sizeof(num[0]));
    MergeSort(num, sizeof(num) / sizeof(num[0]));
    Print(num, sizeof(num) / sizeof(num[0]));
    return 0;
}

template <typename anytype>
void MergeSort(anytype element[], int n)
{
    anytype *b = new anytype [n];
    int segment_size = 1;   //分割大小
    while(segment_size < n)
    {
        MergePass(element, b, n, segment_size);
        segment_size *= 2;
        MergePass(b, element, n, segment_size);
        segment_size *= 2;
    }
    delete [] b;
}

template <typename anytype>
void MergePass(anytype x[], anytype y[], int n, int segment_size)
{
    int i = 0;
    while(i <= n - 2 * segment_size)
    {
        Merge(x, y, i, i + segment_size - 1, i + 2 * segment_size - 1);
        i += 2 * segment_size;
    }

    //少于两个满数据段
    if(i + segment_size < n)
        Merge(x, y, i, i + segment_size - 1, n - 1);    //剩有两个数据段
    else
    {
        for(int j = i; j < n; ++j)  //剩有一个数据段
            y[j] = x[j];
    }
}

template <typename anytype>
void Merge(anytype c[], anytype d[], int first_start, int first_end, int second_end)
{
    int first = first_start;        //第一个数据段的索引
    int second = first_end + 1;     //第二个数据段的索引
    int result = first_start;       //归并数据段的索引

    //直到有一个数据段归并到归并段d
    while(first <= first_end && second <= second_end)
    {
        if(c[first] <= c[second])
            d[result++] = c[first++];
        else
            d[result++] = c[second++];
    }

    //归并剩余元素
    if(first > first_end)
    {
        for(int i = second; i <= second_end; ++i)
            d[result++] = c[i];
    }
    else
    {
        for(int i =  first; i <= first_end; ++i)
            d[result++] = c[i];
    }
}

template <typename anytype>
void Print(anytype element[], int n)
{
    copy(element, element + n, ostream_iterator<anytype>(cout, " "));
    cout << endl;
}
