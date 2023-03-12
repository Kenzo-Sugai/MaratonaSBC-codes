#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct cria {
  int id;
  double nota = 0;
  int notatemp;
};

void print(vector<cria> &w){
  double nota = w[0].nota;
  printf("%.1lf\n", nota);
  string resposta = "";
  for(int k = 0; k < w.size(); k++){
    if(w[k].nota != nota) break;

    resposta += to_string(w[k].id);
    resposta += " "; 
  }
  resposta.pop_back();
  cout << resposta << endl;
}

bool comptemp(cria a, cria b) { return a.notatemp < b.notatemp; }
bool compnota(cria a, cria b) { 
  if(a.nota == b.nota) return a.id < b.id;
  return a.nota > b.nota; 
  }
bool compid(cria a, cria b) { return a.id < b.id; }

int min(int x, int y, int z) { return min(min(x, y), z); }
 
int editDistDP(string str1, string str2, int m, int n){
    int dp[m + 1][n + 1];
 
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0)
                dp[i][j] = j; 

            else if (j == 0)
                dp[i][j] = i;
 
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 
            else
                dp[i][j]
                    = 1
                      + min(dp[i][j - 1],
                            dp[i - 1][j],
                            dp[i - 1][j - 1]);
        }
    }
 
    return dp[m][n];
}
 

int main()
{
    int T;
    string palavras, target;
    vector<cria> words(5);
    for(int i = 0; i < words.size(); i++) words[i].id = i+1;
    cin >> T;
    for(int i = 0; i < T; i++){
      cin >> target;
      for(int j = 0; j < 5; j++){
        cin >> palavras;
        words[j].notatemp = editDistDP(target, palavras, target.size(), palavras.size());   
      }
      sort(words.begin(), words.end(), comptemp);
      int nota = words[0].notatemp;
      //for(auto x: words) cout << x.notatemp << " ";
      //cout << endl;
      for(int j = 0; j < 5; j++){
        if(words[j].notatemp != nota) break;

        if(words[j].notatemp == 0) {
          words[j].nota += 1.0;
          //cout << words[j].id << " | " << words[j].nota << endl;
          }
        else words[j].nota += 0.5;
      }
      sort(words.begin(), words.end(), compid);

    }
    sort(words.begin(), words.end(), compnota);
    print(words);
 
    return 0;
}
