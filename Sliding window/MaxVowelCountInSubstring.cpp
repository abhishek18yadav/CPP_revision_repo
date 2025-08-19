#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c)
{
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}
int maxVowels(string s, int k)
{
    int left = 0, maxVowels = 0, vowel = 0;

    for (int right = 0; right < s.length(); right++)
    {
        if (isVowel(s[right]))
            vowel++;

        if (right - left + 1 == k)
        {
            maxVowels = max(maxVowels, vowel);
            if (isVowel(s[left]))
                vowel--;
            left++;
        }
    }
    return maxVowels;
}

int main() {
string s;
int k;
cout << "Enter the string: ";
cin >> s;
cout << "Enter the window size k: ";
cin >> k;
cout << "Maximum number of vowels in any substring of length " << k << " is: " << maxVowels(s, k) << endl;

    return 0;
}