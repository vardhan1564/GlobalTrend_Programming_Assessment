#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLen = 0;
    int left = 0;
    unordered_set<char> seen;

    for (int right = 0; right < n; right++) {
        char c = s[right];
        while (seen.count(c)) {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(c);
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int maxLength = lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << maxLength << endl;

    return 0;
}

