#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> selectionSort(vector<int> &v){
    int min, imin = 0;

    for(int i = 0; i < v.size() - 1; i++){
        min = INT_MAX;
        for(int j = i; j < v.size(); j++) {
            if(v[j] < min){
                min = v[j];
                imin = j;
            }
        }
        swap(v[i],v[imin]);
    }

    return v;
}

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

int main() {
    int n;
    vector<int> v;
    cout << "Cate elemente in vector:";
    cin >> n;
    for(int i = 0; i < n; i++) {
        int j; cin >> j;
        v.push_back(j);
    }

    // ex = 5 2 4 1 3 6

//    A
    cout << "Ex1a: ";
    vector<int> vect1 = v;
    for(int x: selectionSort(vect1)) cout << x << " ";
    cout << endl;

//    B
    cout << "Ex1b: ";
    vector<int> vect2 = v;
    for(int x: heapSort(vect2)) cout << x << " ";
    cout << endl;
}

//int quickify(vector<int> &v,int l,int r){
//    int pivot = v[r], i = l - 1;
//
//    for(int j = l; j <= r; j++)
//        if(v[j]<pivot) swap(v[++i],v[j]);
//
//    swap(v[i+1],v[r]);
//    return i+1;
//}
//vector<int> quickSort(vector<int> &v,int l,int r){
//
//    if(l < r){
//        int pivot = quickify(v,l,r);
//        quickSort(v,l,pivot-1);
//        quickSort(v,pivot+1,r);
//    }
//
//    return v;
//}
//void slowSort(vector<int> &v){
//    for(int i=0;i<v.size()-1;i++){
//        for(int j=i+1;j<v.size();j++){
//            if(v[i]>v[j]) swap(v[i],v[j]);
//        }
//    }
//}
//void mergeSort(vector<int> &v, int l, int r){
//    if(l<r){
//        int mid = (l+r) / 2;
//        mergeSort(v, l , mid);
//        mergeSort(v, mid + 1 , r);
//
//        int n1 = mid - l + 1, n2 = r - mid, c = 0, i = 0, j = 0, k = l;
//        vector<int> v1, v2;
//
//        for(int x: v){
//            if(c<n1) v1.push_back(v[l+c]);
//            else v2.push_back(v[mid+1+(c-n1)]);
//            c++;
//        }
//
//        while (i < n1 && j < n2) {
//            if (v1[i] <= v2[j]) v[k] = v1[i++];
//            else v[k] = v2[j++];
//            k++;
//        }
//        while (i < n1) v[k++] = v1[i++];
//        while (j < n2) v[k++] = v2[j++];
//    }
//}