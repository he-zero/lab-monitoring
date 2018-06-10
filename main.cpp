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
		//imshow("�ɼ�ͼ��", src);

		//����а������£���_kbhit()����������
		if (_kbhit())
		{
			int ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
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
	strftime(tmp1, sizeof(tmp1), "%m��%d��", localtime(&timep));
	strftime(tmp2, sizeof(tmp2), "%Hʱ", localtime(&timep));
	strftime(tmp3, sizeof(tmp3), "%H-%M-%S", localtime(&timep));
	mytime tmp = { tmp1, tmp2, tmp3 };
	return tmp;
}

void echo()
{
	cout << "*********************************************************" << endl;
	cout << "*\t\t" << "��ӭʹ�ü��1�Ű�ȫϵͳ" << "\t\t\t*" << endl << "*\t\t\t\t\t\t\t*" << endl;
	cout << "*\t\t   " << "���ϵͳ�Ѿ�����" << "\t\t\t*" << endl << "*\t\t\t\t\t\t\t*" << endl;
	cout << "*\t\t   " << "����ESC�˳���ϵͳ" << "\t\t\t*" << endl << "*\t\t\t\t\t\t\t*" << endl;
	cout << "*\t\t   " << "��л���Ĺ���ʹ��" << "\t\t\t*" << endl;
	cout << "*********************************************************" << endl;
}

//int CheckDir(char* Dir)
//{
//	//this function #include <direct.h><memeory><stdlib.h><stdlio.h>  
//	//����ļ����Ƿ���ڣ��������򴴽�֮  
//	//�ļ��д��ڷ���0��  
//	//�ļ��д���ʧ�ܷ���-1  
//	//�ļ��д���ʧ�ܷ���1  
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