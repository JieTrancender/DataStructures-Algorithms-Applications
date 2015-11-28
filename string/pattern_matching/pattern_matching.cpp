#include <iostream>
#include <string>

using namespace std;

//求字串位置的定位函数
int Index(string str1, string str2);

int main()
{
    string str1 = "BBC ABCDAB ABCDABCDABDE";
    string str2 = "ABCDABD";
    cout << str1 << "'s size = " << str1.size() << ", " << str2 << "'s size = " << str2.size() << endl;
    int index = Index(str1, str2);
    cout << "Index = " << index << endl;
    if(index >= 0)
        cout << index << ": " << str1.at(index) << endl;
    else
        cout << "Can't matching..." << endl;
    return 0;
}

int Index(string str1, string str2)
{
    int i = 0, j = 0;
    while(i < str1.size() && j < str2.size())
    {
        if(str1.at(i + j) == str2.at(j))    //若匹配，则模式串匹配位置后移
        {
            ++j;
        }
        else    //不匹配，则对比下一个位置，模式串回溯到首位
        {
            ++i;
            j = 0;
        }
        cout << "i = " << i << ", j = " << j << endl;
    }
    if(j >= str2.size())
        return i;
    else
        return -1;
}
