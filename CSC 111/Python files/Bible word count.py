from array import array

moveForward = False
while not moveForward:
    
    fname = input("which file do you want me to read?")
    #fname = "BibleNIV.txt"
    try:
        with open(fname, "r") as f:
            contents = f.read()
        moveForward = True
    except FileNotFoundError:
        print(f"Sorry, that file does not exist.")
        
cCount = len(contents)
print("there are %d characters in the file" % cCount)

print()

a_count = 0
wormsss bob morris jr