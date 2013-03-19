#include "mysocket.h"


int create_server_to_listen(const short port, const Func func)
{
    WSADATA wsd;
    SOCKET server_socket, cient_socket;
    
    struct sockaddr_in LocalAddr, ClientAddr;
    if( WSAStartup(MAKEWORD(2,0),&wsd) )
	{
        //fprint("Init Windows Socket Failed");
		return 1;
	}
    server_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
 
    if( cClient == INVALID_SOCKET)
	{
		return 0;
	}
    return 0;
}


Socket get_connect_with_server(const char* str_ip, const short int_port)
{
    return NULL;
}

int send_string_with_name(const char* str_ip, const short int_port, const char* str_value)
{
    return 0;
}



int send_string_with_connect(const Socket socket_conn, const char* str_value)
{
    return 0;
}
