class Solution {
public:
    vector<int> temp;

    int merge(vector<int>& nums, int start, int mid, int end){
        int i = start, j = mid+1, cn = 0;
        int n = nums.size();
        
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
                cn += mid - i + 1;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i++]);
        }
        while(j <= end){
            temp.push_back(nums[j++]);
        }

        for(int x = start; x <= end; x++){
            nums[x] = temp[x-start];
        }
        temp.clear();
        return cn;
    }

    int mergesort(vector<int>& nums, int start, int end){
        //base case
        if(start >= end){
            return 0;
        }

        int mid = start + (end-start)/2;
        long long cn = 0;
        cn += mergesort(nums, start, mid);
        cn += mergesort(nums, mid+1, end);
        cn += merge(nums, start, mid, end);
        return cn;
    }

    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int local = 0; 

        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                local++;
            }
        }

        int global = mergesort(nums, 0, n-1);

        return global == local;
    }
};
//     int merge(vector<int> &nums, int low, int mid, int high) {
//     vector<int> temp; // temporary array
//     int left = low;      // starting index of left half of arr
//     int right = mid + 1;   // starting index of right half of arr

//     //Modification 1: cnt variable to count the pairs:
//     int cnt = 0;

//     //storing elements in the temporary array in a sorted manner//

//     while (left <= mid && right <= high) {
//         if (nums[left] <= nums[right]) {
//             temp.push_back(nums[left]);
//             left++;
//         }
//         else {
//             temp.push_back(nums[right]);
//             cnt += (mid - left + 1); //Modification 2
//             right++;
//         }
//     }

//     // if elements on the left half are still left //

//     while (left <= mid) {
//         temp.push_back(nums[left]);
//         left++;
//     }

//     //  if elements on the right half are still left //
//     while (right <= high) {
//         temp.push_back(nums[right]);
//         right++;
//     }

//     // transfering all elements from temporary to arr //
//     for (int i = low; i <= high; i++) {
//         nums[i] = temp[i - low];
//     }

//     return cnt; // Modification 3
// }

// int mergeSort(vector<int> &nums, int low, int high) {
//     int cnt = 0;
//     if (low >= high) return cnt;
//     int mid = (low + high) / 2 ;
//     cnt += mergeSort(nums, low, mid);  // left half
//     cnt += mergeSort(nums, mid + 1, high); // right half
//     cnt += merge(nums, low, mid, high);  // merging sorted halves
//     return cnt;
// }
    
// public:
//     bool isIdealPermutation(vector<int>& nums) {
//         int n = nums.size();
        
//         for (int i = 0; i < n; ++i) {
//             // Check if any number is more than 1 position away from its original position
//             if (abs(nums[i] - i) > 1) {
//                 return false;
//             }
//         }
        
//         return true;
// //         int localCount = 0;
// //         int n = nums.size();
// //         vector<int> numsCopy = nums;
// //         int globalCount = mergeSort(numsCopy, 0, n - 1);
        
// //         for(int i=0; i<n-1; i++)
// //         {
// //             if(nums[i]>nums[i+1])
// //             {
// //                 localCount++;
// //             }
// //         }
        
// //         return globalCount==localCount?true:false;
//     }
// };