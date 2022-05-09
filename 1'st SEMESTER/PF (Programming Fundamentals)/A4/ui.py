"""
  User interface module
"""
from functions import *

def start():
    x=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party'],[1,76,'out','phone'],[16,1234,'in','food'],
       [27,1234,'in','gaming'],[4,79,'out','drinks'],[10,102,'out','laptop'],[30,2,'in','bank'],
       [19,195,'out','birthday']]
    undo_list=[]
    add_to_undo(x,undo_list)
    ok=True

    while ok:

        # Asking the user for the current day until the date inputted is valid
        day=input("Enter the current date(1-30): ")
        if date_check(day)==0:
            print("!ERROR! Inputted day is inavlid. Try again!")
        else:
            ok=False

    while True:

        # Loop that prints the menu and checks the instruction inputted
        print_menu()
        option=list(input("Type your choice: ").split())   # User input is put in a list
        instruction=get_inst(option)  # Instruction is the first word the user inputted
        if instruction=="add":   # We check if the instruction inputted matches the valid functionalities
            op1_add(option,x,day,undo_list)
        elif instruction=="insert":
            op2_add(option,x,undo_list)
        elif instruction=="remove":
            if len(option)==2:
                op3_5_add(option,x,undo_list)
            elif len(option)==4:
                op_4_add(option,x,undo_list)
            else:
                print("!ERROR! The length of remove in invalid!\n")
        elif instruction=="replace":
            op_6_add(option,x)
        elif instruction=="list":
            if len(option)==1:
                op_7_add(option,x)
            elif len(option)==2:
                op_8_add(option,x)
            elif len(option)==3:
                if get_date(option)=="balance":
                    op_10_add(option,x)
                elif get_date(option)=="<" or get_date(option)==">" or get_date(option)=="=":
                    op_9_add(option,x)
                else:
                    print("!ERROR! The list input is invalid!\n")
            else:
                print("!ERROR! The list input is invalid!\n")
        elif instruction=="sum":
            op_11_add(option,x)
        elif instruction=="max":
            op_12_add(option,x)
        elif instruction=="filter":
            if len(option)==2:
                op_13_add(option,x,undo_list)
            elif len(option)==3:
                op_14_add(option,x,undo_list)
            else:
                print("!ERROR! The length of filter input is invalid\n")
        elif instruction=="undo":
            if len(option)==1:
                if check_len(undo_list)==0:
                    print("!ERROR! There is no operation to undo!\n")
                else:
                    undo_opp(x,undo_list)
            else:
                print("!ERROR! The length of 'undo' is invalid\n")
        elif instruction=="exit":
            exit()
        else:
            print("!ERROR! There is no such instruction available. Please check the menu!")

def print_menu():

    # The menu with all commands available
    print("\n")
    print("                                               Bank account transactions menu")
    print("Valid inputs:""\n""<day>: 1-30""\n""<value>: positive integers""\n"
          "<type>: in (into the account) , out (from the account)""\n""<description>: a single word(string)")
    print("\n")
    print("1.1  'add <value> <type> <description>'  =>  adding the transaction in the current date")
    print("1.2  'insert <day> <value> <type> <description>'  =>  inserting a transaction in the given day")
    print("\n")
    print("2.1  'remove <day>'  =>  removing all transactions from inputted day")
    print("2.2  'remove <start day> to <end day>'  =>  remove all transactions between the given days")
    print("2.3  'remove <type>'  =>  remove all transactions of the inputted type")
    print("2.4  'replace <day> <type> <description> with <value>'  =>  replace the initial value with the new inputted value")
    print("\n")
    print("3.1  'list'  =>  display all transactions")
    print("3.2  'list <type>'  =>  display all transactions with the given type")
    print("3.3  'list [<],[=],[>] <value>'  =>  display all transactions having an amount of money <,>,= to value inputted")
    print("3.4  'list balance <day>'  =>  the difference between in and out transactions before and on inputted day")
    print("\n")
    print("4.1 'sum' <type>  =>  display the total amount of all transaction of given type")
    print("4.2 'max' <type> <day>  =>  display the maximum transaction of given type in given day")
    print("\n")
    print("5.1 'filter' <type>  =>  keep only transactions of given type")
    print("5.2 'filter' <type> <value>  =>  keep only transactions of given type smaller than inputted value")
    print("\n")
    print("6.1 'undo'  =>  the last operations can be reversed")
    print("\n")
    print("7.0  'exit'  =>  exit the application")
    print("\n")

def op1_add(option,x,day,undo_list):

    # Checks if there are any errors and prints them, otherwise adds the transaction to the list
    if add_check(option)=="":
        add_to_undo(x,undo_list)
        lst = [int(day), int(option[1]), option[2], option[3]]
        x.append(lst)
    elif add_check(option)==0:
        print("!ERROR! The length of add in invalid!\n")
    else:
        print(add_check(option))

def op2_add(option,x,undo_list):

    # Checks if there are any errors, if not the insert instruction is added to the list
    if insert_check(option)=="":
        add_to_undo(x, undo_list)
        lst = [int(get_date(option)), int(get_value(option)), get_type(option), get_desc(option)]
        x.append(lst)
    elif insert_check(option)==0:
        print("!ERROR! The length of insert in invalid!\n")
    else:
        print(insert_check(option))

def op3_5_add(option,x,undo_list):

    # Checks both day and type inputted to see if any of them are valid, if not we get an error message
    if date_check(get_date(option)) == 1:
        add_to_undo(x, undo_list)
        remove_trans_day(x, get_date(option))
    elif type_check(get_date(option))==1:
        add_to_undo(x, undo_list)
        remove_type(x,get_date(option))
    else:
        print("!ERROR! The date/type inputted is invalid!\n")

def op_4_add(option,x,undo_list):

    # If the input is valid we do the instruction
    if op_4_check(option)=="":
        add_to_undo(x, undo_list)
        remove_bet_days(x,get_date(option),get_type(option))
    else:
        print(op_4_check(option))

def op_6_add(option,x):

    # Prints out an error message or does the operation if nothing is wrong
    if op_6_check(option)=="":
        replace(x, get_date(option), get_type(option), get_value(option), option[5])
    elif op_6_check(option)==0:
        print("!ERROR! The length of replace in invalid!\n")
    else:
        print(op_6_check(option))

def op_7_add(option,x):

    # Prints the whole transaction list
    print(*x)

def op_8_add(option,x):

    # Checks if the type is valid, if not error message printed, else all transaction of type are printed
    if op_8_check(option)=="":
        type_print(x, get_date(option))
    else:
        print(op_8_check(option))

def op_9_add(option,x):

    # Checks if the value inputted is valid and prints out the error message or the valid transactions
    if op_9_check(option)=="":
        print(money(x, get_date(option), get_value(option)))
    else:
        print(op_9_check(option))

def op_10_add(option,x):

    # Checks if there are any errors and prints out the balance if there are no problems
    if op_10_check(option)=="":
        print(balance(x,get_value(option)))
    else:
        print(op_10_check(option))

def op_11_add(option,x):

    # Checks if there are any errors and prints out the error message or the sum of the given type
    if op_11_check(option)==0:
        print("!ERROR! The length of sum is invalid!\n")
    elif op_11_check(option)=="":
        print(sum_calc(get_date(option),x))
    else:
        print(op_11_check(option))

def op_12_add(option,x):

    # Checks if there are any errors and prints the error message or the maximum transaction of the given type in given day
    if op_12_check(option)==0:
        print("!ERROR! The length of max is invalid!\n")
    elif op_12_check(option)=="":
        if max_calc(get_date(option),get_value(option),x)==-1:
            print("!ERROR! There is no transaction that matches the input\n")
        else:
            print(x[max_calc(get_date(option),get_value(option),x)])
    else:
        print(op_12_check(option))

def op_13_add(option,x,undo_list):

    # Checks if there are any errors in the input of the first filter and prints out an error message or deletes all transactions different from the given type
    if op_13_check(option)=="":
        add_to_undo(x, undo_list)
        filter1(get_date(option),x)
    else:
        print(op_13_check(option))

def op_14_add(option,x,undo_list):

    # Checks if there are any errors in the input of the second filter and prints out an error message or deletes all needed transactions
    if op_14_check(option)=="":
        add_to_undo(x, undo_list)
        filter2(get_date(option),get_value(option),x)
    else:
        print(op_14_check(option))

def money(x,instr,mone):

    # Checks the input by the user and prints all transactions that match the given input, if no such transactions are found the function returns 0
    i=0
    k=0
    mone=int(mone)
    if instr==">":
       while i<=len(x)-1:
           if mone<x[i][1]:
                print(x[i])
                k+=1
           i+=1
       return k
    elif instr=="=":
        while i <= len(x) - 1:
            if mone == x[i][1]:
                print(x[i])
                k += 1
            i += 1
        return k
    elif instr=="<":
        while i <= len(x) - 1:
            if mone > x[i][1]:
                print(x[i])
                k += 1
            i += 1
        return k

def type_print(x,type):

    # Prints all transactions of given type, and 0 if there are no such transactions in the list
    i=0
    k=0
    while i<=len(x)-1:
        if type==x[i][2]:
            print(x[i])
            k+=1
        i+=1
    if k==0:
        return 0

def run_tests():

    # Runs the tests
    print("Running tests...")
    test_get_type()
    test_get_date()
    test_get_desc()
    test_get_inst()
    test_get_value()
    test_add_check()
    test_insert_check()
    test_op_4_check()
    test_op_6_check()
    test_op_8_check()
    test_op_9_check()
    test_op_10_check()
    test_op_11_check()
    test_op_12_check()
    test_op_13_check()
    test_op_14_check()
    test_date_check()
    test_type_check()
    test_value_check()
    test_remove_trans_day()
    test_remove_bet_days()
    test_remove_type()
    test_replace_check()
    test_replace()
    test_balance()
    test_sum_calc()
    test_max_calc()
    test_filter1()
    test_filter2()
    test_check_len()
    test_add_to_undo()
    print("All tests are ok!\n")
