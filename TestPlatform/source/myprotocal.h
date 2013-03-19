/*
  myprotocol to socket
*/

#ifndef __MY_PROTOCOL__
#define __MY_PROTOCOL__

#include "mysocket.h"
/*
  reister the test machine with ip and machine name to controler
*/



int register_test_machine(const char* str_ip, const char* str_machine_name);

int run_on_test_machine(const char* str_machine_name);

int connect_server(const char* str_dip, const char* str_machine_name);

int get(char* cmd, char* args);

int set(char* cmd, char* args);


#endif
