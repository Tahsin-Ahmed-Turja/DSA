#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &heap)
{
    for (auto i : heap)
        cout << i << " ";
    cout << endl;
}

void heapify(vector<int>&ht,int i){
    int size = ht.size();
    int largest = i;
    int l = 2*i + 1;
    int h = 2*i + 2;
    if(l < size && ht[l] > ht[largest]) largest = l;
    if(h < size && ht[h] > ht[largest]) largest = h;

    if(largest != i){
        swap(ht[i],ht[largest]);
        heapify(ht,largest);
    }
}

void make_heap(vector<int>&ht){
    int l = ht.size();
    for(int i = l/2 - 1; i>=0 ; i--){
        heapify(ht,i);
    }
}

void insert(vector<int>&ht, int key)
{
    int size = ht.size();
    if (size == 0)
    {
        ht.push_back(key);
        return;
    }
    ht.push_back(key);
    make_heap(ht);
    return;
}

void deletenode(vector<int>&ht, int key){
    int i = -1;
    int l = 0;
    int h = ht.size()-1;
    int mid;
    while(l<=h){
        mid = l + (h-l)/2;
        if(key == ht[mid]){
            i = mid;
            break;
        }
        else if(key < ht[mid]){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    if(i == -1) return;
    swap(ht[i],ht[ht.size()-1]);
    ht.pop_back();
}

int main()
{
    vector<int> heap;

    insert(heap, 3);
    insert(heap, 4);
    insert(heap, 9);
    insert(heap, 5);
    insert(heap, 2);

    print(heap);

    deletenode(heap,4);

    print(heap);
}
