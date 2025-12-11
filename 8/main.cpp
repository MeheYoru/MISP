#include <bits/stdc++.h>
using namespace std;

string norm(const string& s){
    string t=s;
    sort(t.begin(),t.end());
    return t;
}

int main(int argc, char* argv[]){
    if(argc!=3){
        cerr << "Usage: <program> \"anagram sentence\" dict.txt\n";
        return 1;
    }

    string sentence=argv[1];
    string dictfile=argv[2];

    ifstream fin(dictfile);
    if(!fin){
        cerr << "Cannot open dictionary file\n";
        return 1;
    }

    unordered_map<string, vector<pair<string,long long>>> dict;
    string w;
    long long weight;
    while(fin >> w >> weight){
        if(!w.empty())
            dict[norm(w)].push_back({w, weight});
    }

    vector<string> parts;
    stringstream ss(sentence);
    string t;
    while(ss >> t) parts.push_back(t);

    int n = parts.size();
    vector<vector<pair<string,long long>>> opts(n);

    for(int i=0;i<n;i++){
        string x = norm(parts[i]);
        if(!dict.count(x)){
            cout << "Error: no match for \"" << parts[i] << "\"\n";
            return 0;
        }
        opts[i] = dict[x];
    }

    vector<pair<long long, vector<string>>> results;
    vector<string> cur(n);

    function<void(int,long long)> dfs = [&](int i, long long sum){
        if(i==n){
            vector<int> p(n);
            iota(p.begin(), p.end(), 0);
            do{
                vector<string> perm(n);
                for(int k=0;k<n;k++) perm[k] = cur[p[k]];
                results.push_back({sum, perm});
            }while(next_permutation(p.begin(), p.end()));
            return;
        }
        for(auto &pr: opts[i]){
            cur[i] = pr.first;
            dfs(i+1, sum + pr.second);
        }
    };

    dfs(0,0);

    sort(results.begin(), results.end(), [](auto &a, auto &b){return a.first>b.first;});

    long long idx=1;
    for(auto &r: results){
        cout << idx++ << ". ";
        for(int i=0;i<n;i++){
            cout << r.second[i];
            if(i+1<n) cout << " ";
        }
        cout << " | weight=" << r.first << "\n";
    }

    return 0;
}
