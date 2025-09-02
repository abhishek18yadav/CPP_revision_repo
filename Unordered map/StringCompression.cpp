#include<bits/stdc++.h>
using namespace std;
#include<typeinfo>
int compress(vector<char> &chars)
{
    int j = 0;
    int count = 0;
    vector<vector<char>> ans;
    for (int i = 0; i < chars.size(); i++){
        if(chars[i]==chars[j]){
            count++;
        }else{
            if(count>1){
                if(count>9){
                    vector<char> temp;
                    // char v1 = char((count/10)+'0');
                    // char v2 = char((count%10)+'0');
                    ans.push_back({chars[j]});
                    while(count>0){
                        int rem = count%10;
                        temp.push_back(char(rem+'0'));
                        count/=10;
                    }
                    reverse(temp.begin(),temp.end());
                    for(auto ele: temp){
                        ans.back().push_back(ele);
                    }
                    // ans.push_back({chars[j],v1,v2});
                }else ans.push_back({chars[j],char(count+'0')});
            }else{
                ans.push_back({chars[j]});
            }
            
            count=1;
            j = i;
        }
    }
    if (count > 1)
    {
        if (count > 9)
        {
            vector<char> temp;
            // char v1 = char((count/10)+'0');
            // char v2 = char((count%10)+'0');
            ans.push_back({chars[j]});
            while (count > 0)
            {
                int rem = count % 10;
                temp.push_back(char(rem + '0'));
                count /= 10;
            }
            reverse(temp.begin(), temp.end());
            for (auto ele : temp)
            {
                ans.back().push_back(ele);
            }
            // ans.push_back({chars[j],v1,v2});
        }
        else
            ans.push_back({chars[j], char(count + '0')});
    }
    else
    {
        ans.push_back({chars[j]});
    }
    chars.clear();
    for(auto ele: ans){
        for(auto e: ele){
            chars.push_back(e);
        }
    }

        return chars.size();
}

int main(){
    vector<char> chars = {'a', 'a', 'b', 'b', 'a', 'a', 'a'};
    // chars={'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    cout<<compress(chars);
    return 0;
}