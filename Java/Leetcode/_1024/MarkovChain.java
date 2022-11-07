package _1024;

import java.util.*;

public class MarkovChain {
    List<List<String>> lists;
    Set<String> set;
    void solution(int[] nums, String[] opts) {
        this.lists = new ArrayList<>();
        this.set = new HashSet<>();
        set.addAll(Arrays.asList(opts));
        recur(new ArrayList<>(), nums, opts, new boolean[nums.length], new boolean[opts.length], true);
        help();
    }


    void recur(List<String> list, int[] nums, String[] opts, boolean[] used1, boolean[] used2, boolean isNum) {
        if (list.size() == 7) {
            lists.add(new ArrayList<>(list));
            return;
        }
        if (isNum) {
            for (int i = 0; i < nums.length; i++) {
                if (!used1[i]) {
                    used1[i] = true;
                    list.add(String.valueOf(nums[i]));
                    recur(list, nums, opts, used1, used2, false);
                    used1[i] = false;
                    list.remove(list.size() - 1);
                }
            }
        } else {
            for (int i = 0; i < opts.length; i++) {
                if (!used2[i]) {
                    used2[i] = true;
                    list.add(String.valueOf(opts[i]));
                    recur(list, nums, opts, used1, used2, true);
                    used2[i] = false;
                    list.remove(list.size() - 1);
                }
            }
        }
    }

    void help() {
        for (List<String> list : lists) {
            List<String> l = new ArrayList<>();
            for (int i = 0; i < list.size(); i++) {
                String s = list.get(i);
                if (i == 0 || set.contains(s)) {
                    l.add(s);
                } else {
                    String ops = l.remove(l.size() - 1);
                    int prev = Integer.parseInt(l.remove(l.size() - 1));
                    int cur = Integer.parseInt(list.get(i));
                    if (cur == 0 && (ops.equals("/") || ops.equals("%"))) {
                        break;
                    }
                    switch (ops) {
                        case "+" -> l.add(String.valueOf(prev + cur));
                        case "-" -> l.add(String.valueOf(prev - cur));
                        case "*" -> l.add(String.valueOf(prev * cur));
                        case "/" -> l.add(String.valueOf(prev / cur));
                        case "%" -> l.add(String.valueOf(prev % cur));
                        case ">>" -> l.add(String.valueOf(prev >> cur));
                        case "<<" -> l.add(String.valueOf(prev << cur));
                        case "^" -> l.add(String.valueOf(prev ^ cur));
                        case "&" -> l.add(String.valueOf(prev & cur));
                        case "|" -> l.add(String.valueOf(prev | cur));
                        case "**" -> l.add(String.valueOf((int) Math.pow(prev, cur)));
                    }
                }
            }
            if (l.size() > 0 && l.get(0).equals("1024")) {
                for (String s : list) {
                    System.out.print(s + " ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        MarkovChain markovChain = new MarkovChain();

        markovChain.solution(new int[]{
                5,0,2,1024,2,2,3
        }, new String[] {
                "&","|"
        });
    }
}
