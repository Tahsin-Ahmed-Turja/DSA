#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void mergee(vector<int> &v, int l, int h, int mid)
{
    int left = mid - l + 1;
    int right = h - mid;
    vector<int> la(left);
    vector<int> ra(right);
    for (int i = 0; i < left; i++)
    {
        la[i] = v[i + l];
    }
    for (int i = 0; i < right; i++)
    {
        ra[i] = v[mid + 1 + i];
    }
    int le = 0, re = 0;
    la.push_back(INT_MAX);
    ra.push_back(INT_MAX);
    for (int i = l; i <= h; i++)
    {
        if (la[le] <= ra[re])
        {
            v[i] = la[le];
            le++;
        }
        else
        {
            v[i] = ra[re];
            re++;
        }
    }
}

void mergea(vector<int> &v, int l, int h, int mid)
{
    int left = mid - l + 1;
    int right = h - mid;
    vector<int> la(left);
    vector<int> ra(right);
    for (int i = 0; i < left; i++)
    {
        la[i] = v[i + l];
    }
    for (int i = 0; i < right; i++)
    {
        ra[i] = v[mid + 1 + i];
    }
    // print(la);
    // print(ra);
    // cout << "next" << endl;
    int i = 0, j = 0;
    int k = l;
    while (i < left && j < right)
    {
        if (la[i] <= ra[j])
        {
            v[k] = la[i];
            i++;
        }
        else
        {
            v[k] = ra[j];
            j++;
        }
        k++;
    }

    while (i < left)
    {
        v[k] = la[i];
        i++;
        k++;
    }

    while (j < right)
    {
        v[k] = ra[j];
        j++;
        k++;
    }
}

void divide(vector<int> &v, int l, int h)
{
    if (l == h)
        return;
    int mid = (h + l) / 2;
    divide(v, l, mid);
    divide(v, mid + 1, h);
    mergea(v, l, h, mid);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v = {2, 3, 4, 5, 1, 6, 8};
    // bubbleb(v,v.size());
    // selections(v,v.size());
    // print(v);
    // insertion(v, v.size());
    divide(v, 0, v.size() - 1);
    // mergee(v, 0, 6, 3);
    print(v);
}
