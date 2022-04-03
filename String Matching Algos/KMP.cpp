#include <bits/stdc++.h>
using namespace std;

vector<int> lps;
// lps[i] have the length of the longest prefix that is also suffix in p[0..i]
void PrefixFunction(string p)
{
    int m = p.size();
    lps = vector<int>(m, 0);

    int len = 0, i = 1;

    while (i < m)
    {
        if (p[i] == p[len])
        {
            lps[i] = len + 1;
            len++, i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

void FindPatterns(string s, string p)
{
    int n, m;
    n = s.size();
    m = p.size();

    int i = 0, j = 0;

    cout << "Starting index of the all the matching patterns\n";
    while (i < n)
    {
        if (s[i] == p[j])
        {
            i++, j++;
        }

        if (j == m)
        {
            cout << i - m << " ";
            j = lps[j - 1];
        }
        else if (j < m && s[i] != p[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    string s, p;
    cin >> s >> p;

    PrefixFunction(p);

    FindPatterns(s, p);
}

// time complexity: O(n+m)
// space complexity: O(m)