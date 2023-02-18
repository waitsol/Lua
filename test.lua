me = { "c" }
t = { me, me }

print(rawlen(t))
t[1] = t[2]
print(rawlen(t))
