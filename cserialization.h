#include <schema_generated.h>
#include <iostream>
#include <variant>

#ifndef CSERIALIZATION_H
#define CSERIALIZATION_H

using namespace TestSchema;

class CSerialization
{
public:
    CSerialization();
    ~CSerialization();
    bool serialization(const std::string_view passed_file,const std::string_view passed_name,const int &passed_id,const int &passed_key);
    static std::vector<std::variant<std::string, int>> deserialization(const std::string_view passed_file);
};

#endif // CSERIALIZATION_H
