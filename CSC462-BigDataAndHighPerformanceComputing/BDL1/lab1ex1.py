from mrjob.job import MRJob
from mrjob.step import MRStep

class MRmyjob(MRJob):
    def mapper1(self, _, line):
        text = line.split()
        phrase = text[0] + " " + text[1]
        value = int(text[4])  
        yield(phrase, value)

    def reducer1(self, key, list_of_values):
        yield(None, (sum(list_of_values),key))

    def reducer2(self, _, list_of_values):
        yield(max(list_of_values))

    def steps(self):
        return [MRStep(mapper=self.mapper1, reducer=self.reducer1),
                  MRStep(reducer=self.reducer2)]

if __name__ == '__main__':
    MRmyjob.run()
