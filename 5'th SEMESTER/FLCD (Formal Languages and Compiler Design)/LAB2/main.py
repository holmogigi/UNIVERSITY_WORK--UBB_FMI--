from SymbolTable import *

if __name__ == '__main__':
    SymbolTable = SymbolTable(10)

    SymbolTable.Add("var1")
    print("Does item exist?", SymbolTable.HasValue("var1"))
    print("Item position = ", SymbolTable.GetValuePosition("var1"))

    SymbolTable.Add("var2")
    print("Does item exist?", SymbolTable.HasValue("var2"))
    print("Item position = ", SymbolTable.GetValuePosition("var2"))

    SymbolTable.Add("42")
    print("Does item exist?", SymbolTable.HasValue("42"))
    print("Item position = ", SymbolTable.GetValuePosition("42"))

    SymbolTable.Add("42")
    print("Does item exist?", SymbolTable.HasValue("42"))
    print("Item position = ", SymbolTable.GetValuePosition("42"))

    SymbolTable.Add("3")
    print("Does item exist?", SymbolTable.HasValue("3"))
    print("Item position = ", SymbolTable.GetValuePosition("3"))

    print(SymbolTable)
    SymbolTable.Add("27")
    SymbolTable.Delete("42")
    print(SymbolTable)
