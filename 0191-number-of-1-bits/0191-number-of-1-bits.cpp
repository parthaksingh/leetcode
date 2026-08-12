class Solution {
public:
    int hammingWeight(int n) {
        int bits = 0;
        int marks = 1;
        for(int i = 0; i< 32; i++){
            if((marks&n) != 0){
                bits++;
            }
            marks<<=1;
        }
        return bits;
    }
};