#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define LEN sizeof(struct student)
#define LEN2 sizeof(struct login)

struct student // 成員資訊
{
	char num[20], nam[20];
	char scoreA[3],scoreB[3],scoreC[3];
	
	struct student *next; // 鏈結成員
};

struct login // 登錄資訊
{
	int zhanghao;
	char password[20];
	struct login *next;
};

void lmain();
void xg(int,char[] );
void login();//登錄功能系統 
int create(int,char[] );//創建帳號密碼 
void xgmm(); // 修改密碼

void main1();//主菜單 
void addScore();//增加成績 
void delScore();//刪除成績 
void browseScore();//瀏覽成績 
int tjzs3()//統計帳號密碼個數 
{
FILE *fp;
int zhao=0,n;
char mm[20]={'\0'};

fp=fopen("login.txt","r");//打開文件
for (n=0;!feof(fp);n++)//逐個讀文件
fscanf(fp,"%d %s",&zhao,mm);

n--;//當讀到文件末尾時，文件指針並未超出文件，所以會多讀一次。
fclose(fp);//關閉文件
return (n);//返回個數 
}

int tjzs()//統計成員數量 
{
FILE *fp;
int txcl=0,n;
char scoreA[3]={'\0'},scoreB[3]={'\0'},scoreC[3]={'\0'};
char nam[20]={'\0'},num[20]={'\0'};
fp=fopen("Score.txt","r");//打開文件
for (n=0;!feof(fp);n++)//逐個讀文件
fscanf(fp,"%s%s%s%s%s",num,nam,scoreA,scoreB,scoreC);
n--;
fclose(fp);//關閉文件
return (n);//返回個數
}

void mainmenu() // 主菜單
{
	system("cls");

	printf("**************************************************");

	printf("\n\n 1.新增成績\n\n");
	
	printf("\n\n 2.刪除成績\n\n");
	
	printf("\n\n 3.瀏覽成績\n\n");

	printf("\n\n 4.退出系統\n\n");

	printf("\n\n 請按鍵選擇，Enter确定\n");

	printf("*************************************************\n");

	return;
}

void main1()
{
	
	
	char choose;
	mainmenu();
	scanf(" %c",&choose);
	switch(choose)//功能函數 
    {
		case'1':
	    	addScore();
	  	break;
	  
	  	case'2':
	    	delScore();
	  	break;
	  
	  	case'3':
	    	browseScore();
	  	break;
	  	  
	  	case'4':
	  		system("cls");
    		getch();
  			exit(0);
  			system ("cls");
	  	break;
    }
}

void addScore()//增加成績 
{
	FILE*fp;
	char i;
	char scoreA[3]={'\0'},scoreB[3]={'\0'},scoreC[3]={'\0'};
	
    
    char  nam[20]={'\0'},num[20]={'\0'};
    system ("cls");

    if ((fp=fopen("Score.txt","r"))==NULL)//if語句：打開文件，不存在此文件則新建
	{
    	fp=fopen("Score.txt","w");
    	fclose(fp);
    }
	fp=fopen("Score.txt","a");
	
	printf("\n請按以下格式輸入成員信息:\學號 姓名 科目A 科目B 科目C ");
	
	for(;i!=27;)//為了實現輸入一次後按esc退出
	{
		printf("請輸入:\n");
		scanf("%s%s%s%s%s",num,nam,scoreA,scoreB,scoreC);
		fprintf(fp,"%-8s%-9s%-8s%-8s%-8s%\n",num,nam,scoreA,scoreB,scoreC);
	    printf("繼續輸入請按Enter，結束輸入請按Esc\n");
        i=getch();//暫停程序當i接收後繼續下一個指令
        for (;i!=13&&i!=27;)//保証只能是Enter和ESC才能退出循環,輸入其他字符無用，暫停程序，按'Enter'繼續。
        i=getch();
    }

	fclose(fp);
    printf("\n保存成功，按任意鍵返回上一層!");
    getch();
	main1();//返回上一層 
}

void delScore()//刪除成績 
{
		struct student *head=NULL;
        struct student *p,*p1,*p2;
        int n=0,j,k;
        char tscoreA[3]={'\0'},tscoreB[3]={'\0'},tscoreC[3]={'\0'};
        char  tnam[20]={'\0'},tnum[20]={'\0'};
	    char dnam[20]={'\0'};
	    char i;
        FILE *fp;
        if ((fp=fopen("Score.txt","r"))==NULL)//打開文件
        {
	    	system ("cls");
            printf("\n紀錄文件不存在!按任意鍵返回");
            getch();
            main1();
        }

		else//實現刪除的功能
		{
	    	system ("cls");
	    	printf("\n請輸入你要刪除的成員:");
          	scanf("%s",dnam);
          	printf("\n確認刪除請按Enter，取消請按Esc\n");
          	i=getch();
          	for(;i!=13&&i!=27;)
         		i=getch();
          	if (i==27)
          		main1();
	        fp=fopen("Score.txt","r");
		    j=tjzs();

		for (k=0;k<j;k++)
        {
	    	fscanf(fp,"%s%s%s%s%s",tnum,tnam,tscoreA,tscoreB,tscoreC);
            if (strcmp(dnam,tnam))//比較名字，將不同名字的信息複制到鏈表
            {
	        	n++;//相同返回值為0不執行if語句繼續循環，不同則執行直到將所有不同的資料建立成鏈表
	            if (n==1)//建立鏈表
                {
		        	p1=p2=(struct student*)malloc(LEN);
                	head=p1;
				}
                else
			    {
			    	p2->next=p1;
					p2=p1;
                  	p1=(struct student*)malloc(LEN);//新建鏈表
                }

                strcpy(p1->num,tnum);//複製學號
                strcpy(p1->nam,tnam);//複製姓名
                strcpy(p1->scoreA,tscoreA);//複製科目A
                strcpy(p1->scoreB,tscoreB);//複製科目B 
                strcpy(p1->scoreC,tscoreC);//複製科目C 
                 
           }
        }
        if (n==0)//如果成員只有一個且這一個剛好和要刪除的相同
		{
			head=NULL;
		}
		else//建立鏈表的最後剩餘一個儲存空間，所以封底
		{
			p2->next=p1;
			p1->next=NULL;
			fclose(fp);
		}
    }

   	fp=fopen("Score.txt","w");//清空文件，然後關閉 
   	fclose(fp);
   	fp=fopen("Score.txt","a");//追加文件
   	p=head;

   	for (;p!=NULL;)//把鏈表內容覆蓋到文件
   	{
   	   	fprintf(fp,"%-8s%-9s%-8s%-8s%-8s\n",p->num,p->nam,p->scoreA,p->scoreB,p->scoreC);
   	   	p=p->next;
   	}
   	fclose(fp);
   	system ("cls");
   	printf("\n刪除成功 \n按任意鍵返回上一層\n");
   	getch();//返回上一層 
   	main1();
}

void browseScore()//瀏覽成績 
{
	FILE *fp;
	int n=0;
    int k=0,m=0;
	char tscoreA[3]={'\0'},tscoreB[3]={'\0'},tscoreC[3]={'\0'};
    char  nam[20]={'\0'},num[20]={'\0'};
  	char i;
	if ((fp=fopen("Score.txt","r"))==NULL)//打開文件
    	{
	    	system ("cls");
            printf("\n記錄文件不存在!按任意鍵返回");
		    getch();//返回
            main1();
	    }
	    n= tjzs();
        if (n==0)
    	{
	  		system ("cls");
      		printf("\n無任何記錄!");
      	}

	    fp=fopen("Score.txt","r");//打開只讀文件
        system ("cls");
	    printf("學號\t姓名\t科目A\t科目B\t科目C\n");
  
	    for (m=0;m<n;m++)//輸出數據
	    {
	    	fscanf(fp,"%s%s%s%s%s",num,nam,tscoreA,tscoreB,tscoreC);
		 	printf("%-8s%-9s%-8s%-8s%-8s\n",num,nam,tscoreA,tscoreB,tscoreC);
	 	}
		fclose(fp);
        printf("\n按任意鍵返回\n");
        getch();
        main1();
}


void lmenu() // 顯示登錄菜單
{

	printf("\n\n\t    歡迎使用\n\n");
	printf("**********************************************");
	printf("\n\n\t\t1.登入\n\n");
	printf("\n\n\t\t2.創建帳號\n\n");
	printf("\n\n\t\t3.修改密碼\n\n");
	printf("\n\n\t\t4.退出\n\n");
	printf("\n\n\t    請按鍵選擇，Enter确定\n");
	printf("**********************************************");
	printf("\n-->");
	return;
}

void lmain() // 登錄功能函數
{
	void login();
	void create();
	char choose;
	lmenu();
	
	scanf(" %c",&choose);
	
	switch (choose) // 功能函數
	{
	case '1':
		login();
		
		break;
	case '2':
		create();
		
		break;
	case '3':
		xgmm();
		
		break;
	case '4':
		system("cls");
		getch();
		exit(0); // 表示正常退出
		system("cls");
		break;
	}
}



void create() // 新建帳戶密碼
{
	FILE *fp;
	int zhanghao, loop;
	char password[20], password1[20];
	char hit = 0;
	if ((fp = fopen("login.txt", "r")) == NULL) // if語句：打開文件，不存在此文件則新建
	{
		fp = fopen("login.txt", "w");
		fclose(fp);
	}
	system("cls");
	fp = fopen("login.txt", "a");
	do // 輸入兩次密碼确認，兩次相同才能确認
	{
		printf("\n請按以下格式輸入:\n學號 密碼\n");
		printf("請輸入:");
		scanf("%*c%d %s", &zhanghao, password);
		printf("再次輸入密碼:\n");
		scanf("%s", password1);
		if (strcmp(password, password1) == 0)
		{
			fprintf(fp,"%d %s\n",zhanghao,password);//寫入 

			/*printf("創建成功，按任意鍵返回");
			getch();
			system("cls");
			lmain();*/
			
			
			break; // 跳出循環
		}
		else
		{
			printf("兩次輸入密碼不一致，繼續創建按Enter，退出按ESC");
			hit = getch();
			if (hit == 27)
			{
				loop = 0;
				system("cls");
				lmain();
			}

			if (hit == 13)
			{
				loop = 1;
			}
		}
	} while (loop == 1);

	fclose(fp);
	printf("創建成功，按任意鍵返回");
	getch();
	system("cls");
	lmain();
}

int match(int m, char a[20]) // 匹配資料庫中的帳號密碼
{
	FILE *fp;
	int n = 0, i = 0;
	int zhanghao;
	char password[20];

	if ((fp = fopen("login.txt", "r")) == NULL) // 不存在讀者文件
	{
		system("cls");
		printf("\n 還未存在用戶!請新建帳戶");
		getch();
		system("cls");
		lmain();
	}

	for (; !feof(fp);) // feof()函數用來檢測當前文件上的文件結束標識，判斷是否讀到了文件結尾
	{
		fscanf(fp, "%d%s", &zhanghao, password); // 寫入
		if (m == zhanghao)
		{
			if (strcmp(a, password) == 0)
				return 1;
			else
			{
				return -1;
			}
		}
	}
	return 0;
}

void login() // 帳密登錄
{
	int zhanghao;
	char password[20];
	int i = 2, j, k, n;
	char hit = 0; // 為0的字符
	system("cls");
	do
	{
		printf("\n請輸入帳號:\n");
		scanf("%d", &zhanghao);
		printf("確認輸入請按Enter，重新輸入請按ECS");
		hit = getch();					//暫停程序當i接收後繼續下一條指令
		for (; hit != 13 && hit != 27;) // Enter和ESC才能退出循環
		{
			hit = getch();
		}
	} while (hit == 27);
	printf("\n請輸入密碼:\n");
	scanf("%s", password);
	i = match(zhanghao, password);
	if (i == 1)
	{
		printf("登錄成功!按任意鍵繼續");
		getch();
		main1();
	}
	else
	{
		if (i == -1)
		{
			printf("密碼錯誤!");
			getch();
			login();
		}
		if (i == 0)
			printf("不存在此用戶");
		getch();
		system("cls");
		lmain();
	}
}

void xg(int z,char m[20])//修改函數 
{
	FILE *fp;
	int zhanghao1,n,j,k;
	char mima1[20];
	struct login *head,*p,*p1,*p2;

	fp=fopen("login.txt","r");
	    j =tjzs3();	
		
		
	    for (k=0;k<=j-1;k++)
    	{
			fscanf(fp,"%d %s",&zhanghao1,mima1);
        	if (z!=zhanghao1)//比較名字，將不同名字的信息複製到鏈表
          	{
          		
	        	n++;//相同返回值為0不執行if語句繼續循環，不同則執行直到將所有不同的資料建立成鏈表
	            if (n==1)//建立鏈表
                {
		        	p1=p2=(struct login*)malloc(LEN2);
		        	
                	head=p1;
                	p2->next = NULL;
				}
                else
			    {
			    	p1=(struct login*)malloc(LEN2);
			    	p2->next=p1;
					p2=p1;
					
                }
                
				
                
 				p1->zhanghao=zhanghao1;
                strcpy(p1->password,mima1);//複製帳號密碼 
          	}
    	}
    	
        if (n==0)
		{
			head=NULL;
		}
		else//建立鏈表的最後剩餘一個儲存空間，所以封底
		{
			//p2->next=p1;
			p1->next=NULL;
			//fclose(fp);
		}
		
   		
		fclose(fp);
		
		fp=fopen("login.txt","w");//清空文件，只寫打開，然後關閉
        fclose(fp);
        fp=fopen("login.txt","a");//追加文件
        p=head;
        for (;p!=NULL;)//把鏈表內容覆蓋到文件
   		{
   	   		fprintf(fp,"%d %s%\n",p->zhanghao,p->password);
   	   		p=p->next;
	    }
	    fprintf(fp,"%d %s\n",z,m);
        fclose(fp);
        system ("cls");

}


void xgmm()//修改密碼 
{
			FILE *fp;
        int zh=0,k=0,m=0,n=0;
        int chazhao,hit;
        char mima[20]={'\0'},password1[20]={'\0'};
        char  mm[20]={'\0'};
        char i;

        if ((fp=fopen("login.txt","r"))==NULL)//打開文件
        {
	        system ("cls");
            printf("\n紀錄文件不存在!按任意鍵返回");
  		    getch();
  		    system("cls");
		    lmain();
        }
       		system("cls");
        printf("請輸入你的帳號和舊密碼：\n");
        scanf("%d %s",&chazhao,mima);
	    m =tjzs3();
        for (n=0;n<=m;n++)
	    {
	    	fscanf(fp,"%d %s",&zh,mm);
        	if(zh==chazhao)
        	{
        		if(!strcmp(mm,mima))
        		{
        			printf("請輸入新的密碼");
        			scanf("%s",mima);
       		    	printf("再次輸入密碼:\n");
	            	scanf("%s",password1);
	             	if(strcmp(mima,password1)==0)
	   			 	{
		            	xg(chazhao,mima);
		           		getch();
				   		lmain();
	               		system("cls");
   			     	}
       			  	else
	   			  	{
	       		   	    printf("兩次輸入密碼不一致,按任意鍵退出");
	       			    hit=getch();
		   			    system("cls");
				        lmain();

   				  	}
				}
				else
				{
					printf("舊密碼錯誤，按任意鍵返回！");
					getch();
					system("cls");
					lmain();
	            
				}

        	}
      	}
	    printf("不存在此帳號，按任意鍵返回");
		fclose(fp);//修改結束
		getch();
		system("cls");
		lmain(); 
       
}

int main()
{

	lmain();
	
	

	return 0;
}
