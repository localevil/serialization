#include "Сгенерированные схемы/Error_generated.h"
#include "Сгенерированные схемы/Profile_generated.h"
#include "Сгенерированные схемы/Registration_generated.h"
#include "Сгенерированные схемы/SignIn_generated.h"
#include "Сгенерированные схемы/Message_generated.h"
#include <iostream>
#include <variant>

#ifndef CSERIALIZATION_H
#define CSERIALIZATION_H

using namespace Schema;

enum class Type{
    REGISTRATION = 0,
    SIGNIN,
    PROFILE,
    MESSAGE,
    ERROR
};

class CSerialization
{
public:
    CSerialization();
    ~CSerialization();
    bool serialization(const std::string &passedFile, const std::vector<std::variant<std::string, unsigned long, bool,
                       int>> &passedVariant, Type typeOfSchema);
    void deserialization(const std::string &passed_file);

private:
    std::unique_ptr<flatbuffers::FlatBufferBuilder> builder;
    void save_to_file(const std::string &passed_file);
};

#endif // CSERIALIZATION_H
