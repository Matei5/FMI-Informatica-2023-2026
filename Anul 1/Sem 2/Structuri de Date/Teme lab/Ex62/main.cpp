#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n = 5, muchii = 0;
    vector<bool> w = {true, false, false, false, false};
    vector<vector<int>> v = {{0, 1, 7, 0, 0},
                             {1, 0, 9, 2, 4},
                             {7, 9, 0, 5, 6},
                             {0, 2, 5, 0, 3},
                             {0, 4, 6, 3, 0}};

    cout << "Muchie <-> Cost\n";

    while(muchii < n - 1) {
        int min = INT_MAX, minX = 0, minY = 0;

        for(int i = 0; i < n; i++) {
            if(!w[i]) continue;

            for(int j = 0; j < n; j++) {
                if(w[j] || v[i][j] == 0) continue;

                if(min > v[i][j]) {
                    min = v[i][j];
                    minX = i;
                    minY = j;
                }
            }
        }

        cout << "(" << minX << ", " << minY << ") <-> " << v[minX][minY] << endl;
        w[minY] = true;
        muchii++;
    }

    return 0;
}