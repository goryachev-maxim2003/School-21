QT       += core gui printsupport

QMAKE_CXXFLAGS += -Wa,-mbig-obj #Makefile error

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creditcalc.cpp \
    depositcalc.cpp \
    main.cpp \
    mainwindow.cpp \
    ../s21_validation.c \
    ../s21_GUI_functions.c \
    ../s21_calculate.c \
    ../s21_infix_to_postfix.c \
    ../s21_postfix_to_double.c \
    qcustomplot.cpp \
    ../s21_creditCalc.c \
    ../s21_depositCalc.c

HEADERS += \
    creditcalc.h \
    depositcalc.h \
    mainwindow.h \
    ../s21_validation.h \
    ../s21_GUI_functions.h \
    ../s21_calculate.h \
    ../s21_infix_to_postfix.h \
    ../s21_postfix_to_double.h \
    qcustomplot.h \
    ../s21_creditCalc.h \
    ../s21_depositCalc.h

FORMS += \
    creditcalc.ui \
    depositcalc.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
