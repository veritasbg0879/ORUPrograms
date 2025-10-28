print("a b c | y")
print("---------")
for a in range(0,2):
    for b in range(0,2):
        for c in range(0,2):
            y = (not (a or(b*c)) or (not (b*c)))
            print ("%d %d %d | %d" % (a,b,c,y))