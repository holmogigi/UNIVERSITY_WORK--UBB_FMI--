#Problem 5
def prime_num_verify(nr):
    """
    Return 1 if the given number is a prime number, otherwise return 0
    input: nr - the number that needs to be verified
    output: 1 if the number is prime, 0 if the number is !prime
    """
    if nr < 2: #Firstly we check if the number is smaller than 2, if this statement is true we return 0 because there is no prime number smaller then 2
        return 0
    if nr==2: #2 is the only even prime number so we check it before returning 0 if nr is even
        return 1
    if nr%2==0:
        return 0
    d=3  #we already checked everything <=2 so we can start the while statement from 3
    while nr>=d*d: #the while statement checks if nr has any divisors, if the statement is true the function returns 0
        if nr%d==0 :
            return 0
        d+=2 #the function already checked all even numbers so we only need to check odd divisors
    return 1 #returning 1 if the number has no proper divisors which means the number is a prime

def x_start(n):
    """
     Return the number that we need to check first, prime numbers are mostly odd so we only need to check odd numbers
     input: n - the number we need to start searching from
     output: n-1 if the number is even, n-2 otherwise
    """
    if n==3: #the function is not going to work if the number is 3 because it will skip straight to 1, but 2 is the greatest smaller than n prime number
        return n-1
    if n % 2:
        return n - 2 #if n is even we need to start from next smaller number
    else:
        return n - 1 #if n is odd we can skip the even number smaller than it

def verify(n):
    """
    Return whether there exists a prime number smaller than n
    input: n - the number we check
    output: 1 if a smaller prime number then x exists, otherwise 0
    """
    if n<=2: #there are no prime numbers under 2
        return 0
    else:
        return 1

def result(n):
    """
    Returns the previous prime number behind n
    input: n - the input number
    output: x - the number we are searching for
    """
    x = int(x_start(n))
    while prime_num_verify(x)==0: #we keep searching for the first prime number smaller then n
        x-=2
    return x

n=int(input())
if verify(n)==0:
    print("There is no smaller prime number than", n)
else:
    print(result(n))






