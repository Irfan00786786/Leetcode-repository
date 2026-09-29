class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = 0;
        int j = 0;

        vector<int> result(n + m);
        int k = 0;

        while (i < m && j < n) {

            if (nums1[i] < nums2[j]) {
                result[k] = nums1[i];
                i++;
                k++;
            }
            else {
                result[k] = nums2[j];
                j++;
                k++;
            }
        }

        while (i < m) {
            result[k] = nums1[i];
            i++;
            k++;
        }

        while (j < n) {
            result[k] = nums2[j];
            j++;
            k++;
        }
        for (int x = 0; x < n + m; x++) {
            nums1[x] = result[x];
        }
    }
};