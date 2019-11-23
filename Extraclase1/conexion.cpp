#include "conexion.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>


#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>



void conexion::enviarmensaje(string infoenviar){
    //	Create a socket+
    cout<<"A ENVIAR ------------------------------"<<endl;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        return;
    }

    //	Create a hint structure for the server we're connecting with
    int port = 6969;
    string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return;
    }

    //	While loop:
    char buf[4096];


        char mensajeCliente[sizeof(infoenviar)];
        strcpy(mensajeCliente, infoenviar.c_str());
        cout<<strlen(mensajeCliente)<<endl;
        int sendRes = send(sock, mensajeCliente, strlen(mensajeCliente), 0);
        if (sendRes == -1)
        {
            cout << "Could not send to server! Whoops!\r\n";
        }

        //		Wait for response
        memset(buf, 0, 4096);
        int bytesReceived = recv(sock, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cout << "There was an error getting response from server\r\n";
        }
        else
        {
            buf[bytesReceived] = '\0';
            cout<<buf<<endl;
            string s = buf;
            close(sock);
            return;
        }


}
