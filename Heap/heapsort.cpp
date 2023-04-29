#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &heap)
{
    for (auto i : heap)
        cout << i << " ";
    cout << endl;
}

void heapify(vector<int>&ht,int size,int i){
    int largest = i;
    int l = 2*i + 1;
    int h = 2*i + 2;
    if(l < size && ht[l] > ht[largest]) largest = l;
    if(h < size && ht[h] > ht[largest]) largest = h;

    if(largest != i){
        swap(ht[i],ht[largest]);
        heapify(ht,size,largest);
    }
}

void make_heap(vector<int>&ht,int size){
    int l = ht.size();
    for(int i = l/2 - 1; i>=0 ; i--){
        heapify(ht,size,i);
    }
}

void heapsort(vector<int>&ht,int size){
    make_heap(ht,size);
    for(int i = size-1;i>=0;i--){
        swap(ht[0],ht[i]);
        heapify(ht,i,0);
    }
}

int main(){
    vector<int> v = {2,8,14,16,4,1,7,9,10,3};
    heapsort(v,v.size());
    print(v);
}
