open ch 10 alice.py

filename = 'alice.txt'

try:
    with open(filename, encodings='utf-8') as f:
        contents = f.read()
except FileNotFoundError: #if the try failed, check for this exception. if this exception is why it failed, do the thingy after the except.
    print(f"sorry, the file {filename} does not exist.")
else:
    #Count the approximate number of words in the file.
    words = contents.split()
    num_words = len(words)
    print(f"The {filename] has about {num_words} words.")