#CSC111-03 Fall 2022
#Program 5
#Bella Goodman
from array import array   #/main program

def dot (l,r):
    answer = 0
    for f in range (0, len(y)):
        answer = (l[f]*r[f]) + answer
    return answer


x = array('f')  #allocate two empty arrays
y = array('f')

fname1 = input("Enter first file name: ")
fname2 = input("enter second file name: ")

with open(fname1) as f: #open the file as f, f is our handle on the file
    for line in f:      #
        x.append(float(line))

print("Bella Goodman is crying")
#next code block knows nothing about our variable
        
with open(fname2) as f2:
    for line in f2:
        y.append(float(line))

        
print("The Dot Product is: ", dot(x,y))