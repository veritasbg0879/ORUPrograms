#CSC111-03 Fall 2022
#Program 6 - Modified Sieve
#Bella Goodman

from math import sqrt
from array import array

def sieve(lastIndex):
    p = array('i')
    
    p.append(2)
    
    test = 3
    
    while(len(p) < lastIndex):
        
        for i in range(0, len(p)):
            if ((test % p[i] == 0)):
                prime = False
                break
            if (sqrt(test) < p[i]):
                prime = True
                break
            
        if (prime):
            p.append(test)
        
        test += 2
        
    return p

print("Name: Bella Goodman")

finalIndex = int(input("Enter the final index: "))

primes = sieve(finalIndex)

print("Prime #%d is %d" % (finalIndex, primes[-1]))