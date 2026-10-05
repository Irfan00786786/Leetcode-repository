class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();

        int zeros = 0;
        for (int i = 0; i < n - zeros; i++) {
            if (arr[i] == 0) {
                if (i == n - zeros - 1) {
                    arr[n - 1] = 0;
                    n--;
                    break;
                }
                zeros++;
            }
        }

        int i = n - zeros - 1;
        int j = n - 1;

        while (i >= 0) {
            arr[j] = arr[i];

            if (arr[i] == 0) {
                j--;
                arr[j] = 0;
            }

            i--;
            j--;
        }
    }
};