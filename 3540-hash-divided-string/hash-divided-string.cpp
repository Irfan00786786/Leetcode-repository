class Solution {
public:
    string stringHash(string s, int k) {
        string result = "";

        for (int i = 0; i < s.length(); i += k) {
            int sum = 0;

            for (int j = i; j < i + k; j++) {
                sum += s[j] - 'a';
            }

            int hashedChar = sum % 26;
            result += char('a' + hashedChar);
        }

        return result;
    }
};