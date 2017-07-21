#include <cstdio>
#include <cserialization.h>

int main()
{
    //Сделать класс из этих функций
    const std::string str = "one.bin";

    std::unique_ptr<CSerialization> ser = std::make_unique<CSerialization>();

    std::vector<std::variant<std::string, unsigned long, bool, int>> testVector;
    testVector.push_back(0);
    testVector.push_back("root");
    testVector.push_back("passwd");
    testVector.push_back("Ilyas");
    testVector.push_back("Eredz");
    testVector.push_back(bool(true));
    testVector.push_back("10.03.96");

    ser->serialization(str, testVector, Type::REGISTRATION);
    ser->deserialization(str);
    ser->deserialization("two.bin"); //Проверка файла

    return 0;
}



