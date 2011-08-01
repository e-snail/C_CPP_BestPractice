#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

extern "C" {
//for sockets programming
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <netdb.h>
}

#define MYPORT 3490
#define MAXDATASIZE 1024

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ClientSocketEntry();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ClientSocketEntry()
{
    int sockfd, numbytes;
    char buf[MAXDATASIZE];

    struct hostent *he;
    struct sockaddr_in their_addr;

    if((he = gethostbyname("192.168.1.106")) == NULL) {
        qDebug("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        qDebug("socket");
        exit(1);
    }

    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(MYPORT);
    their_addr.sin_addr = *((struct in_addr *)(he->h_addr));
    bzero(&(their_addr.sin_zero), sizeof(struct sockaddr));

    qDebug() <<"------ " <<he->h_name;

    if (::connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        qDebug() <<"connect error";
        exit(1);
    }

    if ((numbytes = recv(sockfd, buf, MAXDATASIZE, 0)) == -1) {
        qDebug() <<"recv error";
        exit(1);
    }

    buf[numbytes] = '/0';

    qDebug() <<QString("Received: %s").arg(buf);
    ::close (sockfd);
}
