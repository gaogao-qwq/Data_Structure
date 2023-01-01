package doublePointer;

class Solution {
    public String largestMerge(String word1, String word2) {
        StringBuilder merge = new StringBuilder();
        while (word1.length() + word2.length() > 0) {
            if (word1.compareTo(word2) > 0) {
                merge.append(word1.charAt(0));
                word1 = word1.substring(1);
            } else {
                merge.append(word2.charAt(0));
                word2 = word2.substring(1);
            }
        }
        return merge.toString();
    }
}

class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.largestMerge("cabaa", "bcaaa"));
    }
}