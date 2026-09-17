class Solution {
public:
    string makeGood(string s) {
        string result = "";
        for(char &ch : s){
            if(result.size()>0 && (result.back() - 32 == ch || result.back() + 32 == ch)){
                result.pop_back();
            }else{
                result.push_back(ch);
            }
        }
        return result;
    }
};