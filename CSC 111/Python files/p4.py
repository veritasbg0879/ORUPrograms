#CSC111-03 Fall 2022
#Program 4 - Feet/Inches to Centimeters
#Bella Goodman
print ("Bella Goodman")

feet = int(input("How many feet? "))

inch = feet*12
centimeters = inch*2.54

print("Feet \t Inches \t Centimeters")

foot = 0
inches = 1
commonCents = 2.54

for n in range (1, inch+1):
    if (inches/12 == 1):
        inches = 0
        foot += 1
    print(f"{foot} \t {inches} \t {commonCents} \n")
    inches = inches + 1
    commonCents = commonCents + 2.54
    if (foot == feet):
        break