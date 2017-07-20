// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_MESSAGE_SCHEMA_H_
#define FLATBUFFERS_GENERATED_MESSAGE_SCHEMA_H_

#include "flatbuffers/flatbuffers.h"

namespace Schema {

struct Message;

struct Message FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TYPE = 4,
    VT_KEY = 6,
    VT_USER_ADDRESSEE_ID = 8,
    VT_USER_SENDER_ID = 10,
    VT_MESSAGE = 12,
    VT_DATE_TIME = 14
  };
  int16_t type() const {
    return GetField<int16_t>(VT_TYPE, 0);
  }
  const flatbuffers::String *key() const {
    return GetPointer<const flatbuffers::String *>(VT_KEY);
  }
  uint64_t user_addressee_id() const {
    return GetField<uint64_t>(VT_USER_ADDRESSEE_ID, 0);
  }
  uint64_t user_sender_id() const {
    return GetField<uint64_t>(VT_USER_SENDER_ID, 0);
  }
  const flatbuffers::String *message() const {
    return GetPointer<const flatbuffers::String *>(VT_MESSAGE);
  }
  const flatbuffers::String *date_time() const {
    return GetPointer<const flatbuffers::String *>(VT_DATE_TIME);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int16_t>(verifier, VT_TYPE) &&
           VerifyOffset(verifier, VT_KEY) &&
           verifier.Verify(key()) &&
           VerifyField<uint64_t>(verifier, VT_USER_ADDRESSEE_ID) &&
           VerifyField<uint64_t>(verifier, VT_USER_SENDER_ID) &&
           VerifyOffset(verifier, VT_MESSAGE) &&
           verifier.Verify(message()) &&
           VerifyOffset(verifier, VT_DATE_TIME) &&
           verifier.Verify(date_time()) &&
           verifier.EndTable();
  }
};

struct MessageBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_type(int16_t type) {
    fbb_.AddElement<int16_t>(Message::VT_TYPE, type, 0);
  }
  void add_key(flatbuffers::Offset<flatbuffers::String> key) {
    fbb_.AddOffset(Message::VT_KEY, key);
  }
  void add_user_addressee_id(uint64_t user_addressee_id) {
    fbb_.AddElement<uint64_t>(Message::VT_USER_ADDRESSEE_ID, user_addressee_id, 0);
  }
  void add_user_sender_id(uint64_t user_sender_id) {
    fbb_.AddElement<uint64_t>(Message::VT_USER_SENDER_ID, user_sender_id, 0);
  }
  void add_message(flatbuffers::Offset<flatbuffers::String> message) {
    fbb_.AddOffset(Message::VT_MESSAGE, message);
  }
  void add_date_time(flatbuffers::Offset<flatbuffers::String> date_time) {
    fbb_.AddOffset(Message::VT_DATE_TIME, date_time);
  }
  MessageBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  MessageBuilder &operator=(const MessageBuilder &);
  flatbuffers::Offset<Message> Finish() {
    const auto end = fbb_.EndTable(start_, 6);
    auto o = flatbuffers::Offset<Message>(end);
    return o;
  }
};

inline flatbuffers::Offset<Message> CreateMessage(
    flatbuffers::FlatBufferBuilder &_fbb,
    int16_t type = 0,
    flatbuffers::Offset<flatbuffers::String> key = 0,
    uint64_t user_addressee_id = 0,
    uint64_t user_sender_id = 0,
    flatbuffers::Offset<flatbuffers::String> message = 0,
    flatbuffers::Offset<flatbuffers::String> date_time = 0) {
  MessageBuilder builder_(_fbb);
  builder_.add_user_sender_id(user_sender_id);
  builder_.add_user_addressee_id(user_addressee_id);
  builder_.add_date_time(date_time);
  builder_.add_message(message);
  builder_.add_key(key);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<Message> CreateMessageDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int16_t type = 0,
    const char *key = nullptr,
    uint64_t user_addressee_id = 0,
    uint64_t user_sender_id = 0,
    const char *message = nullptr,
    const char *date_time = nullptr) {
  return Schema::CreateMessage(
      _fbb,
      type,
      key ? _fbb.CreateString(key) : 0,
      user_addressee_id,
      user_sender_id,
      message ? _fbb.CreateString(message) : 0,
      date_time ? _fbb.CreateString(date_time) : 0);
}

inline const Schema::Message *GetMessage(const void *buf) {
  return flatbuffers::GetRoot<Schema::Message>(buf);
}

inline bool VerifyMessageBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Schema::Message>(nullptr);
}

inline void FinishMessageBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Schema::Message> root) {
  fbb.Finish(root);
}

}  // namespace Schema

#endif  // FLATBUFFERS_GENERATED_MESSAGE_SCHEMA_H_
