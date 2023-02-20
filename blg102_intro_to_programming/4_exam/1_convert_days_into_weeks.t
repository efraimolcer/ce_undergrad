- init:
    run: rm -f question1
    blocker: true

- build:
    run: gcc -std=c99 -Wall -Werror question1.c -o question1  # timeout: 2
    blocker: true

- case_18:
    run: ./question1
    points: 1
    script:
        - expect: "Enter the number of days: "  # timeout: 2
        - send: "18"
        - expect: "18 days are 2 weeks, 4 days.\r\n" # timeout: 2
        - expect: _EOF_  # timeout: 2
    exit: 0

- case_35:
    run: ./question1
    points: 1
    script:
        - expect: "Enter the number of days: "  # timeout: 2
        - send: "35"
        - expect: "35 days are 5 weeks, 0 days.\r\n" # timeout: 2
        - expect: _EOF_  # timeout: 2
    exit: 0

- case_0:
    run: ./question1
    points: 1
    script:
        - expect: "Enter the number of days: "  # timeout: 2
        - send: "0"
        - expect: "0 days are 0 weeks, 0 days.\r\n" # timeout: 2
        - expect: _EOF_  # timeout: 2
    exit: 0

- case_9999:
    run: ./question1
    points: 1
    script:
        - expect: "Enter the number of days: "  # timeout: 2
        - send: "9999"
        - expect: "9999 days are 1428 weeks, 3 days.\r\n" # timeout: 2
        - expect: _EOF_  # timeout: 2
    exit: 0