#include<bits/stdc++.h>
using namespace std;


int main(){

    // Creating an unordered map
    unordered_map<int, int> mp;
    // Inserting elements into the unordered map
    for(int i = 0; i < 10; i++){
        mp[i] = i ;
    }
    mp.erase(5); // Erasing an element with key 5
    // Displaying the elements of the unordered map
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }   
    return 0;
    
}