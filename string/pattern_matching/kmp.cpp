#include <iostream>
#include <string>

using namespace std;

//KMP字符串模式匹配算法
int KMP(string str1, string str2, int next[]);

//KMP next数组求取算法
void GetNext(string str, int next[]);

int main()
{
    string str1 = "BBC ABCDAB ABCDABCDABDE";
    string str2 = "ABCDABD";
    int *next = new int[str1.size()];
    cout << str1 << "'s size = " << str1.size() << ", " << str2 << "'s size = " << str2.size() << endl;
    GetNext(str2, next);
    int index = KMP(str1, str2, next);
    cout << "Index = " << index << endl;
    if(index >= 0)
        cout << index << ": " << str1.at(index) << endl;
    else
        cout << "Can't matching..." << endl;
    return 0;
}

void GetNext(string str, int next[])
{
    int len = str.size();
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < len - 1)
    {
        //str[k]表示前缀， str[j]表示后缀
        if(k == -1 || str[j] == str[k])
        {
            ++j;
            ++k;
            if(str[j] != str[k])
                next[j] = k;

            //不能出现p[j] = p[next[j]],则当出现时需要继续递归，
            //k = next[k] = next[next[k]]
            else
                next[j] = next[k];
        }
        else
        {
            k = next[k];
        }
    }
}

int KMP(string str1, string str2, int next[])
{
    int i = 0;
    int j = 0;
    int str1_len = str1.size();
    int str2_len = str2.size();
    while(i < str1_len &&j < str2_len)
    {
        //如果j == -1，或者当前字符匹配成功
        if(j == -1 || str1.at(i) == str2.at(j))
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if(j == str2_len)
        return i - j;
    else
        return -1;
}
