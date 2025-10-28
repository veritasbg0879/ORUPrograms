# Name: Hayk Shahumyan
# CSC111 Fall 2022
# Homework 3
# Date:  9/14/2023

clans = ["Totos", "Lions", "Tigers", "Bears", "Oh My"]
print("My name is Hayk Shahumyan and my clan is ", clans[0])
numcount = 0
numavg = 0

for y in range(0,10):
    print(y)

sum = 0
for y in range(0,10):
    sum = sum + y
    numcount = numcount + 1
numavg = sum / numcount

print("sum = ", sum)

print("the average is: ", numavg)
