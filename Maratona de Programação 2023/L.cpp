#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

using namespace std;

map<char, queue<int>> hashing;

void getIndex(string &word){

    for(int i = 0; i < word.size(); i++){

        hashing[word[i]].push(i);

    }

}

int main(){

    string word;
    int jump;

    cin >> word;
    cin >> jump;

    int wordSize = word.size();

    getIndex(word);

    sort(word.begin(), word.end());

    vector<int> cache(wordSize, 0);
    vector<string> resp(wordSize, "");

    for(int i = 0; i < word.size(); i++){

        char letra = word[i];

        int idx = hashing[letra].front();

        int j = idx % jump;

        if(!cache[j]){
            cache[j] = jump;        
        }
        else{
            if(cache[j] > word.size()){
                j = idx;
            }
            else{
                j = cache[j];
                cache[j] += jump;
            }
        }

        resp[j] = letra;

        hashing[letra].pop();

    }

    for(auto &x : resp) cout << x;

    cout << endl;







}
