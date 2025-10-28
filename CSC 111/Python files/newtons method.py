def myRoots(l,y):
    x = 3
    diff = 0.1
    while diff > 0.0000001:
        xNew = x - (((x**y)-l)/(y*(x**(y-1))))
        diff = abs(xNew-x)
        x = xNew
    return x

userInput = int(input("take the root of: "))
input2 = int(input("to the...  "))

print ("the %s root of %s is equal to " % (input2, userInput), myRoots(userInput,input2))
print ("ans **i is ",(myRoots(userInput,input2))**input2)