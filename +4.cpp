class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    // To achieve O(log(n+m)) complexity we can't merge two arrays
    // together, because it will be O(m+n). Log suggests we
    // use binary search without merging.
    //
    // We know that median is in the middle, so we need to know only
    // one half of numbers in otherwise merged array. In this case we are
    // looking for all numbers lesser than median
    //
    // We can use binary search to choose elements from one array
    // and add missing (half - amount of chosen numbers from first array)
    // from second array. Because arrays are sorted they would be consecutive.
    //
    // To assure this is the correct selection we compare
    // max numbers of two chosen subarrays
    // with min numbers of two remaining subarrays.
    //
    // If our guess wasn't correct, we use binary search
    // to either increase or decrease amount of selected numbers
    // in first subarray. Second subarray we should change accordingly.
    //
    // Doing so we get closer to the right division
    // with each iteration.
    //
    std::size_t totalLen = nums1.size() + nums2.size();
    int totalHalf = totalLen / 2;
    std::vector<int> *A = nullptr;
    std::vector<int> *B = nullptr;
    //
    // Choosing the smallest array to run binary search on for optimisation
    if (nums1.size() > nums2.size()) {
      A = &nums2;
      B = &nums1;
    } else {
      A = &nums1;
      B = &nums2;
    }
    int l = -1; // l, r - binary search bounds
    int r = A->size() - 1;
    while (true) {
      int i = (l + r) / 2; // dividing index for nums1
      int j = totalHalf - (i + 1) - 1;   // dividing index for nums2
      //
      //
      // values we gonna compare to assert correct division
      double nums1left =
          i >= 0 ? (*A)[i] : -(std::numeric_limits<double>::infinity());
      double nums1right = i + 1 < A->size()
                              ? (*A)[i + 1]
                              : std::numeric_limits<double>::infinity();
      double nums2left = j >= 0 && j < B->size()
                             ? (*B)[j]
                             : -(std::numeric_limits<double>::infinity());
      double nums2right = j + 1 < B->size()
                              ? (*B)[j + 1]
                              : std::numeric_limits<double>::infinity();
      // index j will always be less than size of second array because we 
      // chose the smallest first array, we don't need to chech  if is in
      // bounds on the right side
      //
      // for edge cases where index is out of bounds we assign infinity
      // to the values so comparison will always succed
      //
      //
      // checking if division is correct
      // if so count median
      // else next step
      if (nums1left <= nums2right && nums2left <= nums1right) {
        if (totalLen % 2) {
          return std::min(nums1right, nums2right); // odd length
        } else {
          return (std::max(nums1left, nums2left) +
                  std::min(nums1right, nums2right)) /
                 2.0;
        }
      } else if (nums1left > nums2right) {
        r = i - 1;
      } else {
        l = i + 1; // binary search steps
      }
    }
  }
};

