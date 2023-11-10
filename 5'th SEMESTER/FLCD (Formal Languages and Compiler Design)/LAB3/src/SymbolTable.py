from src.HashTable import *


class SymbolTable:
    def __init__(self, size):
        self.Size = size
        self.HashTable = HashTable(self.Size)
        self.Count = 0

    def Add(self, item):
        self.Count += 1
        return self.HashTable.Add(item, self.Count)

    def GetValuePosition(self, item):
        return self.HashTable.GetValuePosition(item)

    def __str__(self):
        return "SymbolTable: HashTable = " + str(self.HashTable)
