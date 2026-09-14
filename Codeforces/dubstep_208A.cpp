#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin >> s;
    
    string temp;
    int n = s.size();

    for(int i = 0; i<n; i++){
        if(i+2 < n && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
            if(temp.size() > 0){
                cout << temp << ' ';
                temp.clear();
            }
            i+=2;
        }else{
            temp+=s[i];
        }
    }
    if(!temp.empty()){
        cout << temp << ' ';
    }
    return 0;
}