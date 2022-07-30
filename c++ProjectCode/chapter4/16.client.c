#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main () {

    // 创建套接字
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    // 连接服务器
    // 服务器端的数据
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    inet_pton(AF_INET, "172.0.0.1", &serveraddr.sin_addr.s_addr);
    serveraddr.sin_port = htons(9999);
    // 连接
    connect(fd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

    // 通信
    char *data = "cline";
    write(fd, data, strlen(data));
    read()

    return 0;
}