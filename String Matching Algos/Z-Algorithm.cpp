// Uses of Z-Algorithm
// finding pattern/substring in the given string
// finding total number of diffrent substring in a string
// finding compressed string whose repetation can generate the input string

#include <bits/stdc++.h>
using namespace std;

vector<int> z;

// z[i], is the length of the longest prefix of s which is also prefix of (suffix of s starting with index i)

void ZFunction(string s)
{
    int n = s.size();
    z = vector<int>(n, 0);

    // z[0]=0 as we are not considering the proper prefix
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - l]);
        }

        while ((i + z[i]) < n && s[z[i]] == s[z[i] + i])
        {
            z[i]++;
        }

        if ((i + z[i] - 1) > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int main()
{
    string s;
    cin >> s;

    ZFunction(s);
}

// time complexity = O(n)
// space complexity = O(n)