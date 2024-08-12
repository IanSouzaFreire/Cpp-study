#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

std::string readFileContents(const std::string &filePath);

int main(int, char** argv) {
  using namespace std;

  SOCKET wsocket;
  SOCKET new_wsocket;
  WSADATA wsaData;
  struct sockaddr_in server;
  int server_len;
  int BUFER_SIZE = 30720;

  cout << "open \"http://localhost:8080\" in your browser!";

  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != NO_ERROR) {
    return 1; // Could not initialize
  }

  wsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (wsocket == INVALID_SOCKET) {
    return 1; // Could not create socket
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_port = htons(8080);
  server_len = sizeof(server);

  if (bind(wsocket, (SOCKADDR *)&server, server_len) != 0) {
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
    auto bytes = recv(new_wsocket, buff, BUFER_SIZE, 0);

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

std::string readFileContents(const std::string &filePath) {
  std::ifstream file(filePath);

  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + filePath);
  }

  std::string content;
  file.seekg(0, std::ios::end);
  content.resize(file.tellg());
  file.seekg(0, std::ios::beg);
  file.read(&content[0], content.size());
  file.close();

  return content;
}