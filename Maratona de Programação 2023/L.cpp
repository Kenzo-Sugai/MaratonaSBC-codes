#include <bits/stdc++.h>

using namespace std;

int main() {

    string pal;
    int k;

    cin >> pal; cin >> k;

    if(k==1){
        sort(pal.begin(), pal.end());
        cout << pal << endl;
        return 0;
    }
    if(k == pal.size()-1){
        if(pal[0] > pal[pal.size()-1]){
            swap(pal[0], pal[pal.size()-1]);
        }
        cout << pal <<  endl;
        return 0;
    }

    vector<string> hist(k, "");
    int index = 0;

    for (int i = 0; i < pal.size(); i++){
        hist[index] += pal[i];
        index++;
        index %=k;
    }
    for (int i = 0; i < k; i++){
        sort(hist[i].begin(), hist[i].end());
    }

    index=0;
    for (int i = 0; i < pal.size(); i++) {
        if(hist[index].size()>0){
            cout << hist[index][0];
            hist[index].erase(hist[index].begin());
        }
        index++;
        index %=k;
    }
    cout << endl;
    return 0;
}
