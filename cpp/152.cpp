class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int res = *max_element(nums.begin(), nums.end());
        int curMin = 1;
        int curMax = 1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                curMin = 1;
                curMax = 1;
            } else {
                int tmp = (curMax * nums[i]);
                curMax = max(max(nums[i] * curMax, nums[i] * curMin), nums[i]);
                curMin = min(min(tmp, nums[i]*curMin), nums[i]);
                res = max(res, curMax);
            }
        }
        return res;
    }
};
