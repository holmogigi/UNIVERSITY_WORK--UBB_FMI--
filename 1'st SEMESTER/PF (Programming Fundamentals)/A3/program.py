# Problem 4

def start():
    x=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party'],[1,76,'out','phone'],[16,1234,'in','food'],
       [27,1234,'in','gaming'],[4,79,'out','drinks'],[10,102,'out','laptop'],[30,2,'in','bank'],[19,195,'out','birthday']]
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
            op1_add(option,x,day)
        elif instruction=="insert":
            op2_add(option,x)
        elif instruction=="remove":
            if len(option)==2:
                op3_5_add(option,x)
            elif len(option)==4:
                op_4_add(option,x)
            else:
                print("!ERROR! The length of remove in invalid!")
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
                    print("!ERROR! The list input is invalid!")
            else:
                print("!ERROR! The list input is invalid!")
        elif instruction=="exit":
            exit()
        else:
            print("!ERROR! There is no such instruction available. Please check the menu!")

def print_menu():

    # The menu with all commands available
    print("\n")
    print("                                               Bank account transactions menu")
    print("Valid inputs:""\n""<day>: 1-30""\n""<value>: positive integers""\n""<type>: in (into the account) , out (from the account)""\n""<description>: a single word(string)")
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
    print("4.0  'exit'  =>  exit the application")
    print("\n")

def op1_add(option,x,day):

    # Checks if there are any errors and prints them, otherwise adds the transaction to the list
    if add_check(option)=="":
        lst = [int(day), int(option[1]), option[2], option[3]]
        x.append(lst)
    elif add_check(option)==0:
        print("!ERROR! The length of add in invalid!")
    else:
        print(add_check(option))

def op2_add(option,x):

    # Checks if there are any errors, if not the insert instruction is added to the list
    if insert_check(option)=="":
        lst = [int(get_date(option)), int(get_value(option)), get_type(option), get_desc(option)]
        x.append(lst)
    elif insert_check(option)==0:
        print("!ERROR! The length of insert in invalid!")
    else:
        print(insert_check(option))

def op3_5_add(option,x):

    # Checks both day and type inputted to see if any of them are valid, if not we get an error message
    if date_check(get_date(option)) == 1:
        remove_trans_day(x, get_date(option))
    elif type_check(get_date(option))==1:
        remove_type(x,get_date(option))
    else:
        print("!ERROR! The date/type inputted is invalid!")

def op_4_add(option,x):

    # If the input is valid we do the instruction
    if op_4_check(option)=="":
        remove_bet_days(x,get_date(option),get_type(option))
    else:
        print(op_4_check(option))

def op_6_add(option,x):

    # Prints out an error message or does the operation if nothing is wrong
    if op_6_check(option)=="":
        if replace(x,get_date(option),get_type(option),get_value(option),option[5])==0:
            print("!ERROR! There is no such transaction in the bank account!")
        else:
            replace(x, get_date(option), get_type(option), get_value(option), option[5])
    elif op_6_check(option)==0:
        print("!ERROR! The length of replace in invalid!")
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

def type_print(x,type):

    # Prints all transactions of given type, and 0 if there are no such transactions in the list
    i=0
    k=0
    while i<=len(x)-1:
        if type==x[i][2]:
            print(*x[i])
            k+=1
        i+=1
    if k==0:
        return 0

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
    test_date_check()
    test_type_check()
    test_value_check()
    test_remove_trans_day()
    test_remove_bet_days()
    test_remove_type()
    test_replace_check()
    test_replace()
    print("All tests are ok!\n")

# UI functions

# Non-UI functions

def get_date(x):
    return x[1]

def get_value(x):
    return x[2]

def get_type(x):
    return x[3]

def get_desc(x):
    return x[4]

def get_inst(option):
    return option[0]

def add_check(option):

    # Function that checks if the add instruction inputted by the user is valid
    err=""  # Using an empty string and adding errors to it when needed
    if len(option)!=4:
        return 0
    if value_check(option[1])==0:
        err+="!ERROR! The value inputted is invalid!\n"
    if type_check(option[2])==0:
        err+="!ERROR! The type is invalid!\n"
    if value_check(option[3])==1:
        err+="!ERROR! The description is invalid\n"
    return err

def insert_check(option):

    # Validates the insert instruction
    err=""
    if len(option)!=5:
        return 0
    if date_check(get_date(option))==0:
        err+="!ERROR! The inputted date is invalid!\n"
    if value_check(get_value(option))==0:
        err += "!ERROR! The value inputted is invalid!\n"
    if type_check(get_type(option))==0:
        err+="!ERROR! The type is invalid!\n"
    if value_check(get_desc(option))==1:
        err+="!ERROR! The description is invalid\n"
    return err

def op_4_check(option):

    # Validates the 4'th functionality
    err=""
    if date_check(get_date(option))==0:
        err+="!ERROR! The start date is invalid!\n"
    if date_check(get_type(option))==0:
        err+="!ERROR! The end date is invalid!\n"
    if err=="":
        if int(get_date(option))>int(get_type(option)):
            err+="!ERROR! The start day is greater then the end day!\n"
        if int(get_date(option))==int(get_type(option)):
            err+="!ERROR! The start day is the same as the end day!\n"
    if get_value(option)!="to":
        err+="!ERROR! 'to' is spelled wrong!\n"
    return err

def op_6_check(option):

    # Validates the 6'th instruction
    err=""
    if len(option)!=6:
        return 0
    if date_check(get_date(option))==0:
        err+="!ERROR! The inputted date is invalid!\n"
    if type_check(get_value(option))==0:
        err+="!ERROR! The inputted type in invalid!\n"
    if value_check(get_type(option))==1:
        err+="!ERROR! The inputted description is invalid!\n"
    if get_desc(option)!="with":
        err+="!ERROR! 'with' is spelled wrong!\n"
    if value_check(option[5])==0:
        err+="!ERROR! The inputted value is invalid!\n"
    return err

def op_8_check(option):

    # Validates the 8'th instruction
    err=""
    if type_check(get_date(option))==0:
        err+="!ERROR! The type inputted is invalid\n"
    return err

def op_9_check(option):

    # Validates the 9'th instruction
    err=""
    if value_check(get_value(option))==0:
        err+="!ERROR! The value inputted is invalid\n"
    return err

def op_10_check(option):

    # Validates the 10'th instruction
    err=""
    if date_check(get_value(option))==0:
        err+="!ERROR! The inputted day is invalid!\n"
    return err

def date_check(date):

    # Functions that checks if an input is a valid date or not
    if date.isdigit()==0:
        return 0
    else:
        date=int(date)
        if date>=1 and date<=30:
            return 1
        return 0

def type_check(value):

    # Function that checks if an inputted type is valid or not
    if value=="in" or value=="out":
        return 1
    return 0

def value_check(value):

    # Function that checks if an input is a number or not
    if value.isdigit()==0:
        return 0
    return 1

def remove_trans_day(x,day):

    # Function that removes all transactions from the given day
    i=len(x)-1
    day=int(day)
    while i>-1:
        if x[i][0]==day:
            x.pop(i)
        i-=1

def remove_bet_days(x,sday,bday):

    # Function that removes all transactions between two dates (sday=first day,smaller, bday=second day,bigger)
    i=len(x)-1
    sday=int(sday)
    bday=int(bday)
    while i>-1:
        if x[i][0]>=sday and x[i][0]<=bday:
            x.pop(i)
        i-=1

def remove_type(x,type):

    # Function that removes all transactions of the type inputted
    i=len(x)-1
    while i>-1:
        if x[i][2]==type:
            x.pop(i)
        i-=1

def replace_check(x,date,desc,type,i):

    # Function that checks if there are any transactions of the given inputs
    date=int(date)
    if x[i][0]==date and x[i][2]==type and x[i][3]==desc:
        return 1
    return 0

def replace(x,date,desc,type,value):

    # Function that replaces the value of the transaction in the given day
    i=len(x)-1
    k=0
    value=int(value)
    while i>-1:
        if replace_check(x,date,desc,type,i)==1:
            x[i][1]=value
            k+=1
        i-=1
    if k==0:
        return 0

def balance(x,day):

    # Returns the balance of the account before and during the inputted day
    i=0
    inn=0
    out=0
    day=int(day)
    while i<=len(x)-1:
        if day>=x[i][0]:
            if x[i][2]=="in":
                inn+=x[i][1]
            else:
                out+=x[i][1]
        i+=1
    return inn-out

def test_get_date():

    # Tests the get date function
    trans1 = ['add', 23, 1200, 'in', 'ooo']
    trans2 = ['insert', 1, 1467, 'out', 'yeaj']
    trans3 = ['add' , 30, 23565, 'in', 'fine']

    assert  get_date(trans1) == 23
    assert  get_date(trans2) == 1
    assert  get_date(trans3) == 30

def test_get_value():

    # Tests the get value function
    trans1 = ['add', 23, 1200, 'in', 'ooo']
    trans2 = ['insert', 1, 1467, 'out', 'yeaj']
    trans3 = ['add', 30, 23565, 'in', 'fine']

    assert get_value(trans1) == 1200
    assert  get_value(trans2) == 1467
    assert get_value(trans3) == 23565

def test_get_type():

    # Tests get type function
    trans1 = ['add', 23, 1200, 'in', 'ooo']
    trans2 = ['insert', 1, 1467, 'out', 'yeaj']
    trans3 = ['add', 30, 23565, 'in', 'fine']

    assert  get_type(trans1) == 'in'
    assert  get_type(trans2) == 'out'
    assert  get_type(trans3) == 'in'

def test_get_desc():

    # Tests get desc function
    trans1 = ['add', 23, 1200, 'in', 'ooo']
    trans2 = ['insert', 1, 1467, 'out', 'yeaj']
    trans3 = ['add' , 30, 23565, 'in', 'fine']

    assert get_desc(trans1) == 'ooo'
    assert  get_desc(trans2) == 'yeaj'
    assert  get_desc(trans3) == 'fine'

def test_get_inst():

    # Tests get inst function
    trans1 = ['add', 23, 1200, 'in', 'ooo']
    trans2 = ['insert', 1, 1467, 'out', 'yeaj']
    trans3 = ['add', 30, 23565, 'in', 'fine']

    assert get_inst(trans1) == 'add'
    assert get_inst(trans2) == 'insert'
    assert get_inst(trans3) == 'add'

def test_add_check():

    # Tests the add check function
    trans1=['add','2','out','o','1']
    trans2=['add','i','inn','2']
    trans3=['add','245','in','aight']

    assert add_check(trans1) == 0
    assert add_check(trans2) == "!ERROR! The value inputted is invalid!\n!ERROR! The type is invalid!\n!ERROR! The description is invalid\n"
    assert add_check(trans3) == ''

def test_insert_check():

    # Tests the insert check function
    trans1=['insert','12','1237','out','piz','2']
    trans2=['insert', 'i','u','2','3']
    trans3=['insert','12','67','in','nice']

    assert insert_check(trans1) == 0
    assert  insert_check(trans2) == "!ERROR! The inputted date is invalid!\n!ERROR! The value inputted is invalid!\n!ERROR! The type is invalid!\n!ERROR! The description is invalid\n"
    assert  insert_check(trans3) == ''

def test_op_4_check():

    # Tests the 4'th operation check
    trans1=['remove','i','o','405']
    trans2=['remove','30','to','29']
    trans3=['remove','5','to','10']

    assert op_4_check(trans1) == "!ERROR! The start date is invalid!\n!ERROR! The end date is invalid!\n!ERROR! 'to' is spelled wrong!\n"
    assert op_4_check(trans2) == "!ERROR! The start day is greater then the end day!\n"
    assert op_4_check(trans3) == ''

def test_op_6_check():

    # Tests the 6'th instruction validation
    trans1=['replace','12','in','pizza','with','1200','2']
    trans2=['replace','w','oout','1','woth','o']
    trans3=['replace','12','in','pizza','with','1200']

    assert op_6_check(trans1) == 0
    assert  op_6_check(trans2) == "!ERROR! The inputted date is invalid!\n!ERROR! The inputted type in invalid!\n!ERROR! The inputted description is invalid!\n!ERROR! 'with' is spelled wrong!\n!ERROR! The inputted value is invalid!\n"
    assert  op_6_check(trans3) == ''

def test_op_8_check():

    # Tests the validation of the 8'th operation
    trans1=['list','1']
    trans2=['list','in']

    assert  op_8_check(trans1) == "!ERROR! The type inputted is invalid\n"
    assert  op_8_check(trans2) == ''

def test_op_9_check():

    # Tests the validation of the 9'th operation
    trans1=['list','=','p']
    trans2=['list','<','12']

    assert  op_9_check(trans1) == "!ERROR! The value inputted is invalid\n"
    assert  op_9_check(trans2) == ''

def test_op_10_check():

    # Tests the validation of the 10'th instruction
    trans1=['list','balance','32']
    trans2=['list','balance','3']

    assert op_10_check(trans1) == "!ERROR! The inputted day is invalid!\n"
    assert  op_10_check(trans2) == ''

def test_date_check():

    # Tests the date check function
    trans1='b'
    trans2='34'
    trans3='12'

    assert date_check(trans1) == 0
    assert date_check(trans2) == 0
    assert date_check(trans3) == 1

def test_type_check():

    # Tests the type check function
    trans1='in'
    trans2='3'
    trans3='i'

    assert type_check(trans1) == 1
    assert type_check(trans2) == 0
    assert type_check(trans3) == 0

def test_value_check():

    # Tests the value check function
    trans1='9i'
    trans2='1234'

    assert value_check(trans1) == 0
    assert  value_check(trans2) == 1

def test_remove_trans_day():

    # Tests the remove trans day function
    trans1=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party']]
    trans2=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party'],[14,5678,'out','goo']]

    remove_trans_day(trans1,'23')
    assert trans1 == [[14,79,'in','chips'],[25,65,'out','party']]
    remove_trans_day(trans2,'14')
    assert trans2 == [[23,1234,'in','food'],[25,65,'out','party']]

def test_remove_bet_days():

    # Tests the remove bet days function
    trans1=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party'],[24,5678,'out','goo']]
    trans2=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party'],[14,5678,'out','noooo']]

    remove_bet_days(trans1,'23','26')
    assert trans1 == [[14,79,'in','chips']]
    remove_bet_days(trans2,'14','15')
    assert trans2 == [[23,1234,'in','food'],[25,65,'out','party']]

def test_remove_type():

    # Tests the remove type function
    trans1=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party'],[24,5678,'out','goo']]
    trans2=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'in','party'],[24,5678,'in','goo']]

    remove_type(trans1,'in')
    assert trans1 == [[25,65,'out','party'],[24,5678,'out','goo']]
    remove_type(trans2,'out')
    assert  trans2 == [[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'in','party'],[24,5678,'in','goo']]

def test_replace_check():

    # Tests the replace check function
    trans1=[[23,1400,'in','sal'],[14,79,'in','chips']]

    assert replace_check(trans1,'23','sal','in',0) == 1
    assert replace_check(trans1,'14','chips','in',1) ==1
    assert replace_check(trans1, '14', 'chips', 'in', 0) == 0

def test_replace():

    # Tests the replace function
    trans1=[[23,1400,'in','sal'],[14,79,'in','chips']]

    replace(trans1,'14','chips','in','1300')
    assert trans1 == [[23,1400,'in','sal'],[14,1300,'in','chips']]

run_tests()
start()

#  Calling the start function
