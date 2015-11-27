#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

//选择法排序
template <typename anytype>
void SelectSort(anytype *element, int n);

//打印数组元素
template <typename anytype>
inline void Print(anytype element[], int n);

int main()
{
    int num[] = {2, 5, 3, 45, 9, 123, 34, 6, 2};
    Print(num, sizeof(num) / sizeof(num[0]));
    SelectSort(num, sizeof(num) / sizeof(num[0]));
    Print(num, sizeof(num) / sizeof(num[0]));
    return 0;
}

template <typename anytype>
void SelectSort(anytype *element, int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        int k = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(element[k] > element[j])
                k = j;
        }
        if(k != i)
            swap(element[k], element[i]);
    }
}

template <typename anytype>
void Print(anytype element[], int n)
{
    copy(element, element + n, ostream_iterator<anytype>(cout, " "));
    cout << endl;
}
