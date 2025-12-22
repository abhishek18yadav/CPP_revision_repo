#include<bits/stdc++.h>

using namespace std;
 // this is Karp-Rabin Algorithm for Pattern Searching
long long hashedValue(const string &str)
{
    int PRIME = 1001;
    long long hash = 0;
    for (int i = 0; i < str.length(); i++){
        hash += str[i] * pow(PRIME, i);
    }
    return hash;
}

long long recalculateHash(string &str , int oldIdx , int newIdx , double oldHash , int patternLen){
    int PRIME = 1001;
    long long newHash = (oldHash - str[oldIdx]) / PRIME;
    newHash += str[newIdx] * pow(PRIME, patternLen - 1);
    return newHash;
}

vector<int> search(string &text , string &pattern){
    vector<int> idxes;
    long long patternHash = hashedValue(pattern);
    long long textHash = hashedValue(text.substr(0, pattern.length()));
    for (int i = 0; i <= text.length() - pattern.length(); i++){
        if(patternHash == textHash){
            if(text.substr(i , pattern.length()) == pattern){
                // cout<<"Pattern found at index "<<i<<endl;
                idxes.push_back(i);
            }
        }
        if(i<text.length()-pattern.length()){
            textHash = recalculateHash(text , i , i + pattern.length() , textHash , pattern.length());
        }
    }
    // cout<<"Pattern not found"<<endl;
    return idxes;
}
int repeatedStringMatch(string a, string b)
{
    vector<int> res = search(b, a);
    int ans = 0;
    if (res.size() == 0)
        return -1;
    if(res[0] != 0){
        // cout << "hit1" << endl;
         ans++;
    }
    if(res[res.size() - 1] + 2*a.length() -1  > b.length())
        ans++;
    int sz = res.size();
    // cout<<sz<<endl;
    return ans + sz;
}
int main(){
    string text = "aa";
    string pattern = "a";
    cout<<repeatedStringMatch(pattern,text)<<endl;
    return 0;
}