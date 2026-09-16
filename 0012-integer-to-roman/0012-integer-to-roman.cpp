class Solution {
public:
    string intToRoman(int num) {
        
        static vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        static vector<string> symbol = {"M", "CM", "D", "CD","C", "XC", "L", "XL", "X","IX","V","IV" ,"I"};

        string ans = "";

        for(int i = 0; i < value.size(); i++){
            if(num == 0) break;
            int time = num/value[i];
            while(time--){
                ans+=symbol[i];
            }
            num = num%value[i];
        }
        return ans;
    }
};