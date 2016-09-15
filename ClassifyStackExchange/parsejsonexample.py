import json
import itertools
from pprint import pprint

with open('training.json') as f:
    data = []
    # skip first line (ignore integer number at start of file)
    f.readline()

    for line in f:
        data.append(json.loads(line))

    print(data[0]['topic'])