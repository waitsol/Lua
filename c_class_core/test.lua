require "testlib"
co = require "class.core"
a = co.create_inter(3)
b = co.create_inter(4)
c = co.create_inter(4)
print(a:equal(b))
print(c:equal(b))
