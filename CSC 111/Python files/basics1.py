while True:
    sam = int(input("Enter lower value: "))
    sally = int(input("Enter higher value: "))
    
    if (sally>sam):
        print("Sam and Sally are OK")
        break
    else:
        print("Sam is not less than sally")

#if ((sally%sam)==0)[the 1st other way to skin the cat]
        
if (not(sally % sam)):    #the percent sign is a mod function that checks the remainder of sally divided by sam
    print ("Sally is a multiple of Sam")#you could swap this with ("Sally is not a multiple of Sam")and un-not it to get the third way to skin the cat
else:
    print ("Sally is not a multiple of Sam")
    
print ("All Done!")#"there's multiple ways to skin this cat." - Dr. Wheat, 10/28/2022, before saying "my youngest is 38... no wait she's 34, I
#made her too old" (his daughter shaved her shetland sheepdog because she thought it was hot so he shaved the cat)