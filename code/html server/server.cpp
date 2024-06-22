#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32")
#include <WinSock2.h>
#include <fstream>
#include <string>

using namespace std;

string readFileContents(const string &filePath) {
  ifstream file(filePath);
  if (!file.is_open()) {
    throw runtime_error("Failed to open file: " + filePath);
  }

  string content;
  file.seekg(0, ios::end);
  content.resize(file.tellg());
  file.seekg(0, ios::beg);
  file.read(&content[0], content.size());
  file.close();

  return content;
}

int main() {
  SOCKET wsocket;
  SOCKET new_wsocket;
  WSADATA wsaData;
  struct sockaddr_in server;
  int server_len;
  int BUFER_SIZE = 30720;

  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    return 1; // Could not initialize
  }

  wsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (wsocket == INVALID_SOCKET) {
    return 1; // Could not create socket
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_port = htons(8080);
  server_len = sizeof(server)

  if (bind(wsocket, (SOCKADD *)&server, server_len) != 0) {
    return 1; // Could not bind socket
  }

  if (listen(wsocket, 20) != 0) {
    return 1; // Could not start listening
  }

  // If server listening started
  while (true) {
    new_wsocket = accept(wsocket, (SOCKADDR *)&server, &server_len);

    if (new_wsocket == INVALID_SOCKET) {
      return 1; // Could not accept
    }

    char buff[30720] = { 0 };
    bytes = recv(new_wsocket, buff BUFER_SIZE, 0);

    if (bytes < 0) {
      return 1; // Could not read client request
    }

    string serverMessage = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-length: ";
    string response = readFileContents("index.html");
    serverMessage.append(to_string(response.size()));
    serverMessage.append("\n\n");
    serverMessage.append(response);

    int bytesSent = 0;
    int totalBytesSent = 0;

    while (totalBytesSent < serverMessage.size()) {
      bytesSent = send(new_wsocket, serverMessage.c_str(), serverMessage.size(), 0);

      if (bytesSent < 0) {
        return 1; // Could not send response
      }

      totalBytesSent += bytesSent;
    }

    closesocket(new_wsocket);
  }

  closesocket(new_wsocket);
  return 0;
}