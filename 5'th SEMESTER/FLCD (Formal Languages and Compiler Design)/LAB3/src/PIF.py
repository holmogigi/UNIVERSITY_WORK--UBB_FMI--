class PIF:
    def __init__(self):
        self.Pairs = []

    def Add(self, token, position):
        self.Pairs.append((token, position))

    def __str__(self):
        txt = ""
        for pair in self.Pairs:
            txt += pair[0] + ' -> ' + str(pair[1]) + '\n'
        return txt
