# `rfl::Bytestring` 

`rfl::Bytestring` is a simple alias:

```cpp
namespace rfl {

using Bytestring = std::vector<std::byte>;

}
```

Bytestrings are supported by binary formats such as BSON, CBOR, flexbuffers and msgpack. 
Textual formats do not support them.
