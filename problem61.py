# Author: Benjamin Barnett
# Date: 8/25/17
# https://projecteuler.net/problem=61

import pandas as pd
import numpy as np
import itertools as it
import sys

def triangle(n):
    return int(n*(n+1)/2)

def square(n):
    return int(n*n)

def pentagonal(n):
    return int(n*(3*n-1)/2)

def hexagonal(n):
    return int(n*(2*n-1))

def heptagonal(n):
    return int(n*(5*n-3)/2)

def octagonal(n):
    return int(n*(3*n-2))

figurates = [
    [], # Triangle
    [], # Square
    [], # Pentagonal
    [], # Hexagonal
    [], # Heptagonal
    [] # Octagonal
]

# Triangles
val = 0
i = 1
while val < 10000:
    if val >= 1000:
        figurates[0].append(val)
    val = triangle(i)
    i += 1

# Squares
val = 0
i = 1
while val < 10000:
    if val >= 1000:
        figurates[1].append(val)
    val = square(i)
    i += 1

# Pentagonals
val = 0
i = 1
while val < 10000:
    if val >= 1000:
        figurates[2].append(val)
    val = pentagonal(i)
    i += 1

# Hexagonals
val = 0
i = 1
while val < 10000:
    if val >= 1000:
        figurates[3].append(val)
    val = hexagonal(i)
    i += 1

# Heptagonals
val = 0
i = 1
while val < 10000:
    if val >= 1000:
        figurates[4].append(val)
    val = heptagonal(i)
    i += 1

# Octagonals
val = 0
i = 1
while val < 10000:
    if val >= 1000:
        figurates[5].append(val)
    val = octagonal(i)
    i += 1

# Create dataframe
shape_names = [
    "triangle",
    "square",
    "pentagonal",
    "hexagonal",
    "heptagonal",
    "octagonal"
]    
shapes = []
values = []

for idx,s in enumerate(figurates):
    values.extend(s)
    shapes.extend([shape_names[idx] for i in range(0,len(s))])

shape_dict = {
    "value" : values,
    "shape" : shapes
}

df = pd.DataFrame.from_dict(shape_dict)
df['beginning'] = df['value'].apply(lambda x : int(x / 100))
df['end'] = df['value'].apply(lambda x : int(int(x % 1000) % 100))

#Refine the dataframe
unique_endings = df['end'].unique()
df = df[(df['beginning'].isin(unique_endings))]

# All possible orders of shapes
shape_orders = list(it.permutations(shape_names,len(shape_names)))

total_sos = len(shape_orders)

# Find Solution
for idx,so in enumerate(shape_orders):
    print("Checking Shape Order: " + str(idx + 1) + "/" + str(total_sos) + "...")
    
    df1 = df[df["shape"] == so[0]]
    df2 = df[df["shape"] == so[1]]
    df3 = df[df["shape"] == so[2]]
    df4 = df[df["shape"] == so[3]]
    df5 = df[df["shape"] == so[4]]
    df6 = df[df["shape"] == so[5]]
    
    for r1 in df1.itertuples():
        df2_r = df2[df2["beginning"] == r1.end]
        for r2 in df2_r.itertuples():
            df3_r = df3[df3["beginning"] == r2.end]
            for r3 in df3_r.itertuples():
                df4_r = df4[df4["beginning"] == r3.end]
                for r4 in df4_r.itertuples():
                    df5_r = df5[df5["beginning"] == r4.end]
                    for r5 in df5_r.itertuples():
                        df6_r = df6[df6["beginning"] == r5.end]
                        for r6 in df6_r.itertuples():
                            if r6.end == r1.beginning:
                                # Print solution
                                solution = [
                                    r1.value,
                                    r2.value,
                                    r3.value,
                                    r4.value,
                                    r5.value,
                                    r6.value
                                ]
                                print("Solution Found!")
                                print(str(solution) + " = " + str(np.sum(solution)))
                                sys.exit(0)