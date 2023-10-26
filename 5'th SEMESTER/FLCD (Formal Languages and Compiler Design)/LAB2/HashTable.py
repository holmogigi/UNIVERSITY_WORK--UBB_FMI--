class HashTable:
    def __init__(self, size):
        self.Size = size
        self.HashTable = []
        for index in range(self.Size):
            self.HashTable.append([])

    def GetSize(self):
        return self.Size

    def HashFunction(self, key):
        hashValue = 0
        for char in key:
            hashValue += ord(char.lower())
        return hashValue % self.Size

    def GetHashValue(self, key):
        if isinstance(key, str):
            return self.HashFunction(key)
        return -1

    def HasValue(self, key):
        hashValue = self.GetHashValue(key)
        if hashValue != -1:
            for value in self.HashTable[hashValue]:
                if value == key:
                    return True
        return False

    def Add(self, key):
        hashValue = self.GetHashValue(key)
        self.HashTable[hashValue].append(key)

    def Delete(self, key):
        hashValue = self.GetHashValue(key)
        if key in self.HashTable[hashValue]:
            self.HashTable[hashValue].remove(key)

    def GetValuePosition(self, key):
        hashValue = self.GetHashValue(key)
        if hashValue != -1:
            return hashValue
        return -1

    def __str__(self):
        return str(self.HashTable)
