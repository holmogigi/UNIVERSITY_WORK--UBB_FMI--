from HashTable import *


class SymbolTable:
    def __init__(self, size):
        self.Size = size
        self.HashTable = HashTable(self.Size)

    def Add(self, item):
        return self.HashTable.Add(item)

    def Delete(self, item):
        return self.HashTable.Delete(item)

    def GetValuePosition(self, item):
        return self.HashTable.GetValuePosition(item)

    def HasValue(self, item):
        return self.HashTable.HasValue(item)

    def __str__(self):
        return "SymbolTable: HashTable = " + str(self.HashTable)
