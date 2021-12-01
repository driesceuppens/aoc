from numpy import fromfile

file_inputs = fromfile("input/day1.txt", dtype=int, sep="\n")

# first part
sol1 = sum(
    map(
        lambda a: a[1] < file_inputs[a[0] - 1] if a[0] != 0 else False,
        enumerate(file_inputs),
    )
)

# second part
sol2 = sum(
    map(
        lambda a: a[1] < file_inputs[a[0] + 3]
        if a[0] < len(file_inputs) - 3
        else False,
        enumerate(file_inputs),
    )
)
print(sol1, sol2)
