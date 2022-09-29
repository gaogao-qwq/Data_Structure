package hashTable;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    // 哈希表
    public static boolean CheckPermutation(String s1, String s2) {
        if(s1.length() != s2.length()) return false;
        // 初始化
        HashMap<Character, Integer> hmap = new HashMap<>();
        // 遍历s1每一位并映射哈希表
        for(int i = 0; i < s1.length(); ++i) {
            int cnt = hmap.getOrDefault(s1.charAt(i), 0);
            hmap.put(s1.charAt(i), cnt + 1);
        }
        for(int i = 0; i < s2.length(); ++i) {
            if(hmap.containsKey(s2.charAt(i))) {
                hmap.put(s2.charAt(i), hmap.get(s2.charAt(i)) - 1);
                continue;
            }
            return false;
        }
        for(Map.Entry<Character, Integer> entry : hmap.entrySet()) {
            if(entry.getValue() != 0) return false;
        }
        return true;
    }

    // 偷鸡做法，排序
    public static boolean CheckPermutationSort(String s1, String s2) {
        if(s1.length() != s2.length()) return false;
        char[] str1 = s1.toCharArray();
        char[] str2 = s2.toCharArray();
        Arrays.sort(str1);
        Arrays.sort(str2);
        return Arrays.equals(str1, str2);
    }

    public static void main(String[] args) {
        String s1 = "asvnpzurz", s2 = "urzsapzvn";
        System.out.print(CheckPermutation(s1, s2));
    }
}
