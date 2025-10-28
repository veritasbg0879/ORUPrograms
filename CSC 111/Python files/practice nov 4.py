age = 12
if age < 4:
    price = 0

elif age < 18: #elif not andif elif only executes one line of code
    price = 25 #as opposed to multiple. its categorization
    
elif age < 65:
    price = 40

elif age >= 65:
    price = 20
    
print("your admission cost is $", price)