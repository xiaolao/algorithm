# Given the head of a linked list, return the list after sorting it in ascending order.

# Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

# Example 1:

# Input: head = [4,2,1,3]
# Output: [1,2,3,4]
# Example 2:


# Input: head = [-1,5,3,4,0]
# Output: [-1,0,3,4,5]
# Example 3:

# Input: head = []
# Output: []

# Constraints:

# The number of nodes in the list is in the range [0, 5 * 104].
# -105 <= Node.val <= 105


# 解答一：归并排序（递归法）
# 题目要求时间空间复杂度分别为O(nlogn)O(nlogn)和O(1)O(1)，根据时间复杂度我们自然想到二分法，从而联想到归并排序；

# 对数组做归并排序的空间复杂度为 O(n)O(n)，分别由新开辟数组O(n)O(n)和递归函数调用O(logn)O(logn)组成，而根据链表特性：

# 数组额外空间：链表可以通过修改引用来更改节点顺序，无需像数组一样开辟额外空间；
# 递归额外空间：递归调用函数将带来O(logn)O(logn)的空间复杂度，因此若希望达到O(1)O(1)空间复杂度，则不能使用递归。
# 通过递归实现链表归并排序，有以下两个环节：

# 分割 cut 环节： 找到当前链表中点，并从中点将链表断开（以便在下次递归 cut 时，链表片段拥有正确边界）；
# 我们使用 fast,slow 快慢双指针法，奇数个节点找到中点，偶数个节点找到中心左边的节点。
# 找到中点 slow 后，执行 slow.next = None 将链表切断。
# 递归分割时，输入当前链表左端点 head 和中心节点 slow 的下一个节点 tmp(因为链表是从 slow 切断的)。
# cut 递归终止条件： 当head.next == None时，说明只有一个节点了，直接返回此节点。
# 合并 merge 环节： 将两个排序链表合并，转化为一个排序链表。
# 双指针法合并，建立辅助ListNode h 作为头部。
# 设置两指针 left, right 分别指向两链表头部，比较两指针处节点值大小，由小到大加入合并链表头部，指针交替前进，直至添加完两个链表。
# 返回辅助ListNode h 作为头部的下个节点 h.next。
# 时间复杂度 O(l + r)，l, r 分别代表两个链表长度。
# 当题目输入的 head == None 时，直接返回None。


# 解答二：归并排序（从底至顶直接合并）
# 对于非递归的归并排序，需要使用迭代的方式替换cut环节：
# 我们知道，cut环节本质上是通过二分法得到链表最小节点单元，再通过多轮合并得到排序结果。
# 每一轮合并merge操作针对的单元都有固定长度intv，例如：
# 第一轮合并时intv = 1，即将整个链表切分为多个长度为1的单元，并按顺序两两排序合并，合并完成的已排序单元长度为2。
# 第二轮合并时intv = 2，即将整个链表切分为多个长度为2的单元，并按顺序两两排序合并，合并完成已排序单元长度为4。
# 以此类推，直到单元长度intv >= 链表长度，代表已经排序完成。
# 根据以上推论，我们可以仅根据intv计算每个单元边界，并完成链表的每轮排序合并，例如:
# 当intv = 1时，将链表第1和第2节点排序合并，第3和第4节点排序合并，……。
# 当intv = 2时，将链表第1-2和第3-4节点排序合并，第5-6和第7-8节点排序合并，……。
# 当intv = 4时，将链表第1-4和第5-8节点排序合并，第9-12和第13-16节点排序合并，……。
# 此方法时间复杂度O(nlogn)O(nlogn)，空间复杂度O(1)O(1)。

# 模拟上述的多轮排序合并：
# 统计链表长度length，用于通过判断intv < length判定是否完成排序；
# 额外声明一个节点res，作为头部后面接整个链表，用于：
# intv *= 2即切换到下一轮合并时，可通过res.next找到链表头部h；
# 执行排序合并时，需要一个辅助节点作为头部，而res则作为链表头部排序合并时的辅助头部pre；后面的合并排序可以将上次合并排序的尾部tail用做辅助节点。
# 在每轮intv下的合并流程：
# 根据intv找到合并单元1和单元2的头部h1, h2。由于链表长度可能不是2^n，需要考虑边界条件：
# 在找h2过程中，如果链表剩余元素个数少于intv，则无需合并环节，直接break，执行下一轮合并；
# 若h2存在，但以h2为头部的剩余元素个数少于intv，也执行合并环节，h2单元的长度为c2 = intv - i。
# 合并长度为c1, c2的h1, h2链表，其中：
# 合并完后，需要修改新的合并单元的尾部pre指针指向下一个合并单元头部h。（在寻找h1, h2环节中，h指针已经被移动到下一个单元头部）
# 合并单元尾部同时也作为下次合并的辅助头部pre。
# 当h == None，代表此轮intv合并完成，跳出。
# 每轮合并完成后将单元长度×2，切换到下轮合并：intv *= 2。


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):

    def sortList(self, head: ListNode) -> ListNode:
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 处理边界条件
        if not head or not head.next:
            return head
        # 使用快慢两指针找到单链表的中间节点
        slow, fast = head, head.next
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        mid, slow = slow.next, None  # cut
        # 自顶向下递归切分链表
        left, right = self.sortList(head), self.sortList(mid)
        # merge left and right linked list
        t = h = ListNode()
        while left and right:
            if left.val <= right.val:
                t.next, left = left, left.next
            else:
                t.next, right = right, right.next
            t = t.next
        t.next = left if left else right
        return h.next

