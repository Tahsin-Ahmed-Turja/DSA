class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> next_greater(10001, -1);
        vector<int> ans(nums1.size());
        
        for (int num : nums2) {
            while (!s.empty() && nums2[s.top()] < num) {
                next_greater[nums2[s.top()]] = num;
                s.pop();
            }
            s.push(distance(nums2.begin(), find(nums2.begin(), nums2.end(), num)));
        }
        
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = next_greater[nums1[i]];
        }
        
        return ans;
    }
};
