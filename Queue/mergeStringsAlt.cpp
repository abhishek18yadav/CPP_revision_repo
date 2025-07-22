#include<bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
       queue<char>q1,q2;
       for(int i=0; i<word1.length(); i++){
        q1.push(word1[i]);
       } 
       for(int i=0; i<word2.length(); i++){
        q2.push(word2[i]);
       }
       string res="";
       while(q1.size()>0  &&  q2.size()>0){
        char c1 = q1.front();
        char c2= q2.front();
        res= res+c1+c2;
        q1.pop();q2.pop();
       }
       if(q2.size()>0){
        while(q2.size()>0){
            char c2 = q2.front();
            res= res+c2;
            q2.pop();
        }
       }
       if(q1.size()>0){
        while(q1.size()>0){
            char c2 = q1.front();
            res= res+c2;
            q1.pop();
        }
       }
       return res;
}

int main(){
    string w1="abcd", w2="pq";
    string ans = mergeAlternately(w1,w2);
    cout<<ans<<endl;
    return 0;
}