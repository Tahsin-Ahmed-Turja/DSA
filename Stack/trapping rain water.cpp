#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    stack<int> st;
    int ans = 0;
    for(int i=0; i<height.size(); i++) {
        while(!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if(st.empty()) {
                break;
            }
            int left = st.top();
            int currWidth = i - left - 1;
            int currHeight = min(height[left], height[i]) - height[top];
            ans += currWidth * currHeight;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = trap(height);
    cout << "The amount of water trapped is: " << ans << endl;
    return 0;
}
