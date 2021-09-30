# Expansion Project
# Powerd By Python
# Developed By rhseung

import time

print("\n===== Expansion Calculator =====\n")

formula = input("input formula: ")
formula = formula.replace('^','*')
# print(eval(formula))

cpy = ''
for i in range(0, len(formula), 1):
    if formula[i] == '*':
        for j in range(0, i, 1):
            cpy.append(formula[j])

print(cpy)