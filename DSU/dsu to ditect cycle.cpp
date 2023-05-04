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
        }
        parent[b] = a;
        size[a]+=size[b];
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        make(i);
    }

    bool cycle = false;

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;

        if(find(u) == find(v)){
            cycle = true;
            break;
        }
        Union(u, v);
    }

    if(cycle){
        cout << "Graph contains cycle" << endl;
    }
    else{
        cout << "Graph does not contain cycle" << endl;
    }

    return 0;
}
