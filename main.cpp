#include <cstdio>
#include <cserialization.h>

int main()
{
    //Сделать класс из этих функций
    const std::string str = "one.bin";

    std::unique_ptr<CSerialization> ser = std::make_unique<CSerialization>();

    ser->serialization(str, "First", 255, 15);
    ser->deserialization(str);

    return 0;
}



