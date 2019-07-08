import MeCab
fname = 'neko.txt'
fname_parsed = 'neko.txt.mecab'

def parse_neko():
    with open(fname, encoding="utf-8_sig") as data_file:
        with open(fname_parsed, mode='w', encoding="utf-8_sig") as out_file:
            mecab = MeCab.Tagger()
            out_file.write(mecab.parse(data_file.read()))

def make_map():
    ret=[]
    with open(fname_parsed, encoding="utf-8_sig") as file_parsed:
        for line in file_parsed:

            cols = line.split('\t')
            if(len(cols) < 2):
                return ret
            morpheme_cols = cols[1].split(',')

            morpheme = {
                'surface': cols[0],
                'base': morpheme_cols[6],
                'pos': morpheme_cols[0],
                'pos1': morpheme_cols[1]
            }
            ret.append(morpheme)

parse_neko()
parsed_map=make_map()
AofB_list=[]

for i in range(1, len(parsed_map)-1):
    if parsed_map[i]['surface']=='の' and parsed_map[i]['pos']=="助詞":
        if parsed_map[i-1]['pos']=="名詞" and parsed_map[i+1]['pos']=="名詞":
          AofB_list.append(parsed_map[i-1]['surface']
          +parsed_map[i]['surface']
          +parsed_map[i+1]['surface'])

fname_out="AofB.txt"
with open(fname_out, 'w', encoding='utf-8_sig') as output:
    for elem in AofB_list:
        output.write(elem+'\n')
        print(elem)

