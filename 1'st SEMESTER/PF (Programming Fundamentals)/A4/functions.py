"""
  Program functionalities module
"""

def get_date(x):
    return x[1]

def test_get_date():

    # Tests the get date function
    trans1 = ['add', 23, 1200, 'in', 'ooo']
    trans2 = ['insert', 1, 1467, 'out', 'yeaj']
    trans3 = ['add' , 30, 23565, 'in', 'fine']

    assert  get_date(trans1) == 23
    assert  get_date(trans2) == 1
    assert  get_date(trans3) == 30

def get_value(x):
    return x[2]

def test_get_value():

    # Tests the get value function
    trans1 = ['add', 23, 1200, 'in', 'ooo']
    trans2 = ['insert', 1, 1467, 'out', 'yeaj']
    trans3 = ['add', 30, 23565, 'in', 'fine']

    assert get_value(trans1) == 1200
    assert  get_value(trans2) == 1467
    assert get_value(trans3) == 23565

def get_type(x):
    return x[3]

def test_get_type():

    # Tests get type function
    trans1 = ['add', 23, 1200, 'in', 'ooo']
    trans2 = ['insert', 1, 1467, 'out', 'yeaj']
    trans3 = ['add', 30, 23565, 'in', 'fine']

    assert  get_type(trans1) == 'in'
    assert  get_type(trans2) == 'out'
    assert  get_type(trans3) == 'in'

def get_desc(x):
    return x[4]

def test_get_desc():

    # Tests get desc function
    trans1 = ['add', 23, 1200, 'in', 'ooo']
    trans2 = ['insert', 1, 1467, 'out', 'yeaj']
    trans3 = ['add' , 30, 23565, 'in', 'fine']

    assert get_desc(trans1) == 'ooo'
    assert  get_desc(trans2) == 'yeaj'
    assert  get_desc(trans3) == 'fine'

def get_inst(option):
    return option[0]

def test_get_inst():

    # Tests get inst function
    trans1 = ['add', 23, 1200, 'in', 'ooo']
    trans2 = ['insert', 1, 1467, 'out', 'yeaj']
    trans3 = ['add', 30, 23565, 'in', 'fine']

    assert get_inst(trans1) == 'add'
    assert get_inst(trans2) == 'insert'
    assert get_inst(trans3) == 'add'

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
        err+="!ERROR! The description is invalid!\n"
    return err

def test_add_check():

    # Tests the add check function
    trans1=['add','2','out','o','1']
    trans2=['add','i','inn','2']
    trans3=['add','245','in','aight']

    assert add_check(trans1) == 0
    assert add_check(trans2) == "!ERROR! The value inputted is invalid!\n!ERROR! The type is invalid!\n!ERROR! The description is invalid!\n"
    assert  add_check(trans3) == ''

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

def test_insert_check():

    # Tests the insert check function
    trans1=['insert','12','1237','out','piz','2']
    trans2=['insert', 'i','u','2','3']
    trans3=['insert','12','67','in','nice']

    assert insert_check(trans1) == 0
    assert  insert_check(trans2) == "!ERROR! The inputted date is invalid!\n!ERROR! The value inputted is invalid!\n!ERROR! The type is invalid!\n!ERROR! The description is invalid\n"
    assert  insert_check(trans3) == ''

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

def test_op_4_check():

    # Tests the 4'th operation check
    trans1=['remove','i','o','405']
    trans2=['remove','30','to','29']
    trans3=['remove','5','to','10']

    assert op_4_check(trans1) == "!ERROR! The start date is invalid!\n!ERROR! The end date is invalid!\n!ERROR! 'to' is spelled wrong!\n"
    assert op_4_check(trans2) == "!ERROR! The start day is greater then the end day!\n"
    assert op_4_check(trans3) == ''

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

def test_op_6_check():

    # Tests the 6'th instruction validation
    trans1=['replace','12','in','pizza','with','1200','2']
    trans2=['replace','w','oout','1','woth','o']
    trans3=['replace','12','in','pizza','with','1200']

    assert op_6_check(trans1) == 0
    assert  op_6_check(trans2) == "!ERROR! The inputted date is invalid!\n!ERROR! The inputted type in invalid!\n!ERROR! The inputted description is invalid!\n!ERROR! 'with' is spelled wrong!\n!ERROR! The inputted value is invalid!\n"
    assert  op_6_check(trans3) == ''

def op_8_check(option):

    # Validates the 8'th instruction
    err=""
    if type_check(get_date(option))==0:
        err+="!ERROR! The type inputted is invalid\n"
    return err

def test_op_8_check():

    # Tests the validation of the 8'th operation
    trans1=['list','1']
    trans2=['list','in']

    assert  op_8_check(trans1) == "!ERROR! The type inputted is invalid\n"
    assert  op_8_check(trans2) == ''

def op_9_check(option):

    # Validates the 9'th instruction
    err=""
    if value_check(get_value(option))==0:
        err+="!ERROR! The value inputted is invalid\n"
    return err

def test_op_9_check():

    # Tests the validation of the 9'th operation
    trans1=['list','=','p']
    trans2=['list','<','12']

    assert  op_9_check(trans1) == "!ERROR! The value inputted is invalid\n"
    assert  op_9_check(trans2) == ''

def op_10_check(option):

    # Validates the 10'th instruction
    err=""
    if date_check(get_value(option))==0:
        err+="!ERROR! The inputted day is invalid!\n"
    return err

def test_op_10_check():

    # Tests the validation of the 10'th instruction
    trans1=['list','balance','32']
    trans2=['list','balance','3']

    assert op_10_check(trans1) == "!ERROR! The inputted day is invalid!\n"
    assert  op_10_check(trans2) == ''

def op_11_check(option):

    # Validates the 11'th instruction
    err=""
    if len(option)!=2:
        return 0
    if type_check(get_date(option))==0:
        err+="!ERROR! The type inputted is invalid!\n"
    return err

def test_op_11_check():

    # Tests the validation of the 11'th instruction
    trans1=['sum', 'in', '2']
    trans2=['sum','oi']
    trans3=['sum','out']

    assert  op_11_check(trans1) == 0
    assert  op_11_check(trans2) == "!ERROR! The type inputted is invalid!\n"
    assert  op_11_check(trans3) == ''

def op_12_check(option):

    # Validates the 12'th instruction
    err=""
    if len(option)!=3:
        return 0
    if type_check(get_date(option))==0:
        err+="!ERROR! The type inputted is invalid!\n"
    if date_check(get_value(option))==0:
        err+="!ERROR! The inputted day is invalid!\n"
    return err

def test_op_12_check():

    # Tests the validation of the 12'th instruction
    trans1=['max','in','12','p']
    trans2=['max','op','465']
    trans3=['max','in','12']

    assert op_12_check(trans1) == 0
    assert  op_12_check(trans2) == "!ERROR! The type inputted is invalid!\n!ERROR! The inputted day is invalid!\n"
    assert  op_12_check(trans3) == ''

def op_13_check(option):

    # Validates the 13'th instruction
    err=""
    if type_check(get_date(option))==0:
        err+="!ERROR! The type inputted is invalid!\n"
    return err

def test_op_13_check():

    # Tests the validation of the 13'th instruction
    trans1=['filter','ok']
    trans2=['filter','out']

    assert op_13_check(trans1) == "!ERROR! The type inputted is invalid!\n"
    assert  op_13_check(trans2) == ''

def op_14_check(option):

    # Validates the 14'th instruction
    err=""
    if type_check(get_date(option))==0:
        err += "!ERROR! The type inputted is invalid!\n"
    if value_check(get_value(option))==0:
        err+="!ERROR! The value inputted is invalid!\n"
    return err

def test_op_14_check():

    # Tests the validation the 14'th instrucion
    trans1=['filter','2','r']
    trans2=['filter','in','7']

    assert op_14_check(trans1) == "!ERROR! The type inputted is invalid!\n!ERROR! The value inputted is invalid!\n"
    assert  op_14_check(trans2) == ''

def date_check(date):

    # Functions that checks if an input is a valid date or not
    if date.isdigit()==0:
        return 0
    else:
        date=int(date)
        if date>=1 and date<=30:
            return 1
        return 0

def test_date_check():

    # Tests the date check function
    trans1='b'
    trans2='34'
    trans3='12'

    assert date_check(trans1) == 0
    assert date_check(trans2) == 0
    assert date_check(trans3) == 1

def type_check(value):

    # Function that checks if an inputted type is valid or not
    if value=="in" or value=="out":
        return 1
    return 0

def test_type_check():

    # Tests the type check function
    trans1='in'
    trans2='3'
    trans3='i'

    assert type_check(trans1) == 1
    assert type_check(trans2) == 0
    assert type_check(trans3) == 0

def value_check(value):

    # Function that checks if an input is a number or not
    if value.isdigit()==0:
        return 0
    return 1

def test_value_check():

    # Tests the value check function
    trans1='9i'
    trans2='1234'

    assert value_check(trans1) == 0
    assert  value_check(trans2) == 1

def remove_trans_day(x,day):

    # Function that removes all transactions from the given day
    i=len(x)-1
    day=int(day)
    while i>-1:
        if x[i][0]==day:
            x.pop(i)
        i-=1

def test_remove_trans_day():

    # Tests the remove trans day function
    trans1=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party']]
    trans2=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party'],[14,5678,'out','goo']]

    remove_trans_day(trans1,'23')
    assert trans1 == [[14,79,'in','chips'],[25,65,'out','party']]
    remove_trans_day(trans2,'14')
    assert trans2 == [[23,1234,'in','food'],[25,65,'out','party']]

def remove_bet_days(x,sday,bday):

    # Function that removes all transactions between two dates (sday=first day,smaller, bday=second day,bigger)
    i=len(x)-1
    sday=int(sday)
    bday=int(bday)
    while i>-1:
        if x[i][0]>=sday and x[i][0]<=bday:
            x.pop(i)
        i-=1

def test_remove_bet_days():

    # Tests the remove bet days function
    trans1=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party'],[24,5678,'out','goo']]
    trans2=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party'],[14,5678,'out','noooo']]

    remove_bet_days(trans1,'23','26')
    assert trans1 == [[14,79,'in','chips']]
    remove_bet_days(trans2,'14','15')
    assert trans2 == [[23,1234,'in','food'],[25,65,'out','party']]

def remove_type(x,type):

    # Function that removes all transactions of the type inputted
    i=len(x)-1
    while i>-1:
        if x[i][2]==type:
            x.pop(i)
        i-=1

def test_remove_type():

    # Tests the remove type function
    trans1=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'out','party'],[24,5678,'out','goo']]
    trans2=[[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'in','party'],[24,5678,'in','goo']]

    remove_type(trans1,'in')
    assert trans1 == [[25,65,'out','party'],[24,5678,'out','goo']]
    remove_type(trans2,'out')
    assert  trans2 == [[23,1234,'in','food'],[14,79,'in','chips'],[25,65,'in','party'],[24,5678,'in','goo']]

def replace_check(x,date,desc,type,i):

    # Function that checks if there are any transactions of the given inputs
    date=int(date)
    if x[i][0]==date and x[i][2]==type and x[i][3]==desc:
        return 1
    return 0

def test_replace_check():

    # Tests the replace check function
    trans1=[[23,1400,'in','sal'],[14,79,'in','chips']]

    assert replace_check(trans1,'23','sal','in',0) == 1
    assert replace_check(trans1,'14','chips','in',1) ==1
    assert replace_check(trans1, '14', 'chips', 'in', 0) == 0

def replace(x,date,desc,type,value):

    # Function that replaces the value of the transaction in the given day
    i=0
    value=int(value)
    while i<len(x):
        if replace_check(x,date,desc,type,i)==1:
            x[i]=[int(date),int(value),type,desc]
        i+=1

def test_replace():

    # Tests the replace function
    trans1=[[23,1400,'in','sal'],[14,79,'in','chips']]

    replace(trans1,'14','chips','in','1300')
    assert trans1 == [[23,1400,'in','sal'],[14,1300,'in','chips']]

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
    return  inn-out

def test_balance():

    # Tests the balance function
    trans1=[[23,1400,'in','sal'],[14,79,'in','chips'],[19,79,'out','chip']]

    assert balance(trans1,'1') == 0
    assert balance(trans1,'14') == 79
    assert balance(trans1,'19') == 0

def sum_calc(type,x):

    # Calculates the sum of all transactions of the given type and returns it
    k=0
    i=len(x)-1
    while i>=0:
        if x[i][2]==type:
            k+=x[i][1]
        i-=1
    return k

def test_sum_calc():

    # Tests the sum calc function
    trans1=[[23,1400,'in','sal'],[14,79,'in','chips'],[19,79,'out','chip']]

    assert sum_calc('in',trans1) == 1479
    assert sum_calc('out',trans1) == 79

def max_calc(type,day,x):

    # Calcs maximum value of a transaction in day and type given and returns -1 if there is no such transaction or the index of list where the transaction is present
    day=int(day)
    max=-1
    index=0
    i=len(x)-1
    while i>=0:
        if x[i][0]==day and x[i][2]==type:
            if x[i][1]>max:
                max=x[i][1]
                index=i
        i-=1
    if max==-1:
        return -1
    else:
        return index

def test_max_calc():

    # Tests the max calc function
    trans1=[[23,1400,'in','sal'],[23,79,'in','chips'],[19,79,'out','chip']]

    assert max_calc('in','23',trans1) == 0
    assert max_calc('out','19',trans1) == 2

def filter1(type,x):

    # Deletes all other transaction that are not of the given type
    i=len(x)-1
    while i>=0:
        if x[i][2]!=type:
            x.pop(i)
        i-=1

def test_filter1():

    # Tests the filter1 function
    trans1 = [[23, 1400, 'in', 'sal'], [23, 79, 'in', 'chips'], [19, 79, 'out', 'chip']]
    trans2 = [[23, 1400, 'in', 'sal'], [23, 79, 'in', 'chips'], [19, 79, 'out', 'chip']]

    filter1('in',trans1)
    assert  trans1 == [[23, 1400, 'in', 'sal'], [23, 79, 'in', 'chips']]
    filter1('out',trans2)
    assert  trans2 == [[19, 79, 'out', 'chip']]

def filter2(type,value,x):

    # Deletes all transactions different from the given type and larger than the inputted value
    value=int(value)
    i=len(x)-1
    while i>=0:
        if x[i][2]!=type or x[i][1]>value:
            x.pop(i)
        i-=1

def test_filter2():

    # Tests the filter2 function
    trans1 = [[23, 1400, 'in', 'sal'], [23, 79, 'in', 'chips'], [19, 79, 'out', 'chip']]
    trans2 = [[23, 1400, 'in', 'sal'], [23, 79, 'in', 'chips'], [19, 79, 'out', 'chip']]

    filter2('in','100',trans1)
    assert trans1 == [[23, 79, 'in', 'chips']]
    filter2('out','1',trans2)
    assert trans2 == []

def add_to_undo(list,undo_list):

    # Adds the current list to the undo list
    undo_list.append(list[:])

def test_add_to_undo():

    # Tests the add to undo function
    undo=[]
    trans1=[[1,76,223]]
    trans2=[[4,79695,754],[1,76,223]]
    add_to_undo(trans1,undo)
    assert undo == [[[1,76,223]]]

def undo_opp(list,undo_list):

    # Undoes the last operation by changing the current list to the backup one
    list.clear()
    for i in undo_list[-1]:
        list.append(i)
    undo_list.pop()

def check_len(list):

    # Fcuntion that returns 0 if a list is empty, 1 otherwise
    if len(list)==0:
        return 0
    return 1

def test_check_len():

    # Tests the check len function
    trans1=[]
    trans2=[1,2]

    assert check_len(trans1) == 0
    assert check_len(trans2) == 1

