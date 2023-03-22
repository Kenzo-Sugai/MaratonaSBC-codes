#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[])
{
    
    int n,h,w;
 
    char ida, volta;
 
    cin >> n >> h >> w;
 
    for (int i = 0; i < n; i++)
    {
        cin >> ida >> volta;
 
        if(ida == 'Y'){
            cout << 'Y';
            h--;
            w++;
        }
        else if(ida == 'N' && w == 0){
            cout << 'Y';
            h--;
            w++;
        }
        else{
            cout << 'N';
        }
        cout << ' ';
 
        if(volta == 'Y'){
            cout << "Y\n";
            h++;
            w--;
        }
        else if(volta == 'N' && h == 0){
            cout << "Y\n";
            h++;
            w--;
        }
        else{
            cout << "N\n";
        }
 
    }
    
 
    
 
    return 0;
}
