#include <bits/stdc++.h>
using namespace std;

const double e = 1e-7;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    int i, key, j;
    for (i = 0; i < n; i++)
    {
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
        for(int e : v) cout << e <<" ";
        cout << endl;
    }
}
