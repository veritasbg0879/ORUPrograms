from array import array

amount = 10


#program 2

#objective: 
#- array A pulls numbers from a file and copies them into array B. 
#- A slot 1 and B slot 1 are multiplied || (square slot 1 array A)
#- then add the multiplications

#variables required:


A = array('i',[0]*amount)
B = array('i',[0]*amount)

for i in range (0, amount):
    x[i] = float(input("Enter next number: "))
    

f = open(fname, "r")
n = 0

for lineTxt in f:
    print("Got this line: ")
sum = 0
a = 2
b = 5
sum += a * b
print(sum)






from array import array
open fname py2-input.txt

A = array('i',(0 for i in range(0,10))) #an array with ten entries, 0-9 so you have one two three four entries up till nine
fname = input("which file do you want me to read? ")

f = open(fname, "r")

n = 0

for i in range (0, amount):
    print("Got this line from text: ", end='')
    print(lineTxt, end='')
    
    A[n] = float(lineTxt)
    n= n+1
A = array('i',[0]*amount)
B = array('i',[0]*amount)




