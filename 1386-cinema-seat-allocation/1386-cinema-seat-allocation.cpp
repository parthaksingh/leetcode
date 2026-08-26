class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;

        for(auto &seat : reservedSeats){
            int row = seat[0];
            int col = seat[1];

            mp[row].insert(col);
        }
        int ans = (n - mp.size()) * 2;

        for(auto &it : mp){
            set<int> &reserved = it.second;

            bool left =true;
            bool middle = true;
            bool right = true;

            for(int seat = 2; seat <=5; seat++){
                if(reserved.count(seat)){
                    left = false;
                    break;
                }
            }
            for(int seat = 4; seat <= 7; seat++){
                if(reserved.count(seat)){
                    middle = false;
                    break;
                }
            }
            for(int seat = 6; seat<=9; seat++){
                if(reserved.count(seat)){
                    right = false;
                    break;
                }
            }
            if(left && right){
                ans += 2;
            }
            else if(left || middle || right){
                ans+=1;
            }
        }
        return ans;
    }
};