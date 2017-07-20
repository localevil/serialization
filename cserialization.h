#include "Error_generated.h"
#include "Profile_generated.h"
#include "Registration_generated.h"
#include "SignIn_generated.h"
#include "Message_generated.h"
#include <iostream>
//#include <variant>

#ifndef CSERIALIZATION_H
#define CSERIALIZATION_H

using namespace Schema;

class CSerialization
{
public:
    CSerialization();
    ~CSerialization();
    bool serialization(const std::string &passed_file, std::string passed_login, std::string passed_password,
                                       std::string passed_name, std::string passed_surname, bool passed_sex,
                                       std::string passed_data_of_birth); //Регистрация
    bool serialization(const std::string &passed_file, const std::string &passed_login, const std::string &passed_password); // Вход
    bool serialization(const std::string &passed_file, const std::string &passed_key, const std::string &passed_name,
                                      const std::string &passed_surname, const bool &passed_sex, const std::string &passed_data_of_birth); // Профиль
    bool serialization(const std::string &passed_file, const std::string &passed_key, const unsigned long &passed_user_addressee_id,
                                       const unsigned long &passed_user_sender_id, const std::string &passed_message,
                                       const std::string &passed_data_time); // Сообщение
    bool serialization(const std::string &passed_file, const std::string &passed_key, const int16_t &passed_code, const std::string &passed_discriprion); // Ошибка
    void deserialization(const std::string &passed_file);

private:
    std::unique_ptr<flatbuffers::FlatBufferBuilder> builder;
    void save_to_file(const std::string &passed_file);
};

#endif // CSERIALIZATION_H
