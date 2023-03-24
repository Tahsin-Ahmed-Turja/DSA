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

int partitionl(vector<int> &v, int l, int h)
{
    int pivot = v[l];
    int i = h + 1;
    for (int j = h; j > l; j--)
    {
        if (v[j] >= pivot)
        {
            i--;
            swap(v[i], v[j]);
        }
    }
    swap(v[l], v[i-1]);
    return (i-1);
}

int partitionh(vector<int>&v, int low, int high) {

  int pivot = v[high];
  int i = (low - 1);

  for (int j = low; j < high; j++){
    if (v[j] <= pivot){
      i++;
      swap(v[i], v[j]);
    }
  }

  swap(v[i + 1], v[high]);
  return (i + 1);
}

void quicks(vector<int> &v, int l, int h)
{
    if(l<h)
    {
        int p = partitionh(v, l, h);
        quicks(v,l,p-1);
        quicks(v,p+1,h);
    }
}

int main()
{
    vector<int> v = {9, 3, 4, 5, 1, 6, 8, 152, 6545, 5161, 52, 2, 112, 4, 5, 55};
    // bubbleb(v,v.size());
    // selections(v,v.size());
    // print(v);
    // insertion(v, v.size());
    // divide(v, 0, v.size() - 1);
    // mergea(v, 0, 6, 3);
    // quicks(v,0,v.size()-1);
    quicks(v,0,v.size()-1);
    print(v);
}
