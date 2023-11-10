import re


def IsIdentifier(elem):
    return re.match(r'^[a-zA-Z]([a-zA-Z]|[0-9])*$', elem) is not None


def IsConstant(elem):
    return re.match(r'^(-?[1-9]+[0-9]*|0)$', elem) is not None


class Scanner:

    def __init__(self):
        self.ReservedWords = []
        self.Separators = []
        self.Operators = []

    def GetReservedWords(self):
        return self.ReservedWords

    def GetSeparators(self):
        return self.Separators

    def GetOperators(self):
        return self.Operators

    def GetAllTokens(self):
        return self.ReservedWords + self.Separators + self.Operators

    def IsOperator(self, elem):
        for op in self.Operators:
            if elem in op:
                return True
        return False

    def ReadTokens(self):
        with open('Token.in', 'r', encoding='utf-8-sig') as file:
            for i in range(14):
                self.Operators.append(file.readline().strip())
            for i in range(11):
                separator = file.readline().strip()
                if separator == 'space':
                    self.Separators.append(" ")
                else:
                    self.Separators.append(separator)
            for i in range(12):
                self.ReservedWords.append(file.readline().strip())

    @staticmethod
    def String(token, tokens, line, i):
        if len(token) > 0:
            tokens.append(token)
        token = '\''
        end_string = False
        i += 1
        while i < len(line) and not end_string:
            if line[i] == '\'':
                end_string = True
            token += line[i]
            i += 1
        tokens.append(token)
        token = ''
        return token, tokens, i

    def Operator(self, token, tokens, line, i):
        if len(token) > 0:
            tokens.append(token)
        token = ''
        while i < len(line) and self.IsOperator(line[i]):
            token += line[i]
            i += 1
        tokens.append(token)
        token = ''
        return token, tokens, i

    @staticmethod
    def Separator(token, tokens, line, i):
        if len(token) > 0:
            tokens.append(token)
        token = line[i]
        i += 1
        tokens.append(token)
        token = ''
        return token, tokens, i

    def GetTokensFromLine(self, line):
        token = ''
        tokens = []
        i = 0
        while i < len(line):
            if line[i] == '\'':
                token, tokens, i = self.String(token, tokens, line, i)
            elif self.IsOperator(line[i]):
                token, tokens, i = self.Operator(token, tokens, line, i)
            elif line[i] in self.Separators:
                token, tokens, i = self.Separator(token, tokens, line, i)
            else:
                token += line[i]
                i += 1
        if len(token) > 0:
            tokens.append(token)
        return tokens
