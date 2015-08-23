package leetcode;
import static java.lang.System.out;
import util.ListNode;

import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
public class MergeKLists {
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    public ListNode mergeKLists(ListNode[] lists) {  
        // write your code here
        // first comparator
        if (lists == null || lists.length == 0) {
            return null;
        }
        int len = lists.length;
        Comparator<ListNode> comparatorMin = new ComparatorMin();
        PriorityQueue<ListNode> queue = new PriorityQueue<ListNode>(len, comparatorMin);
        // null
        for (int i = 0; i < len; i++) {
            if (lists[i] != null) {
                queue.add(lists[i]);
            } 
        }
        return generate(queue);
    }
    ListNode generate(PriorityQueue<ListNode> queue) {
        if (queue.isEmpty()) {
            return null;
        }
        ListNode cur = queue.poll();
        if (cur.next != null)
            queue.add(cur.next);
        cur.next = generate(queue);
        return cur;
    }
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        
    }
}
class ComparatorMin implements Comparator<ListNode>{
    public int compare(ListNode cur, ListNode parent) {
        return cur.val - parent.val;
    }
}
