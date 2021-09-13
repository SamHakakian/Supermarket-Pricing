QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ./include ./data

SOURCES += \
    src/ItemListParser.cpp \
    src/Reprice_BOGO.cpp \
    src/Reprice_Bundled.cpp \
    src/Reprice_Taxed.cpp \
    src/main.cpp \
    src/SupermarketPricing.cpp

HEADERS += \
    include/Containers.h \
    include/Interface_Reprice.h \
    include/ItemListParser.h \
    include/Reprice_BOGO.h \
    include/Reprice_Bundled.h \
    include/Reprice_Taxed.h \
    include/SupermarketPricing.h

OTHER_FILES += \
    data/products.dat \
    data/BOGOsale.dat \
    data/bundledSale.dat \
    data/taxed.dat


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
