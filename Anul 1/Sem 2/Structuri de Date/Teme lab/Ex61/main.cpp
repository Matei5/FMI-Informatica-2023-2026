#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Muchie{
    Muchie(Muchie const &other) : x(other.x), y(other.y), cost(other.cost){}
    Muchie(int x_, int y_, int cost_) : x(x_), y(y_), cost(cost_){}

    void print(){cout << "(" << x << "," << y << ") <-> " << cost << endl; }

    int x, y, cost;
};

bool check(vector<Muchie> mst, Muchie w){

    for(Muchie j: mst)
        if(j.y == w.y || j.x == w.y) return false;

    return true;
}

int main() {
    int i, x, y;
    vector<Muchie> w, mst={};
    vector<vector<int>> v = {{0, 1, 7, 0, 0},
                             {1, 0, 9, 2, 4},
                             {7, 9, 0, 5, 6},
                             {0, 2, 5, 0, 3},
                             {0, 4, 6, 3, 0}};

    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v.size(); j++)
            if(v[i][j] != 0) w.push_back(Muchie(i,j,v[i][j]));

    for(int i = 0; i < w.size() - 1; i++)
        for(int j = i+1; j < w.size(); j++)
            if(w[i].cost > w[j].cost) swap(w[i],w[j]);

    for (i = 0; i < w.size(); i++)
        if(mst.empty() || check(mst,w[i])) mst.push_back(w[i]);

    cout << "Muchie <-> Cost\n";
    for(Muchie i: mst) i.print();

    return 0;
}