#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
int parent[N];
int size[N];

void make(int x){
    parent[x] = x;
    size[x] = 1;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
            parent[b] = a;
            size[a]+=size[b];
        }
    }
}

int main(){

}
