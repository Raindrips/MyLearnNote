# 正则表达式

```python
## 导入包
import re;

## match 表达式  string 字符
m=re.search(match,string);
```

示例

```python
##
m=re.search("a1","abc")

try:
  print(m.string)
  print(m.group(0))
except AttributeError:
  pass

```



