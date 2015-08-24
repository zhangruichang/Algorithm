package leetcode;
import java.util.*;
public class UglyNumberII {
    public static int nthUglyNumber(int n) {
        Comparator<Long> compareMin = new ComparatorMin1();
        PriorityQueue<Long> l2 = new PriorityQueue<Long>(n, compareMin); 
        PriorityQueue<Long> l3 = new PriorityQueue<Long>(n, compareMin); 
        PriorityQueue<Long> l5 = new PriorityQueue<Long>(n, compareMin);
        l2.add((long)1);
        long cur =Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            cur = Long.MAX_VALUE;
            if (l2.peek() != null && l2.peek() < cur) {
                cur = l2.peek();
            } 
            if (l3.peek() != null && l3.peek() < cur) {
                cur = l3.peek();
            }  
            if (l5.peek() != null && l5.peek() < cur) {
                cur = l5.peek();
            }
            if (cur == l2.peek()) {
                l2.poll();
                l2.add(cur * (long)2);
                l3.add(cur * (long)3);
                l5.add(cur * (long)5);
            } else if (cur == l3.peek()) {
                l3.poll();
                //l2.add(cur * 2);
                l3.add(cur * (long)3);
                l5.add(cur * (long)5);
            } else {
                l5.poll();
                //l2.add(cur * 2);
                //l3.add(cur * 3);
                l5.add(cur * (long)5);
            }
        }
        return (int)cur;
    }
    public static void main(String[] args) {
		System.out.println(nthUglyNumber(1432));
	}
}
class ComparatorMin1 implements Comparator<Long>{
    public int compare(Long cur, Long parent) {
        if(cur > parent) return 1;
        else return -1;
    }
}

