
import time
import random

y = 0
n = 0
x = 0

highestNumber = 0

print("This program will show you some numbers from 1 to 50")

for i in range(10):
    n = random.randint(1,50)
    if n > highestNumber:
        highestNumber = n
    x = highestNumber
    print(n,end = "\r")
    time.sleep(2)

newInput = int(input("number? "))

if newInput == highestNumber:
    print("good job")
else:
    print("no")
