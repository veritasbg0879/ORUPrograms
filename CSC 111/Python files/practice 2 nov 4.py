available_toppings = ['mushrooms', 'olives','pineapple']

requested_toppings = ['pineapple','fire','cheese']

for requested_topping in available_toppings:
    if requested_topping in available_toppings:
        print(f"adding {requested_topping}.")
    else:
        print(f"sorry, we don't have {requested_topping}.")
              
print("\n we finished your pizza!")