#include "mysocket.h"


int create_server_to_listen(const short port, const Func func)
{
    WSADATA  Ws;
    SOCKET ServerSocket, ClientSocket;
    struct sockaddr_in LocalAddr, ClientAddr;
    int Ret = 0;
    int AddrLen = 0;
    HANDLE hThread = NULL;

    //Init Windows Socket
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        printf("Init Windows Socket Failed:%s\n",GetLastError());
        return -1;
    }

    //Create Socket
    ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( ServerSocket == INVALID_SOCKET )
    {
        printf("Create Socket Failed:%s\n",GetLastError());
        return -1;
    }

    LocalAddr.sin_family = AF_INET;
    LocalAddr.sin_addr.s_addr = inet_addr(CONTROLER_PORT);
    LocalAddr.sin_port = htons(port);
    memset(LocalAddr.sin_zero, 0x00, 8);

    //Bind Socket
    Ret = bind(ServerSocket, (struct sockaddr*)&LocalAddr, sizeof(LocalAddr));
    if ( Ret != 0 )
    {
        printf("Bind Socket Failed:%s\n",GetLastError());
        return -1;
    }

    while(1)
    {
        Ret = listen(ServerSocket, 100);
        if ( Ret != 0 )
        {
            printf("listen Socket Failed:%s\n",GetLastError());
            return -1;
        }

        //muti-thread deal with the listen
        
        
        while(1)
        {
            AddrLen = sizeof(ClientAddr);
            ClientSocket = accept(ServerSocket,(struct sockaddr*)&ClientAddr,&AddrLen);
            if (ClientSocket==INVALID_SOCKET)
            {
                printf("Accpet Failed:%s\n",GetLastError());
                break;
            }
            // client info in ClientAddr, can get info
            // address:inet_ntoa(ClientAddr.sin_addr) ;port: ClientAddr.sin_port

            // create thread to deal with the socket
        }
        closesocket(ServerSocket);
        closesocket(ClientSocket);
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
