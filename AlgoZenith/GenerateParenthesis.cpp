#include<bits/stdc++.h>
using namespace std;

vector<string> res;
void f(int op, int cl, int n, string ans)
{
    if (cl == n)
    {
        res.push_back(ans);
        return;
    }
    if (op < n)
    {
        f(op + 1, cl, n, ans + '(');
    }
    if (op > cl and cl < n)
    {
        f(op, cl + 1, n, ans + ')');
    }
    return;
}
vector<string> generateParenthesis(int n)
{
    string ans = "";
    f(0, 0, n, ans);
    return res;
}

int main(){
    int n = 4;
    vector<string> result = generateParenthesis(n);
    for(const string &s : result){
        cout << s << endl;
    }
    return 0;
}