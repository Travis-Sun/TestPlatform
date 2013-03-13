/*
  windows socket operation
*/

#ifndef __MY_SOCKET__
#define __MY_SOCKET__

// controler port of in 
#define CONTROLER_PORT 4000
// test machine port of in
#define TESTER_PORT 5000

#include <windows.h>
#include <winsock2.h>

// add or del the client machine(test machine) function.
typedef int (*Func)(char* str_cmd);

/*
  creat a server to listen
*/
int create_server_to_listen(const short port, const Func func);

/*
  send cmd to server
 */
int send_string_with_name(const char* str_ip, const short int_port, const char* str_value);
int send_string_with_connect(const Socket socket_conn, const char* str_value);

/*
  connect to server
*/
Socket get_connect_with_server(const char* str_ip, const short int_port);



#endif
