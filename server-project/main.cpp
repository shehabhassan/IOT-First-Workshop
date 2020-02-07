#include <stdio.h>
#include <winsock2.h>

#define MAX_CLIENT  10
int main(int argc, char *argv[])
{
    
    // just for windows .
    WSADATA wsa; // strctutre.
    SOCKET s , new_s ;  // socket desc
    struct sockaddr_in echoServer ,echoClient;
  //////////////////////////////////////////////////
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
    printf("Initialised.\n");

    // this for socket creatings.

    if((s = socket(PF_INET,SOCK_STREAM, 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }
     printf("Socket created.\n");
    /////////////////////////////////////////////////////////////
    int  size;
    //////////////////////////////////////////////////////////////////
    echoServer.sin_family = AF_INET ; // Address family
   echoServer.sin_port = htons(100);
    echoServer.sin_addr.s_addr = inet_addr(INADDR_ANY);

    if( bind(s,(struct sockaddr *) &echoServer,sizeof( echoServer) ) < 0){
           printf("Error\n");
            }
          listen (s,MAX_CLIENT);

    if( new_s = accept(s ,(struct sockaddr *) &echoClient, &size )< 0){
     printf("error");
      }
for(;;){
             char massage[2000]= "Hello";
             char recv_buf[2000]="";
       recv(s,recv_buf,2000,0);
  if (!strcmp(massage,"work")){
      printf("Right\n");
  }
       send(s,massage,strlen(massage),0);

          printf("%s",recv_buf);
          puts(recv_buf);
}

    closesocket(s);
   /////////////////////////////
    return 0;
    /*int i=0;
  while(i!=500){i++;
  }*/
}
