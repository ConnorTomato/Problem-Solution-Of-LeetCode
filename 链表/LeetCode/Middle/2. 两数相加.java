/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode ptr1 = l1;
        ListNode ptr2 = l2;
        ListNode current = dummy;
        int carry = 0;
        while(ptr1 != null || ptr2 != null ){
        int ptr1val = (ptr1 != null) ? ptr1.val : 0;
        int ptr2val = (ptr2 != null) ? ptr2.val : 0;
        int sum = ptr1val + ptr2val +carry;
        carry = sum / 10;
        current.next = new ListNode(sum % 10);
        current = current.next;
       if(ptr1 != null) ptr1 = ptr1.next;
       if(ptr2 != null) ptr2 = ptr2.next;
    }
    if(carry > 0){
        current.next = new ListNode(carry);
    }
    return dummy.next;
    }
}
