#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define MAXBOOK 999999
#define LENGTH 20

typedef struct book{
	long id;                 //ͼ����
    char name[LENGTH];       //ͼ����
    char author[LENGTH];     //ͼ������
    int count;               //ͼ�����
    int borrow;              //�������
}BOOK;
typedef struct books{
	BOOK data;
    struct books *next;
}BOOKS;
BOOKS *head=NULL;

void welcome();
char land();                   // [��ҳ��������ж�]
char choice();                 // [����ѡ��������ж�] 
void error(char *);            // [�쳣����]             
int usrmanager();              // [����Ա���]  ����ֵ:0��ʾ������ҳ��,1��ʾ����ִ�б�����  
void printbook();              // [��ӡͼ����Ϣ]
void addbook();                // [ע����ͼ��]
void modbook();                // [�޸��ִ�ͼ����Ϣ]
void delbook();                // [ע���ִ�ͼ��]
int usrstudent();              // [ѧ�����]    ����ֵ:0��ʾ������ҳ��,1��ʾ����ִ�б����� 
void lookupbook();             // [����ͼ��]
void borrowbook();             // [����ͼ��]
void returnbook();             // [�黹ͼ��]
void viewbook();               // [�鿴�ѽ������]
void save();                   // [����ͼ����Ϣ]
void load();                   // [����ͼ����Ϣ]

int main(){    
    welcome();
    return 0;
}

// [��ҳ�����]
void welcome(){
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&��ӭʹ��ͼ�����ϵͳ&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    while(1){
		printf("\n******************************��ӭ������ҳ��************************************\n");
        printf("^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^~^~^~^~\n");       
        printf("\t\t\t��  1: ����Ա���\n\t\t\t��  2: ѧ�����\n\t\t\t��  0: �˳�ϵͳ\n");
        printf("��ѡ��:\n");
		printf("^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^^~^~^~^~\n");
        switch(land()){
            case '1':
                while(1){
                    if(usrmanager()){
                        continue;
                    }else{
                        break;
                    }
                 }
                break;
            case '2':
                while(1){
                    if(usrstudent()){
                        continue;
                    }else{
                        break;
                    }
                }
                break;
            case '0':
				printf("���˳�ϵͳ��ף��ѧϰ���  Y(^_^)Y\n");
                exit(0);//�����˳�
            default:
                break;
        }
    }
}

// [��ҳ��������ж�]
char land(){
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i);
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("�Ƿ�����!!!��ѡ��:1/2/0");
    }
    return '\0';
}

// [����ѡ��������ж�] 
char choice(){
    char c, flag;
    int i;   
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i);
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '3' || flag == '4' || flag == '5' || flag == '6' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("�Ƿ�����!!!��ѡ��:1/2/3/4/0");           
    }    
    return '\0';
}

// [�쳣����] 
void error(char *s){
    fprintf(stderr, "%s\n", s);//��׼���������һ���ļ���
}

// [����Ա���]  ����ֵ0��ʾ������ҳ��,1��ʾ����ִ�б�����
int usrmanager(){
    printf("\n****************************��ӭ������Ա���ܲ���ҳ��****************************\n");
	printf("^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^~^~^~^~\n"); 
    printf("\t\t\t��  1:��ӡͼ����Ϣ\n\t\t\t��  2:ע����ͼ��\n\t\t\t��  3:�޸��ִ�ͼ����Ϣ\n\t\t\t��  4:ע���ִ�ͼ��\n\t\t\t��  5:����ͼ����Ϣ\n\t\t\t��  6:����ͼ����Ϣ\n\t\t\t��  0:������ҳ��\n");
    printf("��ѡ��:\n");
    printf("^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^~^~^~^~\n"); 
    switch(choice()){
        case '1':
            printbook();
            break;
        case '2':
            addbook();
            break;
        case '3':
			modbook();
            break;
        case '4':
            delbook();
            break;
		case '5':
			save();
            break;
        case '6':
            load();
            break;
        case '0':
            return 0;
        default:
            break;
    }
    return 1;
}

// [��ӡͼ����Ϣ]
void printbook()
{
    BOOKS *pr=head;
	//system("cls");//�������̨��Ļ	
    printf("*********************************��ӡͼ����Ϣ**********************************\n");
	if(pr == NULL)
	{
		printf("��Ǹ!ͼ���û��ͼ��!  (*_*)\n");
	}
    while(pr != NULL)
	{		 
         printf("ͼ����:%ld\tͼ����:%s\tͼ������:%s\tͼ���ܴ���:%d\t�������:%d\n",pr->data.id,pr->data.name,pr->data.author,pr->data.count,pr->data.borrow);
	     pr = pr->next;
	}
    printf("*******************************************************************************\n");
}

// [ע����ͼ��]
void addbook()
{
	BOOKS *p = NULL;
    BOOKS *pr = head;
    p=(BOOKS *)malloc(sizeof(BOOKS));
	if(p == NULL) exit(0);
	while(head != NULL && pr->next != NULL  )
	{   //���������һ���ڵ����ͼ����Ϣ
	    pr = pr->next;
	}
	if (head == NULL)
	{
		head = p;
		pr = p;
		pr->next = NULL;
	}
	else
	{
		pr->next = p;
		pr = p;
		pr->next = NULL;
	}
	while(1){
	    printf("please input id(range:0~999999):\n");
	    scanf("%ld",&pr->data.id);
		getchar();
        if(!(pr->data.id >= 0 && pr->data.id <= 999999)){
            printf("�Ƿ�����(ͼ���ŷ�Χ0~999999!!)\n");
            fflush(stdin);//ˢ�±�׼���뻺����
            continue;			
		}
        printf("please input name(length:0~19):\n");
		scanf("%s",pr->data.name);
		if(strlen(pr->data.name) > LENGTH){
            printf("�Ƿ�����(ͼ��������0~19)!!\n");
            fflush(stdin);
            continue;
		}
     	printf("please input author(length:0~19):\n");
		scanf("%s",pr->data.author);
		if(strlen(pr->data.author) > LENGTH){
            printf("�Ƿ�����(ͼ������������0~19)!!\n");
            fflush(stdin);
            continue;
		}
    	printf("please input count(num:0~99):\n");
	    scanf("%d",&pr->data.count);
		getchar();
	    if(!(pr->data.count >= 0 && pr->data.count <= 99)){
            printf("�Ƿ�����(ÿ�����ܴ������ó���99��!!)\n");
            fflush(stdin);
            continue;
        }
     	pr->data.borrow=0;
		if(pr->data.borrow == 0){
			printf("��ϲ�ɹ�ע����ͼ��!!\n");
			return;
		}
		free(p);
	}
}

// [�޸��ִ�ͼ����Ϣ]
void modbook(){
	long modid;
	int choice;
    BOOKS *pr = head;
	printf("��������Ҫ�޸��ִ�ͼ���id:\n");
  	scanf("%ld",&modid);
	if(!(modid >= 0 && modid <= 999999)){
         printf("�Ƿ�����(ͼ���ŷ�Χ0~999999!!)\n");
         printf("ϵͳ�Զ�Ϊ�㷵����һ��ҳ�� (^@^)\n");
         return;
    }
	while(1){
		if(pr->data.id == modid){
            break;
		}
		else if(pr->next == NULL){
			printf("ͼ���û��idΪ%d��ͼ��!! (&!&)\n",modid);
			printf("�޸�ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ�� (^@^)\n");
		    return;
		}
		pr = pr->next;
	}
	printf("��ѡ��Ҫ�޸ĵ�������:\n1:ͼ����\n2:ͼ������\n0:�����޸�\n");
	scanf("%d",&choice);
	switch(choice){
        case 1:
            printf("�������µ�ͼ����:\n");
            scanf("%s",pr->data.name);
		    if(strlen(pr->data.name) > LENGTH){
                printf("�Ƿ�����(ͼ��������0~19)!!\n");
                printf("ϵͳ�Զ�Ϊ�㷵����һ��ҳ�� (^@^)\n");
                return;
			}else{
			    printf("�޸ĳɹ�\n");
			}
            break;
        case 2:
            printf("�������µ�ͼ������:\n");
			scanf("%s",pr->data.author);
		    if(strlen(pr->data.author) > LENGTH){
                printf("�Ƿ�����(ͼ������������0~19)!!\n");
				printf("ϵͳ�Զ�Ϊ�㷵����һ��ҳ�� (^@^)\n");
                return;
			}else{
			    printf("�޸ĳɹ�\n");
			}
            break;
        case 0:
			printf("�����޸ģ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
			return;
        default:
			printf("�Ƿ����룬ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
			return;
            break;
    }
}

// [ע���ִ�ͼ��]
void delbook(){
	long delid;
	BOOKS *pr = head,*p = head;
	if(head == NULL){
		printf("��Ǹ!ͼ���û��ͼ��!  (*_*)\n");
        printf("ϵͳ�Զ�Ϊ�㷵����һ��ҳ�� (^@^)\n");
        return;
	}
	printf("��������Ҫע���ִ�ͼ��id:");
	scanf("%ld",&delid);
	if(!(delid >= 0 && delid <= 999999)){
        printf("�Ƿ�����(ͼ���ŷ�Χ0~999999!!)\n");
        printf("ϵͳ�Զ�Ϊ�㷵����һ��ҳ�� (^@^)\n");
		return;
    }
	while(delid != p->data.id && p->next != NULL){//δ�ҵ�ɾ���ڵ���δ����β
		pr = p;
		p = p->next;
	}
	if(delid == p->data.id){
		if(p == head){//����ɾ�ڵ�Ϊͷ�ڵ�
			head = p->next;
		}else{//����ɾ�ڵ㲻��ͷ�ڵ�
			pr->next = p->next;
		}
		free(p);
		printf("�ɹ�ע��idΪ%ld��ͼ��\n",delid);
	}else{
		printf("ͼ���û��idΪ%ld��ͼ��!! (&!&)\n",delid);
	}
}


int usrstudent(){
    printf("\n****************************��ӭ����ѧ�����ܲ���ҳ��****************************\n");
	printf("^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^~^~^~^~\n"); 
    printf("\t\t\t��  1:����ͼ��\n\t\t\t��  2:����ͼ��\n\t\t\t��  3:�黹ͼ��\n\t\t\t��  4:�鿴�ѽ������\n\t\t\t��  5:����ͼ����Ϣ\n\t\t\t��  6:����ͼ����Ϣ\n\t\t\t��  0:������ҳ\n");
	printf("��ѡ��:\n");
	printf("^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^~^~^~^~\n"); 
    switch(choice()){
        case '1':
            lookupbook();
            break;
        case '2':
            borrowbook();
            break;
        case '3':
            returnbook();
            break;
		case '4':
            viewbook();
            break;
		case '5':
            save();
            break;
		case '6':
            load();
            break;
        case '0':
            return 0;
        default:
            break;
    }
    return 1;
}

// [����ͼ��]
void lookupbook()
{
	int choice;
	BOOKS *pr=head;
	char name[LENGTH],author[LENGTH];
	if(pr == NULL)
	{
		printf("��Ǹ!ͼ���û��ͼ��!�����ù���Աע��ͼ��!!  (*_*)\n");
        printf("����ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
        return;
	}
	printf("��ѡ�����ͼ�鷽ʽ:\n1:��ͼ��������\n2:������������\n0:��������\n");
	scanf("%d",&choice);
    switch(choice){
        case 1:
			printf("������Ҫ���ҵ�ͼ����(����0~19):\n");
			scanf("%s",name);
		    if(strlen(name) > LENGTH){
                printf("�Ƿ�����(ͼ��������0~19)!!\n");
                printf("����ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
                return;
			}
            //system("cls");//�������̨��Ļ	
            printf("******************************��ӡɸѡ��ͼ����Ϣ********************************\n");
            while(pr != NULL)
			{
				if(strcmp(pr->data.name,name) == 0){
                     printf("ͼ����:%ld\tͼ����:%s\tͼ������:%s\tͼ���ܴ���:%d\t�������:%d\n",pr->data.id,pr->data.name,pr->data.author,pr->data.count,pr->data.borrow);	                
				}
			    pr = pr->next;
			}
            printf("********************************************************************************\n");
            break;
        case 2:
            printf("������Ҫ���ҵ�������(����0~19):\n");
			scanf("%s",author);
		    if(strlen(author) > LENGTH){
                printf("�Ƿ�����(����������0~19)!!\n");
                printf("����ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
                return;
			}
            //system("cls");//�������̨��Ļ	
            printf("******************************��ӡɸѡ��ͼ����Ϣ********************************\n");
            while(pr != NULL)
			{
				if(strcmp(pr->data.author,author) == 0){
                     printf("ͼ����:%ld\tͼ����:%s\tͼ������:%s\tͼ���ܴ���:%d\t�������:%d\n",pr->data.id,pr->data.name,pr->data.author,pr->data.count,pr->data.borrow);
				}
			    pr = pr->next;
			}
            printf("********************************************************************************\n");
            break;
        case 0:
			printf("�����޸ģ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
            return;
        default:
			printf("�Ƿ����룬ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
            break;
    }
}

// [����ͼ��]
void borrowbook()
{
	long id;
	int num,have;
	BOOKS *pr = head;
	if(pr == NULL)
	{
		printf("��Ǹ!ͼ���û��ͼ��!�����ù���Աע��ͼ��!!  (*_*)\n");
	    printf("����ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
        return;
	}
	printf("����������Ҫ����ͼ���id:\n");
	scanf("%ld",&id);
	if(!(id >= 0 && id <= 999999)){
         printf("�Ƿ�����(ͼ���ŷ�Χ0~999999!!)\n");
         printf("ϵͳ�Զ�Ϊ�㷵����һ��ҳ�� (^@^)\n");
         return;
    }
	while(pr->next != NULL){
		if(pr->data.id == id){
			if(pr->data.borrow >= pr->data.count){
				printf("��Ǹ(~-~),����ͼ���ѽ�������!!\n");	
				printf("����ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
                return;
			}else{
				break;
			}          
		}else{
			if(pr == NULL){
				printf("ͼ���û��idΪ%ld��ͼ��!! (&!&)\n",id);
			    printf("����ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
                return;
			}else{
					pr = pr->next;
			}
		}
	}
	printf("��������ĸ���ͼ�������:\n");
	scanf("%d",&num);
	have = (pr->data.count)-(pr->data.borrow);
	if(num > have){
		printf("��Ǹ��ͼ���Ŀǰ����ͼ�����%d���ɽ�\n",have);
		printf("����ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
		return;
	}
	pr->data.borrow += num;
	printf("��ϲ���ĳɹ�!!ף��ѧϰ���(^*^)\n");
}

// [�黹ͼ��]
void returnbook()
{
	long id;
	int num;
	BOOKS *pr = head;
	if(pr == NULL)
	{
		printf("��Ǹ!ͼ���û��ͼ��!�����ù���Աע��ͼ��!!  (*_*)\n");
		printf("�黹ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
        return;
	}
	printf("����������Ҫ�黹ͼ���id:\n");
	scanf("%ld",&id);
	if(!(id >= 0 && id <= 999999)){
         printf("�Ƿ�����(ͼ���ŷ�Χ0~999999!!)\n");
         printf("ϵͳ�Զ�Ϊ�㷵����һ��ҳ�� (^@^)\n");
         return;
    }
	while(1){
		if(pr->data.id == id){
			if(pr->data.borrow == 0){
				printf("��Ǹ(~-~),����ͼ����û�н��ĺ����黹!!\n");
				printf("�黹ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
                return;
			}else{
				break;
			}          
		}
		else if(pr->next == NULL){
			printf("ͼ���û��idΪ%ld��ͼ��!! (&!&)\n",id);
			printf("�黹ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
            return;
		}
		pr = pr->next;
	}
	printf("������黹����ͼ�������:\n");
	scanf("%d",&num);
	if(num > pr->data.borrow){
		printf("��Ǹ���㻹��������������������\n");
		printf("����ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
		return;
	}
	pr->data.borrow -= num;
	printf("��ϲ�黹�ɹ�!!ף��ѧϰ���(^*^)\n");
}

// [�鿴�ѽ������]
void viewbook()
{
	BOOKS *pr=head;
	if(pr == NULL)
	{
		printf("��Ǹ!ͼ���û��ͼ��!�����ù���Աע��ͼ��!!  (*_*)\n");
		printf("�鿴ʧ�ܣ�ϵͳ�Զ�Ϊ�㷵����һ��ҳ��\n");
        return;
	}
	//system("cls");//�������̨��Ļ	
    printf("*******************************��ӡ�ѽ���ͼ����Ϣ*******************************\n");
    while(pr != NULL)
	{	
		 if(pr->data.borrow > 0){
             printf("ͼ����:%ld\tͼ����:%s\tͼ������:%s\tͼ���ܴ���:%d\t�������:%d\n",pr->data.id,pr->data.name,pr->data.author,pr->data.count,pr->data.borrow);
		 }
		 pr = pr->next;
	}
    printf("*******************************************************************************\n");
}

// [����ͼ����Ϣ]
void save()
{
	FILE *fp;
    BOOKS *pr = head;
	if((fp = fopen("d:\\booksystem.txt","w")) == NULL)
	{
		printf("Failure to open file!\n");
        exit(1);//�����˳�
	}
    //�������ڵ�д���ļ�
    while(pr)
	{
		fwrite(pr,sizeof(BOOKS),1,fp);
        pr=pr->next;
	}
	fclose(fp);
	printf("�ɹ�����ͼ����Ϣ��·��d:\\booksystem.txt\n");
}

// [����ͼ����Ϣ]
void load()
{
	FILE *fp;
    BOOKS *p;
    BOOKS *pr;
    pr=head;
	if((fp = fopen("d:\\booksystem.txt","r")) == NULL)
	{
		printf("Failure to open file!\n");
        exit(1);
	}
	while(!feof(fp))
	{
		p=(BOOKS *)malloc(sizeof(BOOKS)); 
		if(p == NULL)
		{
			printf("No enough memory!\n");
        	return;
		}
        if(fread(p,sizeof(BOOKS),1,fp) != 1){
			break;
        }else{
			if (head == NULL)
			{
				head = p;
				pr = p;
		        pr->next = NULL;
			}
        	else
			{
				pr->next = p;
	        	pr = p;
	        	pr->next = NULL;
			}
		}
	}
    fclose(fp);
	printf("�ɹ���·��d:\\booksystem.txt����ͼ����Ϣ\n");
}
