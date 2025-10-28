#CSC111-03 Fall 2022
#Program 2
#Bella Goodman
from array import array
aaa = array('f',(0 for i in range(0,10)))
bbb = array('f',(0 for i in range(0,10)))

slot = 0
count = 0

fname = input("which file do you want me to read? ")
f = open(fname, "r")

for lineTxt in f:
    aaa[slot]= float(lineTxt)
    slot += 1
    
slot = 0
for number in aaa:
    bbb[slot] = aaa[slot]
    slot += 1
    
slot = 0   
for number in aaa:        
    count = (aaa[slot] * bbb[slot]) + count
    slot += 1
    
    
print("the Dot Product is... ", count)