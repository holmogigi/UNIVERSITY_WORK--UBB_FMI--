from src.SymbolTable import *
from src.Scanner import *
from src.PIF import *

if __name__ == '__main__':
    SymbolTable = SymbolTable(10)
    Scanner = Scanner()
    Pif = PIF()

    program = "p1.txt"
    error = ""
    Scanner.ReadTokens()

    with open(program, 'r', encoding='utf-8-sig') as file:
        line = file.readline()
        lineIndex = 1
        for line in file:
            tokens = Scanner.GetTokensFromLine(line.strip())
            for i in range(len(tokens)):
                if tokens[i] in Scanner.GetAllTokens():
                    if tokens[i] == ' ':
                        continue
                    Pif.Add(tokens[i], (-1, -1))
                elif IsIdentifier(tokens[i]):
                    SymbolTable.Add(tokens[i])
                    identifier = tokens[i]
                    Pif.Add("identifier", SymbolTable.GetValuePosition(identifier))
                elif IsConstant(tokens[i]):
                    SymbolTable.Add(tokens[i])
                    constant = tokens[i]
                    Pif.Add("constant", SymbolTable.GetValuePosition(constant))
                else:
                    error += 'Lexical error: ' + tokens[i] + " at line " + str(lineIndex+1) + "\n"
            lineIndex += 1

    with open('PIF.out', 'w') as w:
        w.write(str(Pif))

    with open('ST.out', 'w') as w:
        w.write(str(SymbolTable))

    if error == "":
        print("Good lexically")
    else:
        print(error)

"""
1a (1 symbol table)
"""
