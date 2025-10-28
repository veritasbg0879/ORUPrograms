while True:
    sam = int(input("Enter lower value: "))
    sally = int(input("Enter higher value: "))
    
    if (sally>sam):
        print("Sam and Sally are OK")
        break
    else:
        print("Sam is not less than sally")
        
if ((sally%sam) == 0):
    print ("Sally is a multiple of Sam")
else:
    print ("Sally is not a multiple of Sam")
    