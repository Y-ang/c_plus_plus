#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>  // 和错误号相关
#include <fcntl.h>  // 操作文件描述符
#include <sys/epoll.h>
#include "locker.h"
#include "threadpool.h"
#include <signal.h>
#include "http_conn.h"

#define MAX_FD 65535 // 最大的文件描述符个数

// 信号处理，添加信号捕捉
void addsig(int sig, void(handler)(int)) {
    struct sigaction sa;    // 信号
    memset(&sa, '\0', sizeof(sa));  // 所有信号置为空
    sa.sa_handler = handler;
    sigfillset(&sa.sa_mask);  // 设置临时阻塞信号集
    sigaction(sig, &sa, NULL);
}



int main(int argc, char* argv[]) {

    if (argc <= 1) {
        printf("按如下格式运行：%s port_number\n", basename(argv[0]));
        exit(-1);
    }

    // 获取端口号
    int port = atoi(argv[1]);
    
    // 对sigpie信号进程处理,  网络通信的一端已关闭，另一段还在写就会报SIGPIPE信号
    addsig(SIGPIPE, SIG_IGN);

    //创建线程池,初始化线程池
    threadpool<http_conn> * pool = NULL;
    try {
        pool = new threadpool<http_conn>;
    } catch (...) {
        exit(-1);
    }

    // 创建一个数组用于保存所有客户端信息
    http_conn * users = new http_conn[MAX_FD];

    int listenfd = socket(PF_INET, SOCK_STREAM, SOCK_STREAM, 0);

    // 设置端口复用
    setsockopt()

    return 0;
}