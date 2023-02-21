- init:
    run: rm -f assignment
    blocker: true

- build:
    run: gcc -std=c99 -Wall -Werror assignment1.c -o assignment  # timeout: 1
    blocker: true

- case0_1900_1_1_1999:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1900 1 1"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "1999"
        - expect: "[ \r\n]*[A-z :=-]+[Mm]onday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*(14|15|13)[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0

- case0_invalid_11_31:
    run: ./assignment
    points: 2
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "2018 11 31"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                  # timeout: 1
        - expect: _EOF_                                # timeout: 1
    exit: 1

- case1_1868_11_13_2018:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1868 11 13"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "2018"
        - expect: "[ \r\n]*[A-z :=-]+[Ff]riday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*(20|21|22)[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0

- case1_1582_2_24_2018:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1582 2 24"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "2018"
        - expect: "[ \r\n]*[A-z :=-]+[Ww]ednesday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*(62|63|64)[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0

- case1_330_5_11_1453:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "330 5 11"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "1453"
        - expect: "[ \r\n]*[A-z :=-]+[Ss]unday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*(159|160|161)[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0

- case1_1444_11_10_1921:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1444 11 10"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "1921"
        - expect: "[ \r\n]*[A-z :=-]+[Ss]unday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*(67|68|69)[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0

- case1_722_1_2_1492:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "722 1 2"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "1492"
        - expect: "[ \r\n]*[A-z :=-]+[Mm]onday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*(110|111|112)[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0

- case2_invalid_2_30:
    run: ./assignment
    points: 2
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1495 2 30"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                  # timeout: 1
        - expect: _EOF_                                # timeout: 1
    exit: 1

- case2_invalid_4_31:
    run: ./assignment
    points: 2
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1713 4 31"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                  # timeout: 1
        - expect: _EOF_                                # timeout: 1
    exit: 1

- case2_invalid_6_31:
    run: ./assignment
    points: 2
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "546 6 31"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                  # timeout: 1
        - expect: _EOF_                                # timeout: 1
    exit: 1    
    
- case2_invalid_9_31:
    run: ./assignment
    points: 2
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1162 9 31"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                  # timeout: 1
        - expect: _EOF_                                # timeout: 1
    exit: 1

- case2_invalid_11_31:
    run: ./assignment
    points: 2
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1215 11 31"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                  # timeout: 1
        - expect: _EOF_                                # timeout: 1
    exit: 1    
    
- case2_invalid_negative_1:
    run: ./assignment
    points: 2
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1918 -3 31"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                  # timeout: 1
        - expect: _EOF_                                # timeout: 1
    exit: 1
    
- case2_invalid_negative_2:
    run: ./assignment
    points: 2
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1895 5 -11"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                  # timeout: 1
        - expect: _EOF_                                # timeout: 1
    exit: 1
    
- case2_invalid_negative_3:
    run: ./assignment
    points: 2
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "742 -3 -32"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                  # timeout: 1
        - expect: _EOF_                                # timeout: 1
    exit: 1    
    
- case2_invalid_other:
    run: ./assignment
    points: 2
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1770 15 42"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                  # timeout: 1
        - expect: _EOF_                                # timeout: 1
    exit: 1    

- case2_invalid_other2:
    run: ./assignment
    points: 2
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1756 7 0"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                  # timeout: 1
        - expect: _EOF_                                # timeout: 1
    exit: 1

- case3_0_1_1_2018:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "0 1 1"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "2018"
        - expect: "[ \r\n]*[A-z :=-]+[Ss]unday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*(292|293|294)[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0

- case3_1993_3_10_2018:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1993 3 10"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "2018"
        - expect: "[ \r\n]*[A-z :=-]+[Ww]ednesday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*(2|3|4)[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0

- case3_1993_3_10_2021:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1993 3 10"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "2021"
        - expect: "[ \r\n]*[A-z :=-]+[Ww]ednesday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*(3|4|5)[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0

- case3_1999_8_17_2070:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1999 8 17"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "2070"
        - expect: "[ \r\n]*[A-z :=-]+[Tt]uesday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*(9|10|11)[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0    
    
- case3_1546_7_4_5000:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1546 7 4"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "5000"
        - expect: "[ \r\n]*[A-z :=-]+[Tt]hursday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*(490|491|492)[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0    

- case3_1526_8_28_3000:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "1526 8 28"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "3000"
        - expect: "[ \r\n]*[A-z :=-]+[Ss]aturday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*206[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0
    
- case3_200_12_31_2000:
    run: ./assignment
    points: 6
    script:
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"  # timeout: 1
        - send: "200 12 31"
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*"                   # timeout: 1
        - send: "2000"
        - expect: "[ \r\n]*[A-z :=-]+[Ww]ednesday[. ]*[ \r\n]*"                 # timeout: 1
        - expect: "[ \r\n]*[A-z :=-]+[ \r\n]*255[ \r\n]*"  # timeout: 1
        - expect: _EOF_  # timeout: 1
    exit: 0
