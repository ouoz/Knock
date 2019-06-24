import MeCab
from collections import Counter
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

fname = 'neko.txt'
fname_parsed = 'neko.txt.mecab'


def parse_neko():
    with open(fname, encoding='utf-8_sig') as data_file, \
            open(fname_parsed, mode='w', encoding='utf-8_sig') as out_file:

        mecab = MeCab.Tagger()
        out_file.write(mecab.parse(data_file.read()))


def get_surfaces():
    with open(fname_parsed, encoding='utf-8_sig') as file_parsed:
        ret=[]
        for line in file_parsed:
            cols=line.split('\t')
            ret.append(cols[0])
    return ret

parse_neko()

surfaces=get_surfaces()
word_counter = Counter()
word_counter.update(surfaces)

list_word = word_counter.most_common()

counts = list(zip(*list_word))[1]

plt.hist(
    counts,
    bins=20,            
    range=(1, 20))      

plt.xlim(xmin=1, xmax=20)

plt.title("38. histogram")
plt.xlabel('count')
plt.ylabel('word')

plt.grid(axis='y')

plt.show()