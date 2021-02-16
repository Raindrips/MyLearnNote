# json



## MsgPack



### 示例

```cpp
MsgPack::Serializer serializer(socket);  
std::vector<std::unique_ptr<MsgPack::Element>> arrayWithoutElements, arrayWith3Elements;
arrayWith3Elements.push_back(MsgPack::Factory(true));
arrayWith3Elements.push_back(MsgPack__Factory(Array(std::move(arrayWithoutElements))));
arrayWith3Elements.push_back(MsgPack::Factory("Hello World!"));  
serializer << MsgPack__Factory(Array(std::move(arrayWith3Elements)));

MsgPack::Deserializer deserializer(socket);  
deserializer.deserialize([](std::unique_ptr<MsgPack::Element> parsed) {
    std::cout << "Parsed: " << *parsed << "\n";
    return false;
}, true);
```

