#include <schema_generated.h>
#include <iostream>

#ifndef CSERIALIZATION_H
#define CSERIALIZATION_H

using namespace TestSchema;

class CSerialization
{
public:
    CSerialization();
    ~CSerialization();
    bool serialization(const std::string &PASSED_FILE, std::string passed_name, int passed_id, int passed_key);
    void deserialization(const std::string &PASSED_FILE);


private:
    int size_of_builder;
    int one_struct_id;
    int one_struct_key;
    int length;
    FILE* file;
    uint8_t *buffer;
    std::unique_ptr<char> data;
    std::vector<std::variant<std::string, int>> conteier;
    std::unique_ptr<flatbuffers::FlatBufferBuilder> builder;
};

#endif // CSERIALIZATION_H
