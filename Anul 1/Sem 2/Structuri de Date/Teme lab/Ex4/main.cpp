#include <iostream>
#include <vector>
using namespace std;

struct Node{
    Node(string a = " ") : info(a) {this->next = nullptr;}
    string info;
    Node *next;
};

int main() {
    vector<Node*> v;
    for(int i = 0; i < 26; i++){
        Node *nou = new Node();
        v.push_back(nou);
    }
    string s[] = {"Aza", "arta", "inima", "iar", "iures"};

    for(string x: s) {
        string y = x; y[0] = tolower(y[0]);
        int n = (int) tolower(x[0]) - 97;
        Node *here = v[n], *prev = here;
        Node *nou = new Node(x);

        if(here->info == " ") {
            v[n] = nou;
            continue;
        }

        string z = here->info; z[0] = tolower(z[0]);
        while(z < y && here->next != nullptr) {
            prev = here;
            here = here->next;
            z = here->info; z[0] = tolower(z[0]);
        }
        if(z > y) {
            if (prev != here) prev->next = nou;
            else v[n] = nou;
            nou->next = here;
        }
        else here->next = nou;
    }

    for(Node* x: v){
        Node* here = x;
        while(here != nullptr) {
            cout << here->info << " ";
            here = here->next;
        }
        cout << endl;
    }
}
