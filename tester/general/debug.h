#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <cstdio>
#include <cstring>

#include "../proto/messages_robocup_ssl_wrapper.pb.h"
#include "../proto/messages_robocup_ssl_detection.pb.h"
#include "../proto/messages_robocup_ssl_geometry.pb.h"
#include "defs.h"

void printDetectionFrame(SSL_DetectionFrame* df, const char* dmsg);
void printFieldState(FieldState* fs, const char* dmsg);

#endif