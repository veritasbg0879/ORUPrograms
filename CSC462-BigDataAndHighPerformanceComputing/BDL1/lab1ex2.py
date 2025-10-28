from mrjob.job import MRJob
from mrjob.step import MRStep

class MRmyjob(MRJob):
    def mapper1(self, _, line):
        text = line.split()
        phrase = text[0] + " " + text[1]
        year = int(text[2])
        value = int(text[3])
        # EX: ((2005, hello), 1)
        yield((year, phrase), value)

    def reducer1(self, year_phrase, value):
        # Input: ((2005, hello), 1 1 1 1 1 1) 
        yield(year_phrase, sum(value))
        # Output: ((2005, hello), 6)
    
    def mapper2(self, year_phrase, value):
        year, phrase = year_phrase

        # The issue lies here: some error about "TypeError: cannot unpack non-iterable int object"
        #took a break to move on to exercise 3. 

        # the issue i face is that i struggle to find the max of something relative to the year
        # trying to move things around gives me a typeerror, which it shouldnt??
        yield((value, year), phrase)

    def reducer2(self, list_years, _):
        yield(max(list_years))

    #Desired output: (year, word, count)
    #Intermediate output: (year, (count, word))
    # find max bigram value for each year ...

    # mappers make or rearrange tuple pairs. 
    # reducers combine tuple pairs.

    def steps(self):
        return [MRStep(mapper=self.mapper1, reducer=self.reducer1), 
                MRStep(mapper=self.mapper2), MRStep(reducer=self.reducer2)] #, MRStep(mapper=self.mapper2, reducer=self.reducer2)


if __name__ == '__main__':
    MRmyjob.run()
