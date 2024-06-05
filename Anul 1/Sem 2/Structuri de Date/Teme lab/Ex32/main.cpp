#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

int main() {

    int n, x;
    vector<int> v; // 5 2 4 1 1 3 6
    stack<int> s;
    queue<pair<int,int>> q;

    cout << "Cate elemente in vector?";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    for(int i = 0; i < v.size(); i++){
        if(s.empty()) s.push(i);
        else if(v[s.top()] < v[i]){
            while(v[s.top()] < v[i]){
                q.push(make_pair(s.top(), i));
                s.pop();
                if(s.empty()) break;
            }
            s.push(i);
        }
        else s.push(i);

    }

    while(!q.empty()){
        cout << q.front().first << " " << q.front().second << endl;
        q.pop();
    }
}
