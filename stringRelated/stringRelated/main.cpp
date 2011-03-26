#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QtDebug>
#include <QFile>
#include <QTextStream>

#include <string.h>

//ip转整数
long ip2long(const char *ip)
{
    //ip = 192.168.1.2
    //字符串 分解 192 168 1 2
    //分别转换为整数
    //return 192x16^3 + 168*16^2 + 1x16^1 + 2x16^0

    //**** strtok usage ****//
//    char str[100]="This is a test,and you can use it";
//    p = strtok(str," "); //注意，此时得到的   p为指向字符串:"This"，即在第一个分隔符前面的字符串，即每次找到一个分隔符后，一个空（NULL）就被放到分隔符处，所以此时NULL指针指向后面的字符串："is   a   test   ,and   you   can   use   it"。
//
//    qDebug() <<p;
//    do
//    {
//       p = strtok(NULL, " "); //NULL即为上面返回的指针，即字符串:"is a test ,and you can use it"。
//       if(p)
//           qDebug() <<" | " <<p;
//    }while(p);
}

//递归 字符串反转
char *reverse(char *str)
{
    int len = strlen(str);
    if (len <= 1)
        return str;

    char lastChar = str[len - 1];
    str[len - 1] = '\0';
    reverse(str + 1);
    str[len - 1] = str[0];
    str[0] = lastChar;

    return str;
}

void customMessageHandler(QtMsgType type, const char *msg)
{
         QString txt;
         switch (type) {
         //调试信息提示
         case QtDebugMsg:
                 txt = QString("Debug: %1").arg(msg);
                 break;

         //一般的warning提示
         case QtWarningMsg:
                 txt = QString("Warning: %1").arg(msg);
         break;
         //严重错误提示
         case QtCriticalMsg:
                 txt = QString("Critical: %1").arg(msg);
         break;
         //致命错误提示
         case QtFatalMsg:
                 txt = QString("Fatal: %1").arg(msg);
                 abort();
         }

         QFile outFile("debuglog.txt");
         outFile.open(QIODevice::WriteOnly | QIODevice::Append);
         QTextStream ts(&outFile);
         ts << txt << endl;
 }

bool replace(char *&p)
{
	if (p == NULL)
		return false;

	char *tmp = p;
	int n = 0;
	while (*tmp != '\0')
	{
		if (*tmp == '\t')
			n++;
		tmp++;
	}
	if (n == 0)
		return false;
	else{
		tmp = (char*)malloc(strlen(p) + n*3 +1);
		char *t1 = tmp;
		char *t2 = p;
		while(*t2 != '\0') {
			if (*t2 == '\t'){
				for(int i=0; i <4; i++)
				*(t1+i) = ' ';
				t1 += 3;
			}
			else
				*t1 = *t2;
			t1++;
			t2++;
		}
		//free(p);
		p = tmp;
		return true;
	}
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

	char *str = "12\t34\tabcde\tf";
	replace(str);
	qDebug() <<str; 

    char b[] = "abcdefg";
    char *p = b;
    qDebug() <<reverse(p);

    ip2long(p);

//    char p11[] = "192.168.0.136";
//    char *p1 = p11;
//    const char *pt = ".";
////    char *p2 = strtok(p1, pt);
//    char *pp = strtok(p1, pt);
//    qDebug() << pp;

//    //先注册自己的MsgHandler
//    qInstallMsgHandler(customMessageHandler);
//
//    //以后就可以像下面这样直接打日志到文件中，而且日志也会包含时间信息
//    qDebug() <<"size of char " <<sizeof(char);
//
//         qDebug("This is a debug message at thisisqt.com");
//         qWarning("This is a warning message  at thisisqt.com");
//         qCritical("This is a critical message  at thisisqt.com");
//         qFatal("This is a fatal message at thisisqt.com");

//    w.show();
    return a.exec();
}
