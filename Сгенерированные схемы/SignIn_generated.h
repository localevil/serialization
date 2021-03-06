// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SIGNIN_SCHEMA_H_
#define FLATBUFFERS_GENERATED_SIGNIN_SCHEMA_H_

#include "flatbuffers/flatbuffers.h"

namespace Schema {

struct SignIn;

struct SignIn FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TYPE = 4,
    VT_LOGIN = 6,
    VT_PASSWORD = 8
  };
  int16_t type() const {
    return GetField<int16_t>(VT_TYPE, 0);
  }
  const flatbuffers::String *login() const {
    return GetPointer<const flatbuffers::String *>(VT_LOGIN);
  }
  const flatbuffers::String *password() const {
    return GetPointer<const flatbuffers::String *>(VT_PASSWORD);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int16_t>(verifier, VT_TYPE) &&
           VerifyOffset(verifier, VT_LOGIN) &&
           verifier.Verify(login()) &&
           VerifyOffset(verifier, VT_PASSWORD) &&
           verifier.Verify(password()) &&
           verifier.EndTable();
  }
};

struct SignInBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_type(int16_t type) {
    fbb_.AddElement<int16_t>(SignIn::VT_TYPE, type, 0);
  }
  void add_login(flatbuffers::Offset<flatbuffers::String> login) {
    fbb_.AddOffset(SignIn::VT_LOGIN, login);
  }
  void add_password(flatbuffers::Offset<flatbuffers::String> password) {
    fbb_.AddOffset(SignIn::VT_PASSWORD, password);
  }
  SignInBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  SignInBuilder &operator=(const SignInBuilder &);
  flatbuffers::Offset<SignIn> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<SignIn>(end);
    return o;
  }
};

inline flatbuffers::Offset<SignIn> CreateSignIn(
    flatbuffers::FlatBufferBuilder &_fbb,
    int16_t type = 0,
    flatbuffers::Offset<flatbuffers::String> login = 0,
    flatbuffers::Offset<flatbuffers::String> password = 0) {
  SignInBuilder builder_(_fbb);
  builder_.add_password(password);
  builder_.add_login(login);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<SignIn> CreateSignInDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int16_t type = 0,
    const char *login = nullptr,
    const char *password = nullptr) {
  return Schema::CreateSignIn(
      _fbb,
      type,
      login ? _fbb.CreateString(login) : 0,
      password ? _fbb.CreateString(password) : 0);
}

inline const Schema::SignIn *GetSignIn(const void *buf) {
  return flatbuffers::GetRoot<Schema::SignIn>(buf);
}

inline bool VerifySignInBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Schema::SignIn>(nullptr);
}

inline void FinishSignInBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Schema::SignIn> root) {
  fbb.Finish(root);
}

}  // namespace Schema

#endif  // FLATBUFFERS_GENERATED_SIGNIN_SCHEMA_H_
