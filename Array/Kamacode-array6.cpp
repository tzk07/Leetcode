#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/*
    题目描述
        给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
    输入描述
        第一行输入为整数数组 Array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间下标：a，b （b > = a），直至文件结束。
    输出描述
        输出每个指定区间内元素的总和。
*/

int main(){
    int a, b, n;
    cout << "Input n:";
    cin >> n;

    vector<int> vec1(n);
    for(int i = 0; i < n; i++) cin >> vec1[i];

    cin >> a >> b;
    int sum1 = 0;
    for(int i = a; i <= b; i++)
    {
        sum1 += vec1[i];
    }
    cout << sum1 << endl;

    // 提高效率：前缀和
    vector<int> vec2(n);
    vector<int> p(n);
    int presum = 0;
    for(int i = 0; i < n; i++) 
    {
        cin >> vec2[i];
        presum += vec2[i];
        p[i] = presum;
    }
    int result = p[b] - p[a-1];
    cout << result << endl;

    return 0;
}