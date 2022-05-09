# Problem 6
def leap_year(year):
    """
    Return 1 if the year is a leap year
    input: year
    output: 1 if leap year, 0 otherwise
    """
    if (year%4==0 and year%100!=0) or year%400==0:
        return 1
    else:
        return 0

def search(day,month1,month2):
    """
    The function searches for the month in which the day entered by the user is by comparing the previous month and the current month
    input: day-the day inputted by the user, month1;month2-the months in between we are searching for
    output: 1 if we find the right month
    """
    if day>=month1 and day<=month2:
        return 1 #=>month 2
    else:
        return 0

def month_det(day,year):
    """
    Firstly we check if the inputted year is a leap year, afterwards we create a list of the sum of the days up until the list[x] month
    input: day-the number of days inputted by the user, year-the year inputted which we use for checking whether February has 28 or 29 days(leap year)
    output: m2-the month that the inputted day corresponds to, x-the day of the month
    """
    if leap_year(year)==1:
        list=[-1, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366]
    else:
        list=[-1, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365]
    m1=0
    m2=1
    while search(day,list[m1],list[m2])==0:
        m1+=1
        m2+=1
    x=day-list[m1]+1
    return [m2,x] #using a list so that we can return multiple values from function

def month_print(month):
    """
    This function basically converts the month number into the name of the month
    input: month
    output: the name of the month
    """
    list=[0,"January","February", "March", "April", "May", "June", "July" , "August" , "September", "October", "November", "December"]
    return list[month]

day=int(input("Enter a valid day number:"))
year=int(input("Enter a valid year:"))
values=month_det(day,year)
r_month=month_print(values[0])
r_day=values[1]

#checking what ordinal number we print
if r_day==1:
    print(r_month,'',r_day,'st')
elif r_day==2:
    print(r_month,'',r_day,'nd')
elif r_day==3:
    print(r_month, '', r_day,'rd')
else:
    print(r_month, '', r_day,'th')






