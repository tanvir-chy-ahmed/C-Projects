#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define port_no 5405

int main()
{

    // socket() 
    int sock_fd = socket(AF_INET,SOCK_STREAM,0);
    if(sock_fd < 0)
    {
        perror("socket failed");
        return 1;
    }

    // connect()  -- I want to talk to this IP and port.
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_no);


    if(inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr) <= 0)
    {
        perror("Invalid address / address not supported");
        return 1;
    }

    int connection = connect(sock_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    if(connection < 0)
    {
        perror("Connection failed");
        return 1;
    }


    // send()  -- send message to server
    char message[20] = "Hello Server";
    send(sock_fd,message,strlen(message),0);
    printf("Message sent to server");



    // recv()
    char buffer[1024] = {0};
    int valread = recv(sock_fd,buffer,1024,0);
    printf("Server %s\n",buffer);

    close(sock_fd);



    return 0;
}
