#include <iostream>
#include <cstdio>
#include <cserialization.h>

using std::string;

int main()
{
    //Сделать класс из этих функций
    string str = "one.bin";

    CSerialization *ser = new  CSerialization();

    ser->serialization(str, "First", 255, 15);
    ser->deserialization(str);

    delete(ser);

    return 0;
}



