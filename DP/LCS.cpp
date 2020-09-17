#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



/*longest common subsequence*/
int LCS(string l1, string l2){
    int m = l1.size(), n = l2.size();
    vector<vector<int>> mem;
    for (int i=0; i<=m; i++){
        vector<int> v = {};
        for (int j=0; j<=n; j++){
            v.push_back(0);
        }
        mem.push_back(v);
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            int s = mem[i][j];
            if (l1[i] == l2[j]){
                s++;
                }
            s = max(s,mem[i][j+1]);
            s = max(s,mem[i+1][j]);
            mem[i+1][j+1] = s;
        }
    }
    for (int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            cout << mem[i][j] << " ";
        }
        cout << endl;
    }

    return mem[m][n];
}




int main(){
    string l1 = "hjlldshckno";
    string l2 = "kjnblcknv";
    cout << LCS(l1, l2) << endl;
}

