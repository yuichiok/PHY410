from Point import Point


def main() :
    p1 = Point(0.,1.)
    p2 = Point(2.,3.)

    p3 = p1 + p2
    p4 = p1 - p2

    print p1
    print p2
    print p3
    print p4


    line = '23.,45.'
    p4 = Point()
    p4.input(line)

    print p4




if __name__ == "__main__" :
    main()
