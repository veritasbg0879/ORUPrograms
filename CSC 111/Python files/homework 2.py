#CSC111-03 Fall 2022
#Program 2
#Bella Goodman
from array import array
aaa = array('f',(0 for i in range(0,10)))
bbb = array('f',(0 for i in range(0,10)))

cheese = 0
sigh = 0

fname = input("which file do you want me to read? ")
f = open(fname, "r")

for lineTxt in f:
    aaa[cheese]= float(lineTxt)
    cheese += 1
    
cheese = 0
for number in aaa:
    bbb[cheese] = aaa[cheese]
    cheese += 1
    
cheese = 0   
for number in aaa:        
    sigh = (aaa[cheese] * bbb[cheese]) + sigh
    cheese += 1
print("the Dot Product is... ", sigh)