print("Bella Goodman")

int1 = (int(input("start pls ")))
int2= (int(input("finish plz ")))

for x in range (int1, (int2+1)):
    if int1 > int2:
        print("try again")
    else:
            y = x**2
            l = x**3
            print (x, y, l)
    