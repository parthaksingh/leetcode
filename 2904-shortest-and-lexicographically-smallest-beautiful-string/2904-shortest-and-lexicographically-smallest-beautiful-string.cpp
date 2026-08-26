class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int left = 0;
        int ones = 0;

        for(int right = 0; right<s.size(); right++){

            if(s[right] == '1'){
                ones++;
            }
            while(ones> k){
                if(s[left] == '1'){
                    ones--;
                }
                left++;
            }
            while(ones == k && s[left] == '0'){
                left++;
            }
            if(ones == k){
                string temp = s.substr(left, right-left +1);

                if(ans.empty() || temp.size() < ans.size() || (temp.size() == ans.size() && temp < ans)){
                    ans = temp;
                }

                
            }
        }
        return ans;
    }
};