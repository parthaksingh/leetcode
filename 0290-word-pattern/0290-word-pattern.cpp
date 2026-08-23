class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        while(ss >>word){
            words.push_back(word);
        }

        if(pattern.size() != words.size()){
            return false;
        }
        unordered_map<char,string>mp1;
        unordered_map<string, char>mp2;

        for(int i=0; i<pattern.size();i++){
            char ch = pattern[i];
            string str = words[i];

            if(mp1.count(ch) && mp1[ch] != str){
                return false;
            }
            if(mp2.count(str) && mp2[str] != ch){
                return false;
            }
            mp1[ch] = str;
            mp2[str] = ch;
        }
        return true;
    }
};