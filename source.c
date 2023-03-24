#include "monty.h"
stack = []

def push(line):
    try:
        value = int(line.split()[1])
        stack.append(value)
    except (IndexError, ValueError):
        print(f"L{line_number}: usage: push integer")
        exit(1)

def pall():
    for value in reversed(stack):
        print(value)
