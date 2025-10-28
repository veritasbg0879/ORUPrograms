#CSC111-03 Fall 2022
#Program 3 - Simple GPA
#Bella Goodman


grade = float(input("Please type in a grade you have recieved: "))

a = 0
b = 0
c = 0
d = 0
f = 0
gpa = 0
count = 1

while (not(grade == (-1))):
    if grade >= 90:
        print("nice job! that's an A!")
        a += 1
        gpa = gpa + 4.00
        count += 1
        
    elif grade >= 80:
        print("ok! that's a B!")
        b += 1
        gpa = gpa + 3.00
        count += 1
        
    elif grade >= 70:
        print("alright! that's a C!")
        c += 1
        gpa = gpa + 2.00
        count += 1
    
    elif grade >= 60:
        print("that's a D for dIsApPoInTiNg YoUr PaReNtS")
        d += 1
        gpa = gpa + 1.00
        count += 1
        
    elif grade <= 60 and grade > 0:
        print("FAILURE!")
        f += 1
        gpa = gpa + 0
        count += 1
        
    grade = float(input("What's another grade? "))
    
gpa = gpa/count

print("Ok! You have", a, "As!")
print("You also have", b, "Bs!")
print("You have", c, "Cs!")
print("Wow, you have", d, "Ds!")
print("You have", f, "Fs.")
print("Your GPA is: ", gpa)