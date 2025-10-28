from array import array

A = array('i',(0 for i in range(0,10))) #an array with ten entries, 0-9 so you have one two three four entries up till nine
fname = input("which file do you want me to read? ")

f = open(fname, "r")

n = 0

for lineTxt in f:
    print("Got this line from text: ", end='')
    print(lineTxt, end='')
    
    
    A[n] = int(lineTxt)
    n= n+1