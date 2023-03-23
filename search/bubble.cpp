#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&v){
    int n = v.size();
    for(int i=0;i<n;i++){
       cout << v[i] <<" ";
    }
    cout << endl;
}

void bubblel(vector<int>&v,int n){
    for(int i=0;i<n;i++){
        bool f = 1;
        for(int j = i; j<n-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                f = 0;
            }
        }
        if(f) break;
    }
}

void bubbleb(vector<int>&v,int n){
    int r = 0;
    for(int i = 0;i<n;i++){
        for(int j =n-2; j>=r;j--){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
        print(v);
        r++;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v = {1,5,2,3,4,6,8};
    bubblesl(v,v.size());
    print(v);
}
