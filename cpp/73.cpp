class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        //o(1)

        int r = matrix.size(), c = matrix[0].size();
        bool rZero = false;

        // which r/c need to be 0

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    if(i > 0){
                        matrix[i][0] = 0;
                    } else {
                        rZero = true;
                    }


                }
            }
        }

        for(int i = 1; i<r; i++){
            for(int j = 1; j<c; j++){
                if((matrix[0][j] == 0) || (matrix[i][0] == 0)){
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int i=0; i<r; i++){
                matrix[i][0] = 0;
            }
        }

        if(rZero == true){
            for(int j=0; j<c; j++){
                matrix[0][j] = 0;
            }
        }

        
    }
};
