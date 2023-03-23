#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&v){
    int n = v.size();
    for(int i=0;i<n;i++){
       cout << v[i] <<" ";
    }
    cout << endl;
}

void selections(vector<int>&v,int n){
    for(int i=0;i<n;i++){
        int s = i;
        for(int j = i+1;j<n;j++){
            if(v[j]<v[s]){
                s = j;
            }
        }
        swap(v[i],v[s]);
        print(v);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v = {5,2,3,4,6,8,1};
    //bubbleb(v,v.size());
    selections(v,v.size());
    //print(v);
}
