#include "Serializer.hpp"
#include "Data.hpp"

// Use serialize() on the address of the Data object and pass its return value to
// deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer.
int main()
{
    Data dataStruct = Data(10, 42.5, "just data");
    std::cout << "DataStruct address: " << &dataStruct << std::endl;
    std::cout << "Data in datastruct: "    << dataStruct.getInt()    << ", "
                                        << dataStruct.getFloat()  << ", "
                                        << dataStruct.getString() << std::endl;
    std::cout << std::endl;

    uintptr_t serializedObj = Serializer::serialize(&dataStruct);
    std::cout << "Serialized datastruct pointer value: " << serializedObj << std::endl;

    std::cout << std::endl;

    Data *deserializedPtr = Serializer::deserialize(serializedObj);
    std::cout << "DeserializedPtr address: " << deserializedPtr << std::endl;
    std::cout << "Data in serializedObj obtained from deserializedPtr: "    << deserializedPtr->getInt()    << ", "
                                                                            << deserializedPtr->getFloat()  << ", "
                                                                            << deserializedPtr->getString() << std::endl;
}