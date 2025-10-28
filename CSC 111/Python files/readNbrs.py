fname = input("which file do you want me to read? ") #prompts person running file

f=open(fname, "r") #open whatever file you type in and include the .docx or .png or whatever. "r" is open for reading. open is the handle on the coffee
n = 0 #mug. how many things have we read in? 
sum = 0 #whats the sum of the files we have read in?
for lineTxt in f:
    print("Got this line: ", end='') #print the string text and then print whatever end='' is
    print(lineTxt, end='') #print on the same line each time? print the ASCII version
    
    sum+= int(lineTxt) #add any numbers found in the line
    n = n+1
    
print("the sum of the ", n, " numbers was ", sum)

#THE LINE KEEPS GOING BECAUSE 10 IN HEX IS A LINE FEED/CARRIAGE RETURN SO BECAUSE OF THE NUMBERS THERES A HIDDEN NEW LINE FUNCTION