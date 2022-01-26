from asyncio.windows_events import NULL
from os import preadv
from re import T
from tokenize import Binnumber


class BinNode:
    def __init__(self, val : type[T], prev, next):
        self.data = val
        self.prev = prev
        self.next = next
        if prev : prev.next = self
        if next : next.prev = self

class BinNodeTools:
    
    @staticmethod
    def Add(node : BinNode, x : type[T]) -> BinNode:
        while node.prev : node = node.prev
        node.prev = BinNode(x, NULL, node)
        return node
    
    @staticmethod
    def Insert(node : BinNode, pos : BinNode, x : type[T]) -> BinNode:
        if not pos: return BinNodeTools.Add(node, x)
        while node.prev : node = node.prev
        while node.next and node.data != pos.data : node = node.next
        if node.data == pos.data:
            node.next = BinNode(x, node, node.next)
            return node
        return NULL

    def InsertSorted(node : BinNode, x : type[T]) -> BinNode:
        while node.next and node.data < x: node = node.next
        while node.prev and node.data > x: node = node.prev
        # 1 3 4 5 8
        # 2, 4
        if node.data > x : node.next = BinNode(x, node, node.next)
        if node.data < x : node.prev = BinNode(x, node.prev, node)
        return node
