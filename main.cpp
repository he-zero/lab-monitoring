#include<opencv.hpp>
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include<io.h>
#include <direct.h> 
#include <fstream>

using namespace std;
using namespace cv;

struct mytime
{
	string MD;
	string H;
	string HNS;
};

void echo();
mytime getTime();

int main()
{
	echo();

	mytime dqsj;
	bool stop = false;
	VideoCapture cap(0);

	Mat	src, dst;
	string name, pre, lujing;
	pre = "C:\\Users\\Public\\Pictures\\ScreenShot\\";

	while (!stop)
	{
		cap >> src;
		resize(src, dst, Size(240, 180), 0, 0, 1);
		dqsj = getTime();
		lujing = pre + dqsj.MD + "\\" + dqsj.H;
		
		fstream _file;
		_file.open(lujing, ios::in);
		if (!_file)
		{
			_mkdir(lujing.c_str());
		}
		

		name = pre + dqsj.MD + "\\" + dqsj.H + "\\" + dqsj.HNS + ".jpg";
		//cout << name << endl;
		imwrite(name, dst);
		Sleep(1000);
		//imshow("采集图像", src);

		//如果有按键按下，则_kbhit()函数返回真
		if (_kbhit())
		{
			int ch = _getch();//使用_getch()函数获取按下的键值
			if (ch == 27)
			{
				stop = true;
			}
		}
	}

	return 0;
}


mytime getTime()
{
	time_t timep;
	time(&timep);
	//string tmp;
	char tmp1[64], tmp2[64], tmp3[64];
	strftime(tmp1, sizeof(tmp1), "%m月%d日", localtime(&timep));
	strftime(tmp2, sizeof(tmp2), "%H时", localtime(&timep));
	strftime(tmp3, sizeof(tmp3), "%H-%M-%S", localtime(&timep));
	mytime tmp = { tmp1, tmp2, tmp3 };
	return tmp;
}

void echo()
{
	cout << "*********************************************************" << endl;
	cout << "*\t\t" << "欢迎使用监控1号安全系统" << "\t\t\t*" << endl << "*\t\t\t\t\t\t\t*" << endl;
	cout << "*\t\t   " << "监控系统已经开启" << "\t\t\t*" << endl << "*\t\t\t\t\t\t\t*" << endl;
	cout << "*\t\t   " << "按下ESC退出本系统" << "\t\t\t*" << endl << "*\t\t\t\t\t\t\t*" << endl;
	cout << "*\t\t   " << "感谢您的购买使用" << "\t\t\t*" << endl;
	cout << "*********************************************************" << endl;
}

//int CheckDir(char* Dir)
//{
//	//this function #include <direct.h><memeory><stdlib.h><stdlio.h>  
//	//检查文件夹是否存在，不存在则创建之  
//	//文件夹存在返回0，  
//	//文件夹创建失败返回-1  
//	//文件夹创建失败返回1  
//
//	FILE *fp = NULL;
//	char TempDir[200];
//	memset(TempDir, '\0', sizeof(TempDir));
//	sprintf(TempDir, Dir);
//	strcat(TempDir, "\\");
//	fp = fopen(TempDir, "w");
//	if (!fp)
//	{
//		if (_mkdir(Dir) == 0)
//		{
//			return 1;
//		}
//		else
//		{
//			return -1;
//		}
//	}
//	else
//	{
//		fclose(fp);
//	}
//	return 0;
//
//	//main's test sentence    
//	//char *filePath="G:\\project\\divGraph\\divGraph\\img2";  
//	//CheckDir(filePath);  
//}