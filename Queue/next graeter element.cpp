vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result(nums1.size(), -1);
    queue<int> mono;
    for (int num : nums2) {
        while (!mono.empty() && num > mono.front()) {
            int prev = mono.front();
            mono.pop();
            for (int i = 0; i < nums1.size(); i++) {
                if (nums1[i] == prev) {
                    result[i] = num;
                }
            }
        }
        mono.push(num);
    }
    return result;
}
