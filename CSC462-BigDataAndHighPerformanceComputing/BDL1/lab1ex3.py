from mrjob.job import MRJob
from mrjob.step import MRStep

class MRmyjob(MRJob):
    def mapper1(self, _, line):
        text = line.split() #read in the line split by words
        phrase = text[0] + " " + text[1] #get two words in there
        year = text[2]
        value = int(text[3])
        books = int(text[5])
        yield((phrase, year), value, books)

    def reducer1(self, phrase_year, value, books):
        yield((phrase_year, sum(value), sum(books)))
        #Output: (((hello, 2005), [val], [books])

    def reducer2(self, phrase_year, value, books):

        # waiting on output. this code is tentative. 
        yield(phrase_year, value / books)

    def steps(self):
        return [MRStep(mapper=self.mapper1, reducer=self.reducer1),
                  MRStep(reducer=self.reducer2)]

if __name__ == '__main__':
    MRmyjob.run()
