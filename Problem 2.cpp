class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        int x[400][400];
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j >= 1) x[i][j] = x[i][j - 1] ^ a[j];
                else x[i][j] = a[j];
            }
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j; k < n; k++) {
                    if (x[i][j - 1] == x[j][k]) result++;
                }
            }
        }
        return result;
    }
};