#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    int n, m, i, j, k;
    n = 5;
    m = 3;

    char hold;
    int alloc[n][m];
    int max[n][m];
    int avail[3];

    ifstream theFile (argv[1]);

    for (int i = 0; i < n; i++) {
        int j = 0;

        while (true) {
            theFile >> hold;
            if (hold == '/')
                break;
            alloc[i][j] = (int)hold - 48;
            j++;
        }
    }

    for (int i = 0; i < n; i++) {
        int j = 0;

        while (true) {
            theFile >> hold;
            if (hold == '/')
                break;
            max[i][j] = (int)hold - 48;
            j++;
        }
    }

    int v = 0;
    while (true) {
        theFile >> hold;
        if (hold == '/')
            break;
        avail[v] = (int)hold - 48;
        v++;
    }
    

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i ++){
        for (j = 0; j < m ; j++){
            need[i][j] = max[i][j] - alloc [i][j];
        }
    }
    int y = 0;
    for (k = 0; k < 5; k++){
        for (i = 0; i < n; i++){
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++){
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    cout << "The Safe Sequence will be printed: " << endl;
    for (j = 0; j < n - 1; j++){
        cout << " p" << ans[j] << " ->";
    }
    cout << " p" << ans[n - 1] << endl;

    return (0);
}