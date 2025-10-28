#CSC111-03 Fall 2022
#Program 2
#Bella Goodman
from array import array

def createArray(x, type):
    newArray = array(x, type)
    for i in range(0, x):
        newArray.append(0)
    return newArray

n = int(input("hey lil mama "))

aaa = createArray(n, 'f')
bbb = createArray(n, 'f')
                 
for i in range (0,n):
    print(aaa[i])
    
    
    
index = 0
total = 0

fname = input("which file do you want me to read? ")
f = open(fname, "r")

for lineTxt in f:
    aaa[index]= float(lineTxt)
    index += 1
    
index = 0
for number in aaa:
    bbb[index] = aaa[index]
    index += 1
    
index = 0   
for number in aaa:        
    total = (aaa[index] * bbb[index]) + total
    index += 1