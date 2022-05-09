# Problem 12
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

def days_between(birth,current):
    """
    This functions calculates the age of the person in days MINUS the birth year and the current year
    input: birth-the year of birth, current-the current year
    output: the ago of the person in days between when they were born and the current year
    """
    x=current-birth-1
    days=0
    while(x!=0):
        if leap_year(x)==1:
            days+=366
        else:
            days+=365
        x-=1
    return days

def special_days(year,month,day):
    """
    The function returns the number of days the person has been alive for the first year of their life
    input: year,month,day
    output: days
    """
    if leap_year(year)==1:
        list=[0,31,29,31,30,31,30,31,31,30,31,30,31]
    else:
        list=[0,31,28,31,30,31,30,31,31,30,31,30,31]
    days=list[month]-day
    month+=1
    while month<=12:
        days+=list[month]
        month+=1
    return days

def current_year(year,month,day):
    """
    Returns the number of days the person lived this current year
    input: year,month,day
    output: days
    """
    if leap_year(year)==1:
        days=366
    else:
        days=365
    days-=special_days(year,month,day)
    return days

def result(b_year,b_month,b_day,c_year,c_month,c_day):
    """
    Calls all calculating functions and returns the age of the person in days
    input: b_year,b_month,b_day -birth date; ,c_year,c_month,c_day -current date
    output: days - the result
    """
    days=days_between(b_year,c_year)
    days+=special_days(b_year,b_month,b_day)
    days+=current_year(c_year,c_month,c_day)
    return days+1

#using thr split function so "/" is the separator
b_year,b_month,b_day=[int(b_year) for b_year in input("Enter a valid date of birth in year/month/day format: ").split("/")]
c_year,c_month,c_day=[int(c_year) for c_year in input("Enter a valid current date in year/month/day format: ").split("/")]
print("This person is:",result(b_year,b_month,b_day,c_year,c_month,c_day) ,"days old")









