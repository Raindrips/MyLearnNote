# lua调用sqlite

```lua
local sqlite=require('sqlite3')

local db=sqlite.open('a1.db');

db:exec[[
	insert into my_tb values(1,'name');
]];

```

## quick-cocos2d

