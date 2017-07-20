#include <cstdio>
#include <cserialization.h>

int main()
{
    //Сделать класс из этих функций
    const std::string str = "one.bin";

    std::unique_ptr<CSerialization> ser = std::make_unique<CSerialization>();

    ser->serialization(str, "log", "passwd", "Ilyas", "Eredzh", true, "10.03.96"); //Регистрация
    ser->deserialization(str);
    ser->serialization(str, "log", "passwd"); //Вход
    ser->deserialization(str);
    ser->serialization(str, "124nfsdhk312415", "Ilyas", "Eredz", true, "10.03.96"); // Профиль
    ser->deserialization(str);
    ser->serialization(str, "", "Ilyas", "Eredz", true, "10.03.96"); // Сообщение
    ser->deserialization(str);

    return 0;
}



