#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, int> database;
    while(n--){
        string name;
        cin >> name;
        if(database.find(name) != database.end()){
            database[name]++;
            cout << (name + to_string(database[name])) << '\n';
        }else{
            database[name] = 0;
            cout << "OK\n";
        }
    }
    return 0;
}