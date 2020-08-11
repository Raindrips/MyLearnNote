# lua串行化



```lua
-- 
function Serialize(obj)
    if type(o) == "number" then
        io.write(obj);
    elseif type(o) == "string" then
        io.write("[[",obj,"]]");  
    else
		--其他情况
    end 
end
```



