#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>

#define port_no 5405


// Step-01 => socket() --> Creates a communication endpoint.Think of it Like: “open a phone” but no number assigned yet.
// Step-02 => bind()   --> Bind socket to your machine’s IP + port. Like: “give the phone a number.”
// Step-03 => listen() --> Prepare the socket to accept clients. Like: “keep the phone ringing.”
// Step-04 => accept() --> Creates a new socket for the connected client. Original socket continues listening.(Accepts Incoming clients)
// Step-05 => recv()   --> Receive data from client || read clients messages
// Step-06 => send()   --> Send Confimation iam accept or failed
// Step-07 => close()  --> Close server
 

int main(){

    // Socket() => Communication endpoint 
    int server_fd = socket(
        AF_INET,  // IPV4
        SOCK_STREAM, // TCP
        0 // default protocol tcp
    ); 


    if(server_fd < 0)
    {
        perror("socket failed");
    }



    // Bind() => Assign an IP & port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    // address.sin_addr.s_addr = INADDR_ANY; // any local ip
    inet_pton(AF_INET,"127.0.0.1",&address.sin_addr); 
    address.sin_port = htons(port_no);

    int binding = bind(server_fd,(struct sockaddr*)&address ,sizeof(address));
    if(binding < 0)
    {
        perror("binding failed");
    }


    // listen() => Put socket into listening mode

    int listening = listen(server_fd,5); // // max 5 connections in queue
    if(listening < 0 )
    {
        perror("listen failed");
        return 1;
    }


    // accept() => Accept Incoming Clients
    socklen_t addrlen = sizeof(address);
    int client_fd = accept(server_fd,(struct sockaddr*)&address,&addrlen);
    if(client_fd < 0)
    {
        perror("accept failed");
        return 1;
    }

    // recv() 
    char buffer[1024] = {0};
    int bytes = recv(client_fd, buffer, 1024, 0);



    if(bytes < 0 )
    {
        perror("recv failed");
    }else{
        printf("Client said: %s\n",buffer);
    }


    // send() => Send response back to client
    char *reply = "Message Received!";
    send(client_fd,reply,strlen(reply),0);


    //close() => Close Sockets
    close(client_fd);
    close(server_fd);




    return 0;
}
