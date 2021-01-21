class Solution {
public:
    #define oo 1000000007
    int ways(vector<string>& p, int kk) {
        int n = p.size ();
        if (n == 0) return 0;
        int m = p[0].length();
        
        bool hor[100][100];
        bool ver[100][100];
        memset (hor, false, sizeof (hor));
        memset (ver, false, sizeof (ver));
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--)
                hor[i][j] = hor[i][j + 1] || (p[i][j] == 'A');
        }
        
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                ver[i][j] = ver[i + 1][j] || (p[i][j] == 'A');
            }
        }
        
        long long f[60][60][60];
        bool ok;
        
        memset (f, 0, sizeof (f));
        
        for (int i = n - 1; i >= 0; i--) {
            ok = false;
            for (int j = m - 1; j >= 0; j--) {
                ok = ok || ver[i][j];
                if (ok) f[i][j][0] = 1;
                else f[i][j][0] = 0;
                for (int k = 1; k < kk; k++) {
                    bool apple = false;
                    for (int t = i + 1; t < n; t++) {
                        apple = apple || hor[t - 1][j];
                        if (apple) {
                            f[i][j][k] += f[t][j][k - 1];
                            f[i][j][k] %= oo;
                        }
                    }
                    
                    apple = false;
                    for (int t = j + 1; t < m; t++) {
                        apple = apple || ver[i][t - 1];
                        if (apple) {
                            f[i][j][k] += f[i][t][k - 1];
                            f[i][j][k] %= oo;
                        }
                    }
                    
                    cout << i << " " << j << " " << k << " " << f[i][j][k] << "\n";
                }
            }
        }
        
        return f[0][0][kk - 1];
    }
};
