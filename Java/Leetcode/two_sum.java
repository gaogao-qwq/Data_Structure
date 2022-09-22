import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
//    暴力 O(n2)
//    public static int[] twoSum(int[] nums, int target) {
//        for(int i = 0; i < nums.length; ++i) {
//            for(int j = i + 1; j < nums.length; ++j) {
//                if(nums[i] + nums[j] == target) {
//                    return new int[] {i, j};
//                }
//            }
//        }
//        return new int[0];
//    }

//    哈希表
    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; ++i) {
            if(map.containsKey(target - nums[i])) {
                return new int[] {map.get(target - nums[i]), i};
            }
            map.put(nums[i], i);
        }
        return new int[0];
    }

    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        System.out.println(Arrays.toString(twoSum(nums, 9)));
    }
}