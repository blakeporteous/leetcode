class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l = 0;
        int r = height.size() - 1;
        int max = 0;
        int small = 0;

        while(l<r){
            small = min(height[l], height[r]);

            if(max < (r-l) * small){
                max = (r-l) * small;
            }

            if(height[l]<height[r]){
                l +=1;
            } else {
                r -=1;
            }

        }

    return max;

    }
};
