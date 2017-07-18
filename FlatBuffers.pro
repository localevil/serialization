TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cserialization.cpp

DISTFILES += \
    schema.fbs \
    Registration.fbs \
    SignIn.fbs \
    Profile.fbs \
    Error.fbs

HEADERS += \
    schema_generated.h \
    include/flatbuffers/base.h \
    include/flatbuffers/code_generators.h \
    include/flatbuffers/flatbuffers.h \
    include/flatbuffers/flatc.h \
    include/flatbuffers/flexbuffers.h \
    include/flatbuffers/grpc.h \
    include/flatbuffers/hash.h \
    include/flatbuffers/idl.h \
    include/flatbuffers/reflection.h \
    include/flatbuffers/reflection_generated.h \
    include/flatbuffers/registry.h \
    include/flatbuffers/util.h \
    flatbuffers/base.h \
    flatbuffers/code_generators.h \
    flatbuffers/flatbuffers.h \
    flatbuffers/flatc.h \
    flatbuffers/flexbuffers.h \
    flatbuffers/grpc.h \
    flatbuffers/hash.h \
    flatbuffers/idl.h \
    flatbuffers/reflection.h \
    flatbuffers/reflection_generated.h \
    flatbuffers/registry.h \
    flatbuffers/util.h \
    cserialization.h \
    Error_generated.h \
    Profile_generated.h \
    Registration_generated.h \
    SignIn_generated.h
