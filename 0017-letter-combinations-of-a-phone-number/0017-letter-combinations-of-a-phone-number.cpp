class Solution {
public:
    vector<string> result;
    void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp){
        if(idx >= digits.size()){
            result.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];

        for(int i =0; i < str.size(); i++){
            temp.push_back(str[i]);
            solve(idx+1, digits, temp, mp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
      if(digits.size() == 0)
        return {};

       //vector<string> result;
       unordered_map<char, string> mp = {
        {'2', "abc"}, {'3', "def"},
        {'4' , "ghi"}, {'5' , "jkl"},
        {'6' , "mno"}, {'7' , "pqrs"},
        {'8' , "tuv"}, {'9' , "wxyz"}
       };

        string temp = "";

        solve(0, digits, temp, mp);

        return result;
    }
};