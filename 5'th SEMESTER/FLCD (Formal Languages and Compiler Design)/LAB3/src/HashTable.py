class HashTable:
    def __init__(self, size):
        self.Size = size
        self.HashTable = [None] * self.Size
        self.Count = 0
        self.LoadFactor = 0.7

    @staticmethod
    def HashFunction(key):
        hashValue = sum(ord(char) for char in key)
        return hashValue

    def Add(self, key, value):
        if self.Count / self.Size >= self.LoadFactor:
            self.ResizeTable(self.Size * 2)

        index = self.HashFunction(key) % self.Size

        while self.HashTable[index] is not None and self.HashTable[index][0] != key:
            index = (index + 1) % self.Size

        if self.HashTable[index] is None:
            self.HashTable[index] = (key, value)
            self.Count += 1
        else:
            self.HashTable[index] = (key, value)

    def GetValuePosition(self, key):
        index = self.HashFunction(key) % self.Size
        return index, key

    def ResizeTable(self, size):
        newTable = [None] * size
        for elem in self.HashTable:
            if elem is not None:
                key, value = elem
                index = self.HashFunction(key) % size
                while newTable[index] is not None:
                    index = (index + 1) % size
                newTable[index] = (key, value)
        self.Size = size
        self.HashTable = newTable

    def __str__(self):
        items = [str(entry) for entry in self.HashTable if entry is not None]
        return "[" + ", ".join(items) + "]"
