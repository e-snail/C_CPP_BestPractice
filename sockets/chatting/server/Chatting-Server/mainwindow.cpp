#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
}

#define MYPORT 3490 /*定义用户连接端口*/
#define BACKLOG 10 /*多少等待连接控制*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ChatServerEntry();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ChatServerEntry()
{
    int sockfd, new_fd;
    struct sockaddr_in my_addr; //my address infomation
    struct sockaddr_in their_addr; //connector's address info
    socklen_t sin_size; //int sin_size;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        qDebug() <<"socket error";
        exit(1);
    }

    my_addr.sin_family = AF_INET; //host byte order
    my_addr.sin_port = htons(MYPORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero), sizeof(struct sockaddr));

    if (::bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
        qDebug() <<"bind error";
        exit(1);
    }

    while (1) {
        sin_size = sizeof(struct sockaddr_in);
        if ((new_fd = ::accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1) {
            qDebug() <<"accept error";
            continue;
        }
        qDebug() <<QString("server: got connection from %1").arg(inet_ntoa(their_addr.sin_addr));
        if (!fork()) {
            if (send(new_fd, "Hello, world!/n", 14, 0) == -1)
                qDebug() <<"send error";
            ::close(new_fd);
            exit(0);
        }
        ::close(new_fd);
        while (waitpid( -1, NULL, WNOHANG) > 0);
    }
}
