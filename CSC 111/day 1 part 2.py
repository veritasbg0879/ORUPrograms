def supercalifragilisticexpialidocious(a,b):
    if (a<b):
        b=a
        
    return b
#all we're doing is defining it, we aren't actually executing it at the moment. We have to invoke the function for it to happen.


x=3
y=5

print("x =",x,"y =",y)

print ("the Min is", supercalifragilisticexpialidocious(x,y)) #we call supercali... before we print because we have to call the function
#and change the values. thennnn we print it.

print("x =",x,"y =",y)