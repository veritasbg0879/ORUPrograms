print("a b | y")
print("---------")
for a in range(0,2):
    for b in range(0,2):
            y = not(not(a*b))
            print ("%d %d | %d" % (a,b,y))
