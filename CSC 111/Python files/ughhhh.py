# CSC111-03 Fall 2022
# Program 1
# Bella Goodman
sigh1 = int(input("gimme a number please: "))
if sigh1 == (-1):
    print("you can't start with that number.")

if (sigh1%2==0):
    print ("that's even, try again.")
 
if (sigh1 % 2 == 1):
    count += 1
    add += sigh1
    add = sigh1
    add % count
        
def small (x, y):
    if (x < y):
        y = x
        return y
    
def big (a, z):
    if (a < z):
        a = z
        return a
    
def add (p, k):
    p + k
    return p

def avg (u, l):
    add(u,l)
    add % 2
    return add

count = 0
add = 0
big = sigh1
small = sigh1


while True:
    sigh2 = (int(input("give me another number please: ")))
    if sigh2 == (-1):
        break
    if (sigh2%2==0):
        print ("that's even, try again.")

print("the min is: ", small(sigh1, sigh2))
print("the max is: ", big(sigh1, sigh2))
print("the avg is: ", avg(sigh1, sigh2))
# define the average later
