package backTracking;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class Solution {
    public static Deque<Integer> path = new ArrayDeque<>();
    public static List<List<Integer>> ans = new ArrayList<>();
    public static void backTracking(int n, int k, int startIndex) {
        // 终止条件
        if(path.size() == k) {
            ans.add(new ArrayList<>(path));
            return;
        }
        for(int i = startIndex; i <= n; ++i) {
            path.addLast(i);
            backTracking(n, k, i + 1);
            path.removeLast();
        }
    }
    public static List<List<Integer>> combine(int n, int k) {
        backTracking(n, k, 1);
        return ans;
    }

    public static void main(String[] args) {
        List<List<Integer>> ans = combine(1,1);
        System.out.print(ans);
    }
}
