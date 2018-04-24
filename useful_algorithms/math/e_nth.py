"""Finds e to the nth digit of precision."""

import decimal
import itertools
from functools import reduce


def factorial(value):
    """Calculates Factorial."""

    if not value:
        return 1

    return reduce(lambda x, y: x * y, range(1, value + 1))


def e_series(value):
    """Calculates e using Newton's series expansion.

    value -- number of correct digits to be calculated.
    """

    precision = decimal.Decimal(10 ** (-value - 2))
    e_value = decimal.Decimal(0)

    for i in itertools.count():
        calculation = decimal.Decimal(1 / factorial(i))
        e_value += calculation
        if calculation < precision:
            break

    return e_value


def main():
    """
        Interacts with the user and calls e_series.
    """

    print("Calculate e to the nth digit of precision.")
    nth_digit = input("Type n: ")

    try:
        nth_digit = int(nth_digit)
    except TypeError:
        print(f"{nth_digit} is not a number, exiting...")
        return

    if not nth_digit or nth_digit < 0:
        return

    decimal.getcontext().prec = nth_digit + 2
    e_value = e_series(nth_digit)

    print(f"e is {e_value:.{nth_digit+1}}")


if __name__ == '__main__':
    main()
