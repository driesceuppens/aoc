from numpy import fromfile

file_inputs = fromfile("input/day1.txt", dtype=int, sep="\n")

sol = map(
    lambda a: a[1] < file_inputs[a[0] + 3] if a[0] < len(file_inputs) - 3 else False,
    enumerate(file_inputs),
)
print(sum(sol))
