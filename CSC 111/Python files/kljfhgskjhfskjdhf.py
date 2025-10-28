from array import array

x = int(input("gimme a number "))
a = array('i',(10))

while x != -1:
    if x % 2 == 1:
        a.append(x);
    