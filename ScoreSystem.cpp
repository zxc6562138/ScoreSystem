#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define LEN sizeof(struct student)
#define LEN2 sizeof(struct login)

struct student // ������T
{
	char num[20], nam[20];
	char scoreA[3],scoreB[3],scoreC[3];
	
	struct student *next; // �쵲����
};

struct login // �n����T
{
	int zhanghao;
	char password[20];
	struct login *next;
};

void lmain();
void xg(int,char[] );
void login();//�n���\��t�� 
int create(int,char[] );//�Ыرb���K�X 
void xgmm(); // �ק�K�X

void main1();//�D��� 
void addScore();//�W�[���Z 
void delScore();//�R�����Z 
void browseScore();//�s�����Z 
int tjzs3()//�έp�b���K�X�Ӽ� 
{
FILE *fp;
int zhao=0,n;
char mm[20]={'\0'};

fp=fopen("login.txt","r");//���}���
for (n=0;!feof(fp);n++)//�v��Ū���
fscanf(fp,"%d %s",&zhao,mm);

n--;//��Ū���󥽧��ɡA�����w�å��W�X���A�ҥH�|�hŪ�@���C
fclose(fp);//�������
return (n);//��^�Ӽ� 
}

int tjzs()//�έp�����ƶq 
{
FILE *fp;
int txcl=0,n;
char scoreA[3]={'\0'},scoreB[3]={'\0'},scoreC[3]={'\0'};
char nam[20]={'\0'},num[20]={'\0'};
fp=fopen("Score.txt","r");//���}���
for (n=0;!feof(fp);n++)//�v��Ū���
fscanf(fp,"%s%s%s%s%s",num,nam,scoreA,scoreB,scoreC);
n--;
fclose(fp);//�������
return (n);//��^�Ӽ�
}

void mainmenu() // �D���
{
	system("cls");

	printf("**************************************************");

	printf("\n\n 1.�s�W���Z\n\n");
	
	printf("\n\n 2.�R�����Z\n\n");
	
	printf("\n\n 3.�s�����Z\n\n");

	printf("\n\n 4.�h�X�t��\n\n");

	printf("\n\n �Ы����ܡAEnter�̩w\n");

	printf("*************************************************\n");

	return;
}

void main1()
{
	
	
	char choose;
	mainmenu();
	scanf(" %c",&choose);
	switch(choose)//�\���� 
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

void addScore()//�W�[���Z 
{
	FILE*fp;
	char i;
	char scoreA[3]={'\0'},scoreB[3]={'\0'},scoreC[3]={'\0'};
	
    
    char  nam[20]={'\0'},num[20]={'\0'};
    system ("cls");

    if ((fp=fopen("Score.txt","r"))==NULL)//if�y�y�G���}���A���s�b�����h�s��
	{
    	fp=fopen("Score.txt","w");
    	fclose(fp);
    }
	fp=fopen("Score.txt","a");
	
	printf("\n�Ы��H�U�榡��J�����H��:\�Ǹ� �m�W ���A ���B ���C ");
	
	for(;i!=27;)//���F��{��J�@�����esc�h�X
	{
		printf("�п�J:\n");
		scanf("%s%s%s%s%s",num,nam,scoreA,scoreB,scoreC);
		fprintf(fp,"%-8s%-9s%-8s%-8s%-8s%\n",num,nam,scoreA,scoreB,scoreC);
	    printf("�~���J�Ы�Enter�A������J�Ы�Esc\n");
        i=getch();//�Ȱ��{�Ƿ�i�������~��U�@�ӫ��O
        for (;i!=13&&i!=27;)//�O���u��OEnter�MESC�~��h�X�`��,��J��L�r�ŵL�ΡA�Ȱ��{�ǡA��'Enter'�~��C
        i=getch();
    }

	fclose(fp);
    printf("\n�O�s���\�A�����N���^�W�@�h!");
    getch();
	main1();//��^�W�@�h 
}

void delScore()//�R�����Z 
{
		struct student *head=NULL;
        struct student *p,*p1,*p2;
        int n=0,j,k;
        char tscoreA[3]={'\0'},tscoreB[3]={'\0'},tscoreC[3]={'\0'};
        char  tnam[20]={'\0'},tnum[20]={'\0'};
	    char dnam[20]={'\0'};
	    char i;
        FILE *fp;
        if ((fp=fopen("Score.txt","r"))==NULL)//���}���
        {
	    	system ("cls");
            printf("\n������󤣦s�b!�����N���^");
            getch();
            main1();
        }

		else//��{�R�����\��
		{
	    	system ("cls");
	    	printf("\n�п�J�A�n�R��������:");
          	scanf("%s",dnam);
          	printf("\n�T�{�R���Ы�Enter�A�����Ы�Esc\n");
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
            if (strcmp(dnam,tnam))//����W�r�A�N���P�W�r���H���ƨ�����
            {
	        	n++;//�ۦP��^�Ȭ�0������if�y�y�~��`���A���P�h���檽��N�Ҧ����P����ƫإߦ����
	            if (n==1)//�إ����
                {
		        	p1=p2=(struct student*)malloc(LEN);
                	head=p1;
				}
                else
			    {
			    	p2->next=p1;
					p2=p1;
                  	p1=(struct student*)malloc(LEN);//�s�����
                }

                strcpy(p1->num,tnum);//�ƻs�Ǹ�
                strcpy(p1->nam,tnam);//�ƻs�m�W
                strcpy(p1->scoreA,tscoreA);//�ƻs���A
                strcpy(p1->scoreB,tscoreB);//�ƻs���B 
                strcpy(p1->scoreC,tscoreC);//�ƻs���C 
                 
           }
        }
        if (n==0)//�p�G�����u���@�ӥB�o�@�ӭ�n�M�n�R�����ۦP
		{
			head=NULL;
		}
		else//�إ�����̫�Ѿl�@���x�s�Ŷ��A�ҥH�ʩ�
		{
			p2->next=p1;
			p1->next=NULL;
			fclose(fp);
		}
    }

   	fp=fopen("Score.txt","w");//�M�Ť��A�M������ 
   	fclose(fp);
   	fp=fopen("Score.txt","a");//�l�[���
   	p=head;

   	for (;p!=NULL;)//������e�л\����
   	{
   	   	fprintf(fp,"%-8s%-9s%-8s%-8s%-8s\n",p->num,p->nam,p->scoreA,p->scoreB,p->scoreC);
   	   	p=p->next;
   	}
   	fclose(fp);
   	system ("cls");
   	printf("\n�R�����\ \n�����N���^�W�@�h\n");
   	getch();//��^�W�@�h 
   	main1();
}

void browseScore()//�s�����Z 
{
	FILE *fp;
	int n=0;
    int k=0,m=0;
	char tscoreA[3]={'\0'},tscoreB[3]={'\0'},tscoreC[3]={'\0'};
    char  nam[20]={'\0'},num[20]={'\0'};
  	char i;
	if ((fp=fopen("Score.txt","r"))==NULL)//���}���
    	{
	    	system ("cls");
            printf("\n�O����󤣦s�b!�����N���^");
		    getch();//��^
            main1();
	    }
	    n= tjzs();
        if (n==0)
    	{
	  		system ("cls");
      		printf("\n�L����O��!");
      	}

	    fp=fopen("Score.txt","r");//���}�uŪ���
        system ("cls");
	    printf("�Ǹ�\t�m�W\t���A\t���B\t���C\n");
  
	    for (m=0;m<n;m++)//��X�ƾ�
	    {
	    	fscanf(fp,"%s%s%s%s%s",num,nam,tscoreA,tscoreB,tscoreC);
		 	printf("%-8s%-9s%-8s%-8s%-8s\n",num,nam,tscoreA,tscoreB,tscoreC);
	 	}
		fclose(fp);
        printf("\n�����N���^\n");
        getch();
        main1();
}


void lmenu() // ��ܵn�����
{

	printf("\n\n\t    �w��ϥ�\n\n");
	printf("**********************************************");
	printf("\n\n\t\t1.�n�J\n\n");
	printf("\n\n\t\t2.�Ыرb��\n\n");
	printf("\n\n\t\t3.�ק�K�X\n\n");
	printf("\n\n\t\t4.�h�X\n\n");
	printf("\n\n\t    �Ы����ܡAEnter�̩w\n");
	printf("**********************************************");
	printf("\n-->");
	return;
}

void lmain() // �n���\����
{
	void login();
	void create();
	char choose;
	lmenu();
	
	scanf(" %c",&choose);
	
	switch (choose) // �\����
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
		exit(0); // ��ܥ��`�h�X
		system("cls");
		break;
	}
}



void create() // �s�رb��K�X
{
	FILE *fp;
	int zhanghao, loop;
	char password[20], password1[20];
	char hit = 0;
	if ((fp = fopen("login.txt", "r")) == NULL) // if�y�y�G���}���A���s�b�����h�s��
	{
		fp = fopen("login.txt", "w");
		fclose(fp);
	}
	system("cls");
	fp = fopen("login.txt", "a");
	do // ��J�⦸�K�X�̻{�A�⦸�ۦP�~���̻{
	{
		printf("\n�Ы��H�U�榡��J:\n�Ǹ� �K�X\n");
		printf("�п�J:");
		scanf("%*c%d %s", &zhanghao, password);
		printf("�A����J�K�X:\n");
		scanf("%s", password1);
		if (strcmp(password, password1) == 0)
		{
			fprintf(fp,"%d %s\n",zhanghao,password);//�g�J 

			/*printf("�Ыئ��\�A�����N���^");
			getch();
			system("cls");
			lmain();*/
			
			
			break; // ���X�`��
		}
		else
		{
			printf("�⦸��J�K�X���@�P�A�~��Ыث�Enter�A�h�X��ESC");
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
	printf("�Ыئ��\�A�����N���^");
	getch();
	system("cls");
	lmain();
}

int match(int m, char a[20]) // �ǰt��Ʈw�����b���K�X
{
	FILE *fp;
	int n = 0, i = 0;
	int zhanghao;
	char password[20];

	if ((fp = fopen("login.txt", "r")) == NULL) // ���s�bŪ�̤��
	{
		system("cls");
		printf("\n �٥��s�b�Τ�!�зs�رb��");
		getch();
		system("cls");
		lmain();
	}

	for (; !feof(fp);) // feof()��ƥΨ��˴���e���W����󵲧����ѡA�P�_�O�_Ū��F��󵲧�
	{
		fscanf(fp, "%d%s", &zhanghao, password); // �g�J
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

void login() // �b�K�n��
{
	int zhanghao;
	char password[20];
	int i = 2, j, k, n;
	char hit = 0; // ��0���r��
	system("cls");
	do
	{
		printf("\n�п�J�b��:\n");
		scanf("%d", &zhanghao);
		printf("�T�{��J�Ы�Enter�A���s��J�Ы�ECS");
		hit = getch();					//�Ȱ��{�Ƿ�i�������~��U�@�����O
		for (; hit != 13 && hit != 27;) // Enter�MESC�~��h�X�`��
		{
			hit = getch();
		}
	} while (hit == 27);
	printf("\n�п�J�K�X:\n");
	scanf("%s", password);
	i = match(zhanghao, password);
	if (i == 1)
	{
		printf("�n�����\!�����N���~��");
		getch();
		main1();
	}
	else
	{
		if (i == -1)
		{
			printf("�K�X���~!");
			getch();
			login();
		}
		if (i == 0)
			printf("���s�b���Τ�");
		getch();
		system("cls");
		lmain();
	}
}

void xg(int z,char m[20])//�ק��� 
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
        	if (z!=zhanghao1)//����W�r�A�N���P�W�r���H���ƻs�����
          	{
          		
	        	n++;//�ۦP��^�Ȭ�0������if�y�y�~��`���A���P�h���檽��N�Ҧ����P����ƫإߦ����
	            if (n==1)//�إ����
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
                strcpy(p1->password,mima1);//�ƻs�b���K�X 
          	}
    	}
    	
        if (n==0)
		{
			head=NULL;
		}
		else//�إ�����̫�Ѿl�@���x�s�Ŷ��A�ҥH�ʩ�
		{
			//p2->next=p1;
			p1->next=NULL;
			//fclose(fp);
		}
		
   		
		fclose(fp);
		
		fp=fopen("login.txt","w");//�M�Ť��A�u�g���}�A�M������
        fclose(fp);
        fp=fopen("login.txt","a");//�l�[���
        p=head;
        for (;p!=NULL;)//������e�л\����
   		{
   	   		fprintf(fp,"%d %s%\n",p->zhanghao,p->password);
   	   		p=p->next;
	    }
	    fprintf(fp,"%d %s\n",z,m);
        fclose(fp);
        system ("cls");

}


void xgmm()//�ק�K�X 
{
			FILE *fp;
        int zh=0,k=0,m=0,n=0;
        int chazhao,hit;
        char mima[20]={'\0'},password1[20]={'\0'};
        char  mm[20]={'\0'};
        char i;

        if ((fp=fopen("login.txt","r"))==NULL)//���}���
        {
	        system ("cls");
            printf("\n������󤣦s�b!�����N���^");
  		    getch();
  		    system("cls");
		    lmain();
        }
       		system("cls");
        printf("�п�J�A���b���M�±K�X�G\n");
        scanf("%d %s",&chazhao,mima);
	    m =tjzs3();
        for (n=0;n<=m;n++)
	    {
	    	fscanf(fp,"%d %s",&zh,mm);
        	if(zh==chazhao)
        	{
        		if(!strcmp(mm,mima))
        		{
        			printf("�п�J�s���K�X");
        			scanf("%s",mima);
       		    	printf("�A����J�K�X:\n");
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
	       		   	    printf("�⦸��J�K�X���@�P,�����N��h�X");
	       			    hit=getch();
		   			    system("cls");
				        lmain();

   				  	}
				}
				else
				{
					printf("�±K�X���~�A�����N���^�I");
					getch();
					system("cls");
					lmain();
	            
				}

        	}
      	}
	    printf("���s�b���b���A�����N���^");
		fclose(fp);//�קﵲ��
		getch();
		system("cls");
		lmain(); 
       
}

int main()
{

	lmain();
	
	

	return 0;
}
