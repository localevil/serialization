#include "cserialization.h"

CSerialization::CSerialization()
{

}

CSerialization::~CSerialization()
{

}

bool CSerialization::serialization(const std::string_view passed_file,const std::string_view passed_name,
                                    const int &passed_id, const int &passed_key)
{

    std::unique_ptr<flatbuffers::FlatBufferBuilder> builder = std::make_unique<flatbuffers::FlatBufferBuilder>(1024);

    //Создание и присваивание значений элементов структуры из schema_generated.h

    auto one_struct_name = builder->CreateString(std::string(passed_name).c_str());
    int one_struct_id = passed_id;
    int one_struct_key = passed_key;

    //Создание экземпляра структуры с использованием элементов

    auto one = CreateTestStruct(*builder,one_struct_name,one_struct_id, one_struct_key);

    //Завершение построения структуры
    builder->Finish(one);

    //Присваевание указателя билдера
    uint8_t *buffer = builder->GetBufferPointer();

    if(!buffer)
    {
        return false;
    }

    //Размер билдера
    size_t size_of_builder = builder->GetSize();

    //Открываем файл в режиме запись
    FILE *file = fopen(std::string(passed_file).c_str(), "wb");

    fseek(file,0L,SEEK_END);
    fwrite(buffer, sizeof(char), size_of_builder , file);
    fclose(file);

    return true;
}

std::vector<std::variant<std::string, int>> CSerialization::deserialization(const std::string_view passed_file)
{
    std::vector<std::variant<std::string, int>> conteier;
    // Открываем файл в режиме чтения
    FILE* file_in = fopen(std::string(passed_file).c_str(), "rb");
    fseek(file_in, 0L, SEEK_END);
    size_t length = size_t(ftell(file_in));
    fseek(file_in, 0L, SEEK_SET);
     std::unique_ptr<char[]> data = std::make_unique<char[]>(length);
    fread(data.get(), sizeof(char), length, file_in);
    fclose(file_in);

    //Десериализация файла
    auto take = GetTestStruct(data.get());

    conteier.push_back(take->name()->str());
    conteier.push_back(take->id());
    conteier.push_back(take->key());
    for(auto &value : conteier)
    {
        if(std::get_if<std::string>(&value))
            std::cout << std::get<std::string>(value) << std::endl;
        else if(std::get_if<int>(&value))
            std::cout << std::get<int>(value) << std::endl;
    }

//    for(auto &value : conteier)
//    {
//        if(value.type() == typeid(std::string))
//            std::cout << static_cast<std::string>(std::any_cast<std::string>(value)) << std::endl;
//        else if(value.type() == typeid(int))
//            std::cout << static_cast<int>(std::any_cast<int>(value)) << std::endl;
//    }

    return conteier;
}
