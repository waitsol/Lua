local tb = { aaaaaaa = "aaaaaaaaaaa", k1 = "kv1", k2 = "kv2", ktb = { childtb = "ctb", ctb2 = "ctb2",
	ctb3 = { ctb33 = "xxxxxxxxxx" } } }

-- 这里是闭包测试
function Run(a)
	print("argv = ", a)
end

Run(...)
