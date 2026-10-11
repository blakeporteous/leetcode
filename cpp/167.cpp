class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // l starts first index, rights starts last
        // intialise res outside so it doesn't keep
        // re intialising
        int res = 0;
        int l = 0;
        int r = numbers.size() - 1;
        
        // should of found target before this is true
        while(l < r){

            res = numbers[l] + numbers[r];

            if(res > target) {
                // if result is bigger than target make it smaller
                r -= 1; 
            } 
            else if(res < target) {
                //if result is smaller make it bigger with l
                l += 1;
            } 
            else {
                // adding one because cpp index starts 0
                return {l + 1, r + 1};
            }
        }

        //failed could return empty but problem
        // says there will always be a solution anyway
        return {};
    }
};
