class Solution {
public:

    bool allcapital(string word){
        for(char ch : word){
            if(ch < 'A' || ch > 'Z')
                return false;
        }
        return true;
    }
    bool allsmall(string word){
        for(char ch : word){
            if(ch < 'a' || ch > 'z')
                return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if(allcapital(word) || allsmall(word) || allsmall(word.substr(1))){
            return true;
        }
        return false;
    }
};