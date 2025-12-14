class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergeSort(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    void merge(std::vector<int>& arr, int left, int mid, int right) {

        std::vector<int> arr1(mid - left + 1);
        std::vector<int> arr2(right - mid);
        for (int i = 0; i < arr1.size(); i++) {
            arr1[i] = arr[left + i];
        }
        for (int i = 0; i < arr2.size(); i++) {
            arr2[i] = arr[mid + 1 + i];
        }
        int curr_1 = 0;
        int curr_2 = 0;
        while (curr_1 < arr1.size() && curr_2 < arr2.size()) {
            int elem;
            if (arr1[curr_1] < arr2[curr_2]) {
                elem = arr1[curr_1];
                curr_1++;
            }
            else {
                elem = arr2[curr_2];
                curr_2++;
            }
            arr[left + curr_1 + curr_2 - 1] = elem;
        }
        while (curr_1 < arr1.size()) {
            int elem = arr1[curr_1];
            curr_1++;
            arr[left + curr_1 + curr_2 - 1] = elem;
        }
        while (curr_2 < arr2.size()) {
            int elem = arr2[curr_2];
            curr_2++;
            arr[left + curr_1 + curr_2 - 1] = elem;
        }
    }
};
