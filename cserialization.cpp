#include "cserialization.h"

CSerialization::CSerialization()
{
    builder = std::make_unique<flatbuffers::FlatBufferBuilder>(1024);
}

CSerialization::~CSerialization()
{

}

enum type{
    strcISTRATION = 0,
    SINGIN,
    PROFILE,
    MESSAGE,
    ERROR
};

bool CSerialization::serialization(const std::string &passed_file, std::string passed_login, std::string passed_password,
                                   std::string passed_name, std::string passed_surname, bool passed_sex,
                                   std::string passed_data_of_birth) //Регистрация
{
    //Создание и присваивание значений элементов структуры из schema_generated.h

    auto struct_login = builder->CreateString(passed_login);
    auto struct_password = builder->CreateString(passed_password);
    auto struct_name = builder->CreateString(passed_name);
    auto struct_surname = builder->CreateString(passed_surname);
    bool struct_sex = passed_sex;
    auto struct_data_of_birth = builder->CreateString(passed_data_of_birth);

    //Создание экземпляра структуры с использованием элементов
    auto strc = CreateRegistration(*builder, 0, struct_login, struct_password, struct_name, struct_surname,
                                   struct_sex, struct_data_of_birth);

    //Завершение построения структуры
    builder->Finish(strc);

    save_to_file(passed_file);

    return true;
}
bool CSerialization::serialization(const std::string &passed_file, const std::string &passed_login, const std::string &passed_password) // Вход
{
    auto struct_login = builder->CreateString(passed_login);
    auto struct_password = builder->CreateString(passed_password);

    //Создание экземпляра структуры с использованием элементов
    auto strc = CreateSignIn(*builder, 1, struct_login, struct_password);

    //Завершение построения структуры
    builder->Finish(strc);

    save_to_file(passed_file);

    return true;
}

bool CSerialization::serialization(const std::string &passed_file, const std::string &passed_key, const std::string &passed_name,
                                  const std::string &passed_surname, const bool &passed_sex, const std::string &passed_data_of_birth) // Профиль
{
    auto struct_key = builder->CreateString(passed_key);
    auto struct_name = builder->CreateString(passed_name);
    auto struct_surname = builder->CreateString(passed_surname);
    bool struct_sex = passed_sex;
    auto struct_data_of_birth = builder->CreateString(passed_data_of_birth);

    //Создание экземпляра структуры с использованием элементов
    auto strc = CreateProfile(*builder, 2, struct_key, struct_name, struct_surname, struct_sex, struct_data_of_birth);

    //Завершение построения структуры
    builder->Finish(strc);

    save_to_file(passed_file);
    return true;
}

bool CSerialization::serialization(const std::string &passed_file, const std::string &passed_key, const unsigned long &passed_user_addressee_id,
                                   const unsigned long &passed_user_sender_id, const std::string &passed_message,
                                   const std::string &passed_data_time) // Сообщение
{
    auto struct_key = builder->CreateString(passed_key);
    unsigned long struct_user_addressee_id = passed_user_addressee_id;
    unsigned long struct_user_sender_id = passed_user_sender_id;
    auto struct_message = builder->CreateString(passed_message);
    auto struct_data_time = builder->CreateString(passed_data_time);

    //Создание экземпляра структуры с использованием элементов
    auto strc = CreateMessage(*builder, 3, struct_key, struct_user_addressee_id, struct_user_sender_id, struct_message, struct_data_time);

    //Завершение построения структуры
    builder->Finish(strc);

    save_to_file(passed_file);

    return true;
}


bool CSerialization::serialization(const std::string &passed_file, const std::string &passed_key, const int16_t &passed_code, const std::string &passed_discriprion) // Ошибка
{
    auto struct_key = builder->CreateString(passed_key);
    int16_t struct_code = passed_code;
    auto struct_discriprion = builder->CreateString(passed_discriprion);

    //Создание экземпляра структуры с использованием элементов
    auto strc = CreateError(*builder, 4, struct_key, struct_code, struct_discriprion);

    //Завершение построения структуры
    builder->Finish(strc);

    save_to_file(passed_file);

    return true;
}

void CSerialization::save_to_file(const std::string &passed_file)
{
    //Присваевание указателя билдера
    uint8_t *buffer = builder->GetBufferPointer();

    //Размер билдера
    size_t size_of_builder = builder->GetSize();

    //Запись
    FILE *file = fopen(passed_file.c_str(), "wb");
    fseek(file,0L,SEEK_END);
    fwrite(buffer, sizeof(char), size_of_builder , file);
    fclose(file);
}

void CSerialization::deserialization(const std::string &passed_file)
{
    std::cout << "-------------------------" <<  std::endl;
    // Открываем файл в режиме чтения
    FILE *file = fopen(passed_file.c_str(), "rb");

    if(file == nullptr) //Проверка файл
    {
        std::cout << "File error: " << passed_file << std::endl;
        return ;
    }

    fseek(file,0L,SEEK_END);
    size_t length = ftell(file);
    fseek(file,0L,SEEK_SET);
    std::unique_ptr<char[]> data = std::make_unique<char[]>(length);
    fread(data.get(),sizeof(char), length, file);
    fclose(file);

    auto for_type = GetSignIn(data.get());
    //Вывод значений в консоль(можно использовать только printf())
    /*conteier.push_back(take->name.c_str());
    conteier.push_back(take->id());
    conteier.push_back(take->key());
    for(int i =0; i < conteier.size(); i++)
    {
        std::cout << conteier[i] << std::endl;
    }*/
//    switch (for_type->type())
//    {
//    case 0:
//        //Десериализация файла
//        auto take = GetRegistration(data.get());
//        printf("%s\n", take->login()->c_str());
//        printf("%s\n", take->password()->c_str());
//        printf("%s\n", take->name()->c_str());
//        printf("%s\n", take->surname()->c_str());
//        printf("%s\n", take->sex() ? "true" : "false");
//        printf("%s\n", take->date_of_birth()->c_str());
//        break;
//    case 1:
//        //Десериализация файла
//        auto take = GetSignIn(data.get());
//        printf("%s\n", take->login()->c_str());
//        printf("%s\n", take->password()->c_str());
//        break;
//    case 2:
//        //Десериализация файла
//        //auto take = GetProfile(data.get());
//        printf("%s\n", take->key()->c_str());
//        printf("%s\n", take->name()->c_str());
//        printf("%s\n", take->surname()->c_str());
//        printf("%s\n", take->sex() ? "true" : "false");
//        printf("%s\n", take->date_of_birth()->c_str());
//        break;
//    case 3 :
//        //Десериализация файла
//        //auto take = GetMessage(data.get());
//        printf("%s\n", take->key()->c_str());
//        printf("%d\n", take->user_addressee_id() );
//        printf("%d\n", take->user_sender_id());
//        printf("%s\n", take->message()->c_str());
//        break;
//    case 4:
//        break;
//    default:
//        break;
//    }
    if(for_type->type() == 0)
    {
        //Десериализация файла
        auto take = GetRegistration(data.get());
        printf("%s\n", take->login()->c_str());
        printf("%s\n", take->password()->c_str());
        printf("%s\n", take->name()->c_str());
        printf("%s\n", take->surname()->c_str());
        printf("%s\n", take->sex() ? "true" : "false");
        printf("%s\n", take->date_of_birth()->c_str());
    }
    else if(for_type->type() == 1)
    {
        //Десериализация файла
        auto take = GetSignIn(data.get());
        printf("%s\n", take->login()->c_str());
        printf("%s\n", take->password()->c_str());
    }
    else if(for_type->type() == 2)
    {
        //Десериализация файла
        auto take = GetProfile(data.get());
        printf("%s\n", take->key()->c_str());
        printf("%s\n", take->name()->c_str());
        printf("%s\n", take->surname()->c_str());
        printf("%s\n", take->sex() ? "true" : "false");
        printf("%s\n", take->data_of_birth()->c_str());
    }
    else if(for_type->type() == 3)
    {
        //Десериализация файла
        auto take = GetMessage(data.get());
        printf("%s\n", take->key()->c_str());
        printf("%llu\n", take->user_addressee_id());
        printf("%llu\n", take->user_sender_id());
        printf("%s\n", take->message()->c_str());
    }
    else if(for_type->type() == 4)
    {
        //Десериализация файла
        auto take = GetError(data.get());
        printf("%s\n", take->key()->c_str());
        printf("%d\n", take->code());
        printf("%s\n", take->description()->c_str());

    }
}
