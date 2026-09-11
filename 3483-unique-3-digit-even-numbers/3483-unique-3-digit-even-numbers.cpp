class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};

        for(int x : digits){
            freq[x]++;
        } 
        int count = 0;
        for(int a = 1; a <= 9; a++){
            if(freq[a] == 0){
                continue;
            }
            for(int b = 0; b <=9; b++){
                if(freq[b] == 0){
                    continue;
                }
                freq[a]--;
                if(freq[b] == 0){
                    freq[a]++;
                    continue;
                
                }
                freq[b]--;
                for(int c = 0; c<=8;c+=2){
                    if(freq[c]> 0){
                        count++;
                    }
                }
                freq[b]++;
                freq[a]++;
            }
        }
        return count;
    }
};