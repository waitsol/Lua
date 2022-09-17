studentB=Student:new() --实例化Student全局对象
 
function Run()
	studentB:Run();
end
 
function Run2(a)
	studentB:Run2(a);
end
  
Run()
 
Run2(10)