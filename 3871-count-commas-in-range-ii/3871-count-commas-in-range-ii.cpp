#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll result = 0;
        ll start = 1000;
        ll commas = 1;

        while(start <= n){
           ll lastno = start*1000 - 1;
           if(lastno > n)
            lastno = n;

            ll countofno = lastno - start + 1;
            result += countofno*commas;

            start *= 1000;
            commas++;

        }
        return result;

    }
};