"""Finds pi to the nth digit of precision."""

import decimal
from functools import reduce
from math import sqrt


def factorial(value):
    """Calculates Factorial."""

    if not value:
        return 1

    return reduce(lambda x, y: x * y, range(1, value + 1))


def chudnovsky(precision):
    """Calculates pi using chudnovsky formula.

    precision -- number of correct digits to be calculated.
    """

    limit = precision // 14
    summation = decimal.Decimal()

    for i in range(limit + 1):

        first = factorial(i * 6) * (545140134 * i + 13591409)
        second = factorial(i * 3) * (factorial(i)**3) * ((-262537412640768000) ** i)

        summation += decimal.Decimal(first) / decimal.Decimal(second)

    pi_value = decimal.Decimal(426880 * sqrt(10005)) / summation

    return pi_value


def main():
    """
        Interacts with the user and calls pi_series.
    """

    print("Calculate pi to the nth digit of precision.")
    nth_digit = input("Type n: ")

    try:
        nth_digit = int(nth_digit)
    except TypeError:
        print(f"{nth_digit} is not a number, exiting...")
        return

    if not nth_digit or nth_digit < 0:
        return

    decimal.getcontext().prec = nth_digit + 1
    pi_value = chudnovsky(nth_digit)

    print(f"Pi is {pi_value}")


if __name__ == '__main__':
    main()
