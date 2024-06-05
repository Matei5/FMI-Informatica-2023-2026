#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int info;
    Node *next;
};
struct List {
    Node *head;
};

Node* Node_New(int info){
    Node *node = (Node*) malloc(sizeof(Node));
    node->info = info;
    node->next = nullptr;
    return node;
}
List* List_New(){
    List *myList = new List;
    myList->head = nullptr;
    return myList;
}

void List_Append(List *myList, int info, int poz = -1){
    Node *other = Node_New(info);
    if(myList->head == nullptr){
        myList->head = other;
        other->next = other;
        return;
    }
    Node *crt = myList->head, *prev = crt;
    while(crt->next != myList->head && poz != 0){
        prev = crt;
        crt = crt->next;
        poz--;
    }
    if(poz < 0 || poz > 0) {
        other->next = crt->next;
        crt->next = other;
    }
    else if(prev == crt){
        while(prev->next != myList->head) prev = prev->next;
        myList->head = other;
        prev->next = other;
        other->next = crt;
    }
    else{
        prev->next = other;
        other->next = crt;
    }
}
void List_Print(List *myList){
    Node *crt = myList->head;
    while(crt->next != myList->head){
        cout << crt->info << " ";
        crt = crt->next;
    }
    cout << crt->info << endl;
}
int List_Search(List* myList, int x){
    int i = 0;
    Node *crt = myList->head;
    while(crt->next != myList->head){
        if(crt->info == x) return i;
        crt = crt->next;
        i++;
    }
    if(crt->info == x) return i;
    return -1;
}
void List_Erase(List* myList, int x){
    int i = 0;
    Node *crt = myList->head, *prev = crt;
    while(prev->next != crt) prev = prev->next;

    while(crt->next != myList->head){
        if(i == x) {
            if(i == 0) myList->head = crt->next;
            prev->next = crt->next;

            free(crt);
            return;
        }
        prev = crt;
        crt = crt->next;
        i++;
    }
    if(i == x) {
        prev->next = crt->next;

        free(crt);
        return;
    }
    cout << "Index prea mare!\n";
}

int main(){
    List* myList = List_New();

    cout << "Ex2: Lista circulara dublu inlantuita: \n";

    int x, n;
    cout << "Cate elemente in lista?";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        List_Append(myList, x);
    }

    int choice = 1;
    while(choice != 0){
        cout << "|>= Exit 0; add 1; print 2; search 3; erase 4;\nIntorduce:";
        cin >> choice;

        if(choice == 0) break;
        else if(choice == 1){
            int poz;
            cout << "Element de adaugat:";
            cin >> x;
            cout << "Pozitie de introdus (<0 = final):";
            cin >> poz;
            List_Append(myList, x, poz);
        }
        else if(choice == 2){
            List_Print(myList);
        }
        else if(choice == 3){
            cout << "Element de cautat:";
            cin >> x;
            cout << List_Search(myList, x) << endl;
        }
        else if(choice == 4){
            cout << "Pozitie de sters:";
            cin >> x;
            List_Erase(myList, x);
        }
    }

    return 0;
}
