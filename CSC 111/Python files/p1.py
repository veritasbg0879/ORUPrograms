# CSC111-03 Fall 2022
# Program 1
# Bella Goodman

number = (int(input("Give me a number please! ")))

add = 0
biggest = number
smallest = number
total = 0

while(not(number==(-1))):
    if (number % 2 == 0):
        print ("Sorry, no even numbers.")
    if (number % 2 ==1):
        total = total + 1
        add = add + number
        if (number < smallest):
            smallest = number
        if (number > biggest):
            biggest = number
    number = (int(input("What's next? ")))
    
print("The average is: ", add/total)
print("The smallest number is: ", smallest)
print("The biggest number is: ", biggest)