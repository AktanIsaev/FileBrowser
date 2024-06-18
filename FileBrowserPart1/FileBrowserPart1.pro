QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        context.cpp \
        group_by_folder.cpp \
        group_by_type.cpp \
        item_info.cpp \
        main.cpp \
        print_helpers.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    context.h \
    group_by_folder.h \
    group_by_strategy.h \
    group_by_type.h \
    item_info.h \
    print_helpers.h
