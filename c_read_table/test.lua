local tb={aaaaaaa="aaaaaaaaaaa",k1="kv1",k2="kv2",ktb={childtb="ctb",ctb2="ctb2",ctb3={ctb33="xxxxxxxxxx"}}}

function ff(a)
	tb[1] = a
	print("ff "..a)
	return tb
end
function Run(a)
	return a*10
end
function Pc(a)
	print("type a = ",type(a))
	print(a)
end
setmetatable(tb,{__index={ff=ff}})
ff(...)
return tb
--zy(...)
--return tb
