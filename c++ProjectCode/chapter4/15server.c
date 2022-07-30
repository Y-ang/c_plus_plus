#include <stdio.h>
#include <arpa/inet.h>


int main() {
    // 1. 创建socket（用于监听的套接字）
    int lfd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. 绑定
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;

    // 转换ip地址 主机字节序转换为网络字节序
    // inet_pton(AF_INET, "127.0.0.1", saddr.sin_addr.s_addr);  // 将主机字节序（点分十进制转pot）换为网络字节序（net）
    saddr.sin_addr.s_addr = INADDR_ANY;  // 0.0.0.0  表示任意的地址  计算机无线网卡、以太网卡的地址不一样，制定0表示连个都绑定
    // 端口号，主机字节序转换为网络字节序
    saddr.sin_port = htons(9999);
    
    int ret = bind(lfd, (struct sockaddr *)&saddr, sizeof(saddr));

    if (ret == -1) {
        perror();
    }

    // 3. 监听
    ret = listen(lfd, 8);
    if (ret == -1) {
        perror();
    }

    // 4. 接受客户端的连接
    struct sockaddr_in clientaddr;
    socklen_t len = sizeof(clientaddr);

    int cfd = accept(lfd, (struct sockaddr *)&clientaddr, &len);
    if (cfd == -1) {
        perror();
    }

    // 输出客户端信息
    char clientIP[16];
    inet_ntop(AF_INET, &clientaddr.sin_addr.s_addr, clientIP, sizeof(clientaddr ));

    // 5. 服务器和客户端进行通信


    return 0;
}