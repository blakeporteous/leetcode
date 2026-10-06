class Solution {
public:
    int rob(vector<int>& nums) {

        int rob1 = 0, rob2 = 0;
        int rob3 = 0, rob4 = 0;

        if (nums.size() == 1) return nums[0];

        // rob1 rob2 n n+1
        for(int i=0;i<nums.size() - 1;i++){
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        // rob3 rob4 n n+1
        for(int j=1;j<nums.size();j++){
            int temp = max(nums[j] + rob3, rob4);
            rob3 = rob4;
            rob4 = temp;
        }

        return max(rob2, rob4);
        
    }
};
