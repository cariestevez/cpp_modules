#include "Serializer.hpp"
#include "Data.hpp"

// Use serialize() on the address of the Data object and pass its return value to
// deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer.
int main()
{
    Data dataStruct = Data(10, 42.5, "just data");
    std::cout << "dataStruct value: " << &dataStruct << std::endl;

    uintptr_t serializedObj = Serializer::serialize(&dataStruct);
    std::cout << "serializedObj value: " << serializedObj << std::endl;

    Data *deserializedPtr = Serializer::deserialize(serializedObj);
    std::cout << "deserializedPtr value: " << deserializedPtr << std::endl;
}