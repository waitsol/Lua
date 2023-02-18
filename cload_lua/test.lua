local function test_load()
	print "test_load"
	return 1
end
local function test_print()
	print "test_print"
	return "test_print"
end
local test_table={"aa","bb"}
--能加载到 
function Zlk_print(val)
	print("Zlk_print ",val)
	return "Zlk_print"
end
function Zlk_print_G(val)
	print("Zlk_print_G ", _G[val])
	
end
local Zlk_table = {one= "aa", two="bb" }
--lua_getglobal这样才能加载到
_G["g_zlk_table"] = Zlk_table
_G["test_table"] = test_table
a = test_load()
b = test_print()
return test_table
