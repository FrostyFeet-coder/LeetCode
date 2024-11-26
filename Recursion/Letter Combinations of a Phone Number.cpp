class Solution {
public:
    vector<string> ans; // Final answer store karne ke liye
    // Digit-letter mapping like phone keypad
    vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // Recursive function jo combinations generate karega
    void solve(string &digits, string &temp, int idx) {
        int n = digits.size(); // Digits ka size
        // Agar saare digits process ho gaye, toh temp ko ans me store karna
        if (idx == n) {
            ans.push_back(temp); // Temp string ko result me daal do
            return; // Backtrack karne ke liye
        }
        int curr_num = digits[idx] - '0'; // Current digit ko number me convert karna
        // Har character jo current digit represent karta hai uske liye loop
        for (auto &key : keys[curr_num]) {
            temp.push_back(key); // Current letter ko temp me add karte hain
            solve(digits, temp, idx + 1); // Next digit process karne ke liye recursion call
            temp.pop_back(); // Backtrack, temp ka last character hata do
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) { 
            return ans; // Agar input digits khali hain toh khali result return karo
        }
        string temp; // Temporary string jo combinations generate karega
        solve(digits, temp, 0); // Solve function ko start se call karte hain
        return ans; // Final combinations return karo
    }
};
