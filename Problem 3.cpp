class Solution {
public:
    typedef pair <int, bool> ib;
    typedef vector <int> vii;
    
    vii a[200000];
    int n;
    bool ok[200000];
    bool visit[200000];
    
    ib DFS (int u) {
        visit[u] = true;
        ib result;
        result.first = 0; result.second = false;
        int i = 0;
        while (i < a[u].size()) {
            if (visit[a[u][i]]) {
                i++; continue;
            }
            ib tmp = DFS (a[u][i]);
            if (tmp.second) {
                result.first = result.first + tmp.first + 1;
                result.second = true;
            }
            i++;
        }
        if ((!ok[u]) && (!result.second)) {
            result.first = 0;
        } else {
            result.second = true;
        }
        return result;
    }
    
    int minTime(int n, vector<vector<int>>& e, vector<bool>& hasApple) {
        n = e.size();
        for (int i = 0; i < n; i++) {
            a[e[i][0]].push_back (e[i][1]);    
            a[e[i][1]].push_back (e[i][0]);
        }
        
        n++;
        for (int i = 0; i < n; i++) {
            if (hasApple[i]) {
                ok[i] = true;
            }
            else ok[i] = false;
        }
        
        memset (visit, false, sizeof (visit));

        ib result = DFS (0);
        return result.first * 2;
    }
};