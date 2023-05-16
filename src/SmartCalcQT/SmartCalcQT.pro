QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../CreditCalc.c \
    ../DepositCalc.c \
    ../SmartCalc.c \
    SmartCalcQT.cpp \
    credit.cpp \
    deposit.cpp \
    main.cpp \
    qcustomplot.cpp

HEADERS += \
    ../SmartCalc.h \
    SmartCalcQT.h \
    credit.h \
    deposit.h \
    qcustomplot.h

FORMS += \
    SmartCalcQT.ui \
    credit.ui \
    deposit.ui

ICON = $${PWD}/calc.icns

TARGET = Smart_Calculator

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
