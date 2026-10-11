class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prefix =1;
        int postfix = 1;
        vector<int> output(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            output[i] = prefix;
            prefix *= nums[i];
        }

        for (int j = nums.size() - 1; j >= 0; j--) {
            output[j] *= postfix;
            postfix *= nums[j];
        }

        return output;
    }
};
