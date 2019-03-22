#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int LCS(string A, int i, string B, int j)
{
    if(i == -1 || j == -1)
        return 0;
    if(A[i] == B[j])
        return 1 + LCS(A, i - 1, B, j - 1);
    else
    {
        int sum1 = LCS(A, i - 1, B, j);
        int sum2 = LCS(A, i, B, j - 1);
        return sum1 > sum2 ? sum1 : sum2;
    }
}

int main()
{
    string first = "AAAAAA", second = "BCD";
    cout << LCS(first, first.length() - 1, second, second.length() - 1);
    return 0;
}