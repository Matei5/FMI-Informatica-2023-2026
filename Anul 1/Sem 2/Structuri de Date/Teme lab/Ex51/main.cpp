#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Node{
    Node(int a) : info(a), left(nullptr), right(nullptr){}
    Node *left, *right;
    int info;
};

void heapify(vector<int> &v, int n, int i) {
    int maxim = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && v[l] > v[maxim]) maxim = l;
    if (r < n && v[r] > v[maxim]) maxim = r;

    if (maxim != i) {
        swap(v[i], v[maxim]);
        heapify(v, n, maxim);
    }
}
vector<int> heapSort(vector<int> &v) {

    int n = v.size() - 1;
    for(int i = n/2 - 1; i >= 0; i--) heapify(v, n, i);

    for(int i = n - 1; i >= 0; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
    return v;
}

Node* creare(vector<int> v, int l, int r){
    if(l > r) return nullptr;

    int mid = (l + r) / 2;
    Node* head = new Node(v[mid]);

    head->left = creare(v, l, mid - 1);
    head->right = creare(v, mid + 1, r);

    return head;
}

vector<int> toVector(Node* Node, vector<int> &out){

    if(Node == nullptr) return {};

    out.push_back(Node->info);
    toVector(Node->left, out);
    toVector(Node->right, out);

    return out;
}

vector<int> interclasare(vector<int> v1, vector<int> v2){
    int i = 0, j = 0, k = 0;
    vector<int> v;

    while(i < v1.size() && j < v2.size()) {
        if(v1[i] <= v2[j]) v.push_back(v1[i++]);
        else v.push_back(v2[j++]);
    }
    while(i < v1.size()) v.push_back(v1[i++]);
    while(j < v2.size()) v.push_back(v2[j++]);

    return v;
}

Node* merge(Node *head1, Node *head2){
    vector<int> v1, v2;

    toVector(head1, v1);
    toVector(head2, v2);
    heapSort(v1);
    heapSort(v2);

    vector<int> v = interclasare(v1, v2);

    return creare(v, 0, v.size() - 1);
}

// Pb Extra 1: https://www.geeksforgeeks.org/print-bst-keys-in-given-range-o1-space/

void toVectorWithRange(Node* Node, int min, int max){

    if(Node == nullptr) return;

    if(Node->info >= min && Node->info <= max) cout << Node->info << " ";
    toVectorWithRange(Node->left, min, max);
    toVectorWithRange(Node->right, min, max);
}

// Pb Extra 2:https://www.geeksforgeeks.org/count-pairs-from-two-bsts-whose-sum-is-equal-to-a-given-value-x/

vector<pair<int,int>> findPairs(Node* head1, Node* head2, int x, vector<pair<int,int>> &pairs){

    if(head1 == nullptr || head2 == nullptr) return {};

    if(head1->info + head2->info == x) pairs.push_back(make_pair(head1->info,head2->info));
    findPairs(head1->left, head2->left, x, pairs);
    findPairs(head1->right, head2->right, x, pairs);

    return pairs;
}

int main(){

    vector<int> v1 = {1,2,7,8,9,10}, v2 = {3,4,5,6}, ans1, ans2, ans3;
    vector<pair<int,int>> ans4;
    Node* head1 = creare(v1, 0, v1.size() - 1);
    Node* head2 = creare(v2, 0, v2.size() - 1);
    Node* mergedHead = merge(head1, head2);


    for(int i : toVector(head1, ans1)) cout << i << " "; cout << endl;
    for(int i : toVector(head2, ans2)) cout << i << " "; cout << endl;
    for(int i : toVector(mergedHead, ans3)) cout << i << " "; cout << endl;
    toVectorWithRange(mergedHead, 4, 8); cout << endl;
    for(pair<int,int> i : findPairs(head1, head2, 11, ans4))
        cout << i.first << " " << i.second << endl;

    return 0;
}