#include "cserialization.h"

CSerialization::CSerialization()
{
    builder = std::make_unique<flatbuffers::FlatBufferBuilder>(1024);
}

CSerialization::~CSerialization()
{

}

bool CSerialization::serialization(const std::string &PASSED_FILE, std::string passed_name, int passed_id, int passed_key)
{
    //Создание и присваивание значений элементов структуры из schema_generated.h

    auto one_struct_name = builder->CreateString(passed_name);
    one_struct_id = passed_id;
    one_struct_key = passed_key;

    //Создание экземпляра структуры с использованием элементов

    auto one = CreateTestStruct(*builder,one_struct_name,one_struct_id, one_struct_key);

    //Завершение построения структуры
    builder->Finish(one);

    //Присваевание указателя билдера
    buffer = builder->GetBufferPointer();

    //Размер билдера
    size_of_builder = builder->GetSize();

    //Открываем файл в режиме запись
    file = fopen(PASSED_FILE.c_str(), "wb");

    fseek(file,0L,SEEK_END);
    fwrite(buffer, sizeof(char), size_of_builder , file);
    fclose(file);

    return false;
}

void CSerialization::deserialization(const std::string &PASSED_FILE)
{
    // Открываем файл в режиме чтения
    file = fopen(PASSED_FILE.c_str(), "rb");
    fseek(file,0L,SEEK_END);
    length = ftell(file);
    fseek(file,0L,SEEK_SET);
    data =std::make_unique<char>(length);
    fread(&data,sizeof(char), length, file);
    fclose(file);

    //Десериализация файла
    auto take = GetTestStruct(&data);

    //Вывод значений в консоль(можно использовать только printf())
    conteier.push_back(take->name.c_str());
    conteier.push_back(take->id());
    conteier.push_back(take->key());
    for(int i =0; i < conteier.size(); i++)
    {
        std::cout << conteier[i] << std::endl;
    }
}
