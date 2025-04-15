# start with a decently large vector
input: [1,2,3,4,5,6,7,8,9,10]

# map each x through a non-trivial arithmetic expression
map:    { x : (x * 2 + 1) / (x - 1) }

# filter to even results greater than 3
filter: { x : x % 2 == 0 }
filter: { x : x > 3 }

# expand each x into three values: itself, its square, and its double-plus-one
expand: { [ x, x * x, (x * 2 + 1) ] | x }

# shift the entire sequence down by 5
map:    { x : x - 5 }

# drop negatives
filter: { x : x >= 0 }

# final expand into halves and thirds
expand: { [ x / 2, x / 3 ] | x }

# emit the result
output:
