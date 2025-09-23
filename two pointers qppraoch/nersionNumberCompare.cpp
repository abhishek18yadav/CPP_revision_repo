#include <bits/stdc++.h>
using namespace std;
// int compareVersion(string version1, string version2)
// {
//     int ans = 0;
//     int v1 = 0;
//     int v2 = 0;
//     while (v1 < version1.length() and v2 < version2.length())
//     {
//         if (version1[v1] == '.' or version2[v2] == '.')
//         {
//             while (v1 + 1 < version1.length() and version1[v1 + 1] == '0')
//             {
//                 v1++;
//             }
//             while (v2 + 1 < version2.length() and version2[v2 + 1] == '0')
//             {
//                 v2++;
//             }
//             if (version1[v1] == '0')
//                 v1++;
//             if (version2[v2] == '0')
//                 v2++;
//         }
//         else if (version1[v1] == '.' and version2[v2] != '.')
//         {
//             if (version2[v2] != '0'){
//                 ans = -1;
//                 break;
//             }
//             else
//                 v1++;
            
//         }
//         else if (version1[v1] != '.' and version2[v2] == '.'){
//             if (version1[v1] != '0'){
//                 ans = 1;
//                 break;
//             }
//             else
//                 v2++;
//         }
//         if (version1[v1] != '.' and version2[v2]!='.' and version1[v1] > version2[v2])
//         {
//             ans = 1;
//             break;
//         }
//         else if (version1[v1] != '.' and version2[v2] != '.' and version1[v1] < version2[v2]){
//             ans = -1;
//             break;
//         }
//         else
//         {
//             if(v1+1<version1.length())
//                 v1++;
//             if(v2+1<version2.length())
//                 v2++;
//         }
//     }
    
//     while (v1 < version1.length())
//     {
//         if (version1[v1] == '.')
//         {
//             v1++;
//             continue;
//         }
//         if (version1[v1] != '0')
//         {
//             ans = 1;
//             break;
//         }
//         v1++;
//     }
//     while (v2 < version2.length())
//     {
//         if (version2[v2] == '.')
//         {
//             v2++;
//             continue;
//         }
//         if (version2[v2] != '0')
//         {
//             ans = -1;
//             break;
//         }
//         v2++;
//     }
//     return ans;
// }
int compareVersion(string version1, string version2)
{
    string v1 = version1;
    string v2 = version2;
    int x1 = 0, x2 = 0;
    for (int i = 0, j = 0; i < v1.size() or j < v2.size(); i++, j++)
    {
        while (i < v1.size() and v1[i] != '.')
        {
            x1 = x1 * 10 + (v1[i] - '0');
            i++;
        }
        while (j < v2.size() and v2[j] != '.')
        {
            x2 = x2 * 10 + (v2[j] - '0');
            j++;
        }
        // cout<<x1<<" "<<x2<<endl;
        if (x1 > x2)
            return 1;
        else if (x1 < x2)
            return -1;
        x1 = 0;
        x2 = 0;
    }
    return 0;
}
int main()
{
    string version1 = "1.0";
    string version2 = "1.0.0.0";
    cout << compareVersion(version1, version2);
    return 0;
}