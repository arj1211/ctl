input  :  [1,2,3,4,5,6,7,8,9,10]
map    :  { x : (x * 2 + 1) / (x - 1) }
filter :  { x : x % 2 == 0 }
filter :  { x : x > 3 }
expand :  { [ x, x * x, (x * 2 + 1) ] | x }
map    :  { x : x - 5 }
filter :  { x : x >= 0 }
expand :  { [ x / 2, x / 3 ] | x }
output :