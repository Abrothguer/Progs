""" Fibonacci sequence with big numbers """

FIB_LIST = [0, 1]


def big_fibonacci(nth):
    """ Calculates the nth fibonacci number"""

    try:
        return FIB_LIST[nth]
    except IndexError:
        pass

    for i in range(len(FIB_LIST), nth + 1):
        FIB_LIST.append(FIB_LIST[i - 1] + FIB_LIST[i - 2])

    return FIB_LIST[nth]


def main():
    """ Main function """

    nth = input("Calculate the nth fibonacci number. Type n: ")

    if not nth.isdigit():
        return

    nth = int(nth)
    if not nth or nth < 0:
        return

    fib_nth = big_fibonacci(nth)
    print(f"The {nth} fibonacci number is {fib_nth}")


if __name__ == "__main__":
    main()
