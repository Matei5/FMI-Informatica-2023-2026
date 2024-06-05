#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string a){
    stack<char> v;
    v.push('.');

    for(char x: a){
        if(x == '(' || x == '[' || x == '{') v.push(x);
        else if(x == ')' || x == ']' || x == '}'){
            char a = v.top(); v.pop();
            if(a == '.') return false;

            if(x == ')' && a != '(')  return false;
            if(x == ']' && a != '[')  return false;
            if(x == '}' && a != '{')  return false;
        }
    }
    return true;
}

int main() {
    string exemplu;
    cin >> exemplu;
    cout << check(exemplu);

//    string exempluBun = "{}[(){()}]", exempluRau = "({(}))", e = ")";
//
//    cout << check(exempluBun) << " " << check(exempluRau);
//    cout << " " << check(e) << " " << check("[(})");

}
