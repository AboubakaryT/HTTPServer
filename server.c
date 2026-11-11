#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[]){
  //creates an endpoint for communication, returns a file descriptor. For the socket.
   
  struct sockaddr_in ip4addr, *res;
  memset(&ip4addr,0, sizeof(struct sockaddr_in));
  
  ip4addr.sin_family = AF_INET;
  ip4addr.sin_port = htons(3000);
  ip4addr.sin_addr.s_addr = INADDR_ANY;
  int descriptor;
  
  descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if(descriptor == -1){
    perror("socket failed");
    return -1;
  }

  //memset(&sockaddr_in, 0, sizeof(sockaddr_in));
  int sockbind;
  //makes the socket associated with an address. Needs to be performed before the socket can
  //accept connections from other hosts.
  sockbind = bind(descriptor, (struct sockaddr *)&ip4addr, sizeof(struct sockaddr_in));
  if(sockbind != 0){
    perror("bind failed");
    return -1;
  }
  int listening;
  connected = listen(descriptor, 10);

  if(listening!= 0){
    perror("connection failed");
  }


  return 0;
}
