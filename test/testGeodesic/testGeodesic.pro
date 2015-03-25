
include(../../common.pri)


M4D_DIR     = $$PWD/../../
TEMPLATE = app

CONFIG(debug, debug|release) {
    TARGET      = m4dTestGeodesic_debug
    DESTDIR     = .
    OBJECTS_DIR = $$M4D_DIR/compiled/debug
    unix {
       LIBS += -Wl,-rpath $$M4D_DIR/lib -L$$M4D_DIR/lib -lm4d_debug
    }
}

CONFIG(release, debug|release) {
    TARGET      = m4dTestGeodesic
    DESTDIR     = .
    OBJECTS_DIR = $$M4D_DIR/compiled/release
    unix {
       LIBS += -Wl,-rpath $$M4D_DIR/lib -L$$M4D_DIR/lib -lm4d
    }
}

INCLUDEPATH += . $$M4D_DIR $$M4D_DIR/src

SOURCES = testGeodesic.cpp

unix {
    LIBS += -Wl,-rpath $$GSL_LIB_DIR -L$$GSL_LIB_DIR -lgsl -lgslcblas
    USE_LUA {
        LIBS += -L$$LUA_LIB_DIR -llua -ldl
    }
}

p_app.path  = $$PREFIX/bin
p_app.files = $$TARGET
p_other.path  = $$PREFIX/bin
p_other.files = plotSchwGeods.gnu

INSTALLS += p_app p_other
