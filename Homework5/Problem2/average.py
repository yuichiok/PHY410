import sys

file_name = sys.argv[1]

with open(file_name) as f:
    for l in f.readlines():
        print l.strip().split(",")
        break
        f.close()