#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[]){
  //creates an endpoint for communication, returns a file descriptor. For the socket.
   
  struct sockaddr_in ip4addr;
  memset(&ip4addr, 0, sizeof(struct sockaddr_in));
  
  ip4addr.sin_family = AF_INET;
  ip4addr.sin_port = htons(3000); //ensures that TCP port number is able to be read across all machines.
  ip4addr.sin_addr.s_addr = INADDR_ANY; 
  int descriptor;
  
  //create a TCP endpoint. 
  descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if(descriptor == -1){
    perror("socket failed");
    return -1;
  }
  
  int sockbind;
  
  //makes the socket associated with an address. Needs to be performed before the socket can
  //accept connections from other hosts.
  sockbind = bind(descriptor, (struct sockaddr *)&ip4addr, sizeof(struct sockaddr_in));
  
  if(sockbind != 0){
    perror("bind failed");
    return -1;
  }

  int listening;
  listening = listen(descriptor, 10);
  //prepares our adress for incoming connnections.
  if(listening!= 0){
    perror("listening failed");
    return -1;
  }
  struct sockaddr_in client_addr;
  memset(&client_addr,0, sizeof(struct sockaddr_in));
  socklen_t client_len = sizeof(client_addr);
  
  int accepted;
  //Connect to the port that we are listeing on. 
  //Creates a new socket associated with our socket address.
  accepted = accept(descriptor, (struct sockaddr *)&client_addr, &client_len);

  if(accepted == -1){
    perror("Socket not accepted");
    return -1;
  }
  
  //connect(descriptor, ip4addr.sin_addr, sizeof(ip4addr.sin_addr));

  return 0;
}
