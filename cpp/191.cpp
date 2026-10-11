class Solution {
public:
    int hammingWeight(int n) {
        
        int bits = 0;
        int rem = 0;

        while(n != 0 ){

            rem = n % 2;

            if(rem == 1){
                bits +=1;
            }
            n = n/2;
        }

        return bits;

    }
};
