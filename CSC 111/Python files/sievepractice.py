from array import array

def sieve(lastIndex): #wherever we stop this is where the function goes to
    p = array('i')    #array or something
    
    p.append(2)       #adding two to each value and then doing something
    
    target = 3        #next is three 
    
    while(len(p) < lastIndex):  #while LENGTH of our p array is less than the end of the function
        prime = True            #assume it is a prime until proven otherwise
        for i in range(0, len(p)): # for a number between 0 and the integer which starts at 1
            if ((target % p[i]) == 0): #finds the remainder, is 3 divisible by p[i]? is 3 divisible by 2 equaling 0? then its not a prime
                prime = False #then break the loop if it is divisible by 2
                break #breaks our nice if loop and not the while loop
            
        if (prime):
            p.append(target) #then we're gonna add 2 and 4
            
        
        target += 1 #its four now and thats why we add two and four above
        
    return p #this is the array20

print("Name: Bella Goodman") #your name goes here

finalIndex = int(input("Enter the final index: "))

primes = sieve(finalIndex)

for i in range(0, finalIndex):
    print("Prime #%d is %d" % (i+1, primes[i]))