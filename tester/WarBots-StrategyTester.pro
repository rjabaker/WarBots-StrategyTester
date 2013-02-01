HEADERS       = comm/receiver.h \
				comm/netraw.h \
				comm/sender.h \
				ai/ai.h \
				general/defs.h \
				general/debug.h
SOURCES       = main.cpp \
				comm/receiver.cpp \
				comm/sender.cpp \
				comm/netraw.cpp \
				proto/messages_robocup_ssl_wrapper.pb.cc \
				proto/messages_robocup_ssl_detection.pb.cc \
				proto/messages_robocup_ssl_geometry.pb.cc \
				proto/grSim_Replacement.pb.cc \
				proto/grSim_Commands.pb.cc \
				proto/grSim_Packet.pb.cc \
				ai/ai.cpp \
				general/defs.cpp \
				general/settings.cpp \
				player/playerBlue.cpp \
				player/playerYellow.cpp \
				general/debug.cpp				
QT           += network
QMAKE_CXXFLAGS += `pkg-config protobuf --cflags`
LIBS += -L$$PWD/libs/ \
    -L/usr/local/lib \
	`pkg-config protobuf --libs`

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/multicastreceiver
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS multicastreceiver.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/network/multicastreceiver
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)