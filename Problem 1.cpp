class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        int m = t.size();
        vector <string> res;
        int j = 0;
        
        for (int i = 1; i <= n; i++) {
            if (j == m) break;
            if (i == t[j]) {
                res.push_back ("Push");
                j++;
            } else {
                res.push_back ("Push");
                res.push_back ("Pop");
            }
        }
        return res;
    }
};