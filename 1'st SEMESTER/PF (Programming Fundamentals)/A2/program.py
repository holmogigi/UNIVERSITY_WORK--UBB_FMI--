# Prop 4 & 12

# UI section

import math  # We need the math library for sqrt

def start():

    # The start function in which we check every user input

    a=[[2,-1],[1,2],[222,1],[-3,-1],[9,5],[12,13],[-1,0],[4,6],[8,-2],[9,-3]]  # 10 complex numbers avaialble at program startup
    while True:
        print_menu()
        option = int(input("Choose a number according to your choice: "))
        print("\n")

        if option == 1:
            a.append(option_1())
            print("\n")

        elif option == 2:
            i=0
            while i<=len(a)-1:
                print_complex(a,i)
                i+=1
            print("\n")

        elif option==3:
            x=[]
            i=0
            while i<len(a):  # We create a new list in which we add the modulus of every complex number, this is indeed not necessary but it is much easier to visualise
                x.append(modulus(a[i][0], a[i][1]))
                i+=1
            values=solve_4(x)
            if values[0]==-1 or values[1]==-1:
                print("There is no such sequence")  # The program prints this if there is no such sequence in the list
            else:
                print_3_4(values,a)
            print("\n")

        elif option == 4:
            values = solve_12(a)
            if values[0] == -1 or values[1] == -1:
                print("There is no such sequence")  # Once again the program prints this if there is no such sequence in the list
            else:
                print_3_4(values, a)
            print("\n")

        elif option == 5:
            exit()  # exits the program

        else:
            print("Input is invalid, try again!")   # if the user inputs anything else than [1,5] this message is printed
            print("\n")

def print_menu():

    # The menu that the user sees

    print("Press 1 to add a complex number to the list")
    print("Press 2 to print the complex number list")
    print("Press 3 to display the longest sequence of complex numbers having increased modulus")
    print("Press 4 to display the longest sequence of complex numbers in which both real and imaginary parts can be written using the same base 10 digits")
    print("Press 5 to exit")
    print("\n")

def option_1():

    # If the user inputs 1 then he/she can add a complex number to the already existing list

    real = int(input("Choose a real part for the complex number:"))
    imaginary = int(input("Choose an imaginary part of the complex number:"))
    return [real, imaginary]

def print_3_4(values,a):

    # This function is called for printing the correct sequence for properties 4 and 12

    first=values[0]
    last=values[1]
    while first<=last:
        print_complex(a,first)
        first+=1

def print_complex(value,i):

    # Converts the list into a complex number form: a+bi

    if value[i][1]>0:
        print(f'{value[i][0]}+{value[i][1]}i')
    elif value[i][1]==0:
        print(value[i][0])
    else:
        print(f'{value[i][0]}{value[i][1]}i')

# Function section

def modulus(real,imag):

    # Calculates the modulo of a complex number: sqrt(a^2+b^2)

    return math.sqrt(real*real+imag*imag)

def solve_4(x):

    """
    Function that solves prop. 4, and returns the position index of the first and last number in the sequence
    input: x - the modulus list of the complex numbers
    output: fmax - the index of the first element in the maximum sequence , lmax - the index of the last element in the maximum sequence
    """

    i=0
    fmax=-1
    lmax=-1
    kmax=-1
    while i<len(x)-1:
        if x[i]<x[i+1]:  # We check every modulus one by one until the modulus is increasing
            k=1          # If an increasing modulus is found we give k the value 1, k is actually the length of the sequence
            ok=1
            first=i
            i+=1
            while i<len(x)-1 and ok==1:  # While loop for checking how long is this sequence, stopping when the prop. is false
                if x[i] < x[i+1]:
                    k+=1
                    i += 1
                else:
                    ok=0
            last=i
            if k>=kmax:  # Checking if this sequence is the longest found yet, if true we change fmax and lmax
                kmax=k
                fmax=first
                lmax=last
        else:
            i+=1
    return [fmax,lmax]  # The function will return either [-1,-1] or the correct position of the sequence, we check in the start function if the values are -1 and act accordingly

def solve_12(x):

    """
    Function that solves prop nr.12 and just like the one above returns the position index of the first and last number in the sequence
    input: x - the list of complex numbers
    output:  fmax - the index of the first element in the maximum sequence , lmax - the index of the last element in the maximum sequence
    """

    i = 0
    fmax = -1
    lmax = -1
    kmax = -1
    while i < len(x) - 1:
        # We go trough the whole list
        if check(freq(x[i][0],x[i][1]),freq(x[i+1][0],x[i+1][1]))==1:  # Checks if the digits of 2 consecutive numbers are the same
            k = 1
            ok = 1
            first = i
            i += 1
            while i < len(x) - 1 and ok == 1:
                if check(freq(x[i][0],x[i][1]),freq(x[i+1][0],x[i+1][1]))==1:
                    k += 1
                    i += 1
                else:
                    ok = 0
            last = i
            if k >= kmax:
                kmax = k
                fmax = first
                lmax = last
        else:
            i += 1
    return [fmax, lmax]

def freq(n,x):

    # Very important function that creates a frequency list of the real and imaginary digits of the complex number

    digits=[0]*10
    n = abs(n)  # We need the absolute values of the numbers, otherwise the while is going to infinitely loop
    x = abs(x)
    while n!=0:
        digits[n%10]=1
        n=n//10
    while x!=0:
        digits[x%10]=1
        x=x//10
    return digits

def check(d1,d2):

    # Checks if two frequency lists are identical

    i=0
    while i<=9:
        if d1[i]!=d2[i]:
            return 0
        i+=1
    return 1

start()
