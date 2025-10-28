list1 = []
list2 = []

with open ('file1.txt','r') as fileOne:
    for line in fileOne:
        list1.append(int(line))
        
        
with open ('file2.txt','r') as fileTwo:
    for line in fileTwo:
        list2.append(int(line))
        
    
j = 0
for i in range(0,7):
    a = list1[i]
    b = list2[i]
    
    x = list1[i] + list2[i]
    y = list1[i] * list2[i]
    z = list1[i]**list2[i]
    
    print("The sum of ", a," and ", b, " is ", x)
    print("The product of ", a," and ", b, " is ", y)
    print("The power of ",a," and ",b, " is ", z)
    j = j + x
    l = i*2
    
print (j, "\n")
avgX = j/(l)
print (avgX)