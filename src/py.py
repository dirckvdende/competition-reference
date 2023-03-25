import io, os
# Fast input
inp = io.BytesIO(os.read(0, os.fstat(0).st_size)) \
.readline
s = inp().decode()
# Fast output
sys.stdout.write(s)
# Normal input and output
input(), print()

# Sort a list, with key returning a number
list.sort(reverse, key)
# Unordered set and map
set([a, b, c]), {"a": 5, "g": 34}
set.add(), set.remove()
lambda a : a + 10
# Floor division
a = b // c
# Parallel assignment (example: swap)
a, b = b, a