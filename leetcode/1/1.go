func twoSum(nums []int, target int) []int {
    for i := 0; i < len(nums); i++ {
        for j := i; j < len(nums); j++ {
            if (j == i) {
                continue
            }

            if (nums[i] + nums[j] == target) {
                sum := []int{i, j};
                return sum;
            }
        }
    }

    return nil;
}
