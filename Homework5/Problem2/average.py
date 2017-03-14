import sys

file_name = sys.argv[1]

def main(name):
    
    record = open(name)
    sum = 0.0
    n = 0

    for line in record:
        print line
        n += 1
        l = line.split(',')
        score = float(l[2])
        sum += score
    
    return sum / n

print("average = " + str(main(file_name)))