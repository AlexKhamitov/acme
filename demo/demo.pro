TEMPLATE = app
CONFIG += console c++1z strict_c++
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../common/eh128148.cpp

HEADERS += \
    ../common/eh128148.hpp

#GCC:QMAKE_CXXFLAGS += -pedantic-errors -fsanitize=undefined
