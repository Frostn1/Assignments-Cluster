from asyncio.windows_events import NULL
from inspect import _void
from os import preadv
from re import T
from typing import List


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
        while node.prev and node.data != pos.data : node = node.prev
        while node.next and node.data != pos.data : node = node.next
        if node.data == pos.data:
            node.next = BinNode(x, node, node.next)
            return node
        return NULL

    @staticmethod
    def InsertSorted(node : BinNode, x : type[T]) -> BinNode:
        while node.next and node.data < x: node = node.next
        while node.prev and node.data > x: node = node.prev
        # 1 3 4 5 8
        # 2, 4
        if node.data > x : node.next = BinNode(x, node, node.next)
        if node.data < x : node.prev = BinNode(x, node.prev, node)
        return node

    @staticmethod
    def Build() -> BinNode:
        return NULL
    
    @staticmethod
    def Build(arr : List[int]) -> BinNode:
        node = NULL
        for val in arr:
            node = BinNodeTools.Add(node, val)
    
    @staticmethod
    def Remove(node : BinNode) -> BinNode:
        while node.prev : node = node.prev
        node = node.next
        node.prev = NULL
        return node

    @staticmethod
    def RemoveAt(node : BinNode, pos : BinNode) -> BinNode:
        while node.prev : node = node.prev
        while node.next and node.next.data != pos.data : node = node.next
        if not node.next : return NULL
        if node.next.next : node.next.next.prev = node
        node.next = node.next.next
        return node

    @staticmethod
    def Show(node : BinNode) -> None:
        while node.prev : node = node.prev
        while node.next : 
            print(node.data)
            node = node.next
        
    @staticmethod
    def ShowBackword(node : BinNode) -> None:
        while node.next : node = node.next
        while node.prev : 
            print(node.data)
            node = node.prev

    @staticmethod
    def GetLast(node : BinNode) -> BinNode:
        while node.next : node = node.next
        return node
    
    @staticmethod
    def GetPosition(node : BinNode, x : type[T]) -> BinNode:
        while node.prev and node.data != x : node = node.prev
        while node.next and node.data != x : node = node.next
        if node.data == x: return node
        return NULL