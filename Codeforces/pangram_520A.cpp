#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    if(n < 26){
        cout << "NO";
        return 0;
    }

    string s;
    cin >> s;
    vector<bool> visited(26, false);
    for(const char &x: s){
        int index = tolower(x)-'a'; // trick to get the index of x
        if(!visited[index]){
            visited[index] = true;
        }
    }

    for(const bool &x: visited){
        if(!x){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}