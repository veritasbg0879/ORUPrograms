print("a b c | y")
print("---------")
for a in range(0,8):
    for b in range(0,1):
        for c in range(0,1):
            a = int(0)
            b = int (1)
            c = int (1)
            y = (not (a or(b*c)) or (not (b*c)))
            print (a, b, c, y)