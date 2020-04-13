# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#Time complexity: O(n)-n is the number of nodes in the given list.... Space complexity: O(1)
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        moveOne = moveTwo = head
        while moveTwo and moveTwo.next:
            moveOne = moveOne.next
            moveTwo = moveTwo.next.next
        return moveOne