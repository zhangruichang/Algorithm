__author__ = 'zhangruichang'
import sys

class Node:
    def __init__(self):
        self.val = 0
        self.left = None
        self.right = None

class Solution(object):
    def closestValue(self, root, value):
        gap = abs(root.val - value)
        ans = root
        while root is not None:
            if root.val == value:
                return root.val
            elif value < root.val:
                if abs(root.val - value) < gap:
                    ans = root
                    gap = abs(root.val - value)
                root = root.left
            else:
                if abs(root.val - value) < gap:
                    ans = root
                    gap = abs(root.val - value)
                root = root.right
        return ans.val