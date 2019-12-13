#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define MAXBOOK 999999
#define LENGTH 20

typedef struct book{
	long id;                 //图书编号
    char name[LENGTH];       //图书名
    char author[LENGTH];     //图书作者
    int count;               //图书存数
    int borrow;              //借出数量
}BOOK;
typedef struct books{
	BOOK data;
    struct books *next;
}BOOKS;
BOOKS *head=NULL;

void welcome();
char land();                   // [主页面的输入判断]
char choice();                 // [功能选择的输入判断] 
void error(char *);            // [异常提醒]             
int usrmanager();              // [管理员入口]  返回值:0表示返回主页面,1表示继续执行本函数  
void printbook();              // [打印图书信息]
void addbook();                // [注册新图书]
void modbook();                // [修改现存图书信息]
void delbook();                // [注销现存图书]
int usrstudent();              // [学生入口]    返回值:0表示返回主页面,1表示继续执行本函数 
void lookupbook();             // [查找图书]
void borrowbook();             // [借阅图书]
void returnbook();             // [归还图书]
void viewbook();               // [查看已借阅情况]
void save();                   // [保存图书信息]
void load();                   // [载入图书信息]

int main(){    
    welcome();
    return 0;
}

// [主页面入口]
void welcome(){
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&欢迎使用图书管理系统&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    while(1){
		printf("\n******************************欢迎进入主页面************************************\n");
        printf("^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^~^~^~^~\n");       
        printf("\t\t\t☆  1: 管理员入口\n\t\t\t☆  2: 学生入口\n\t\t\t☆  0: 退出系统\n");
        printf("请选择:\n");
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
				printf("已退出系统，祝你学习愉快  Y(^_^)Y\n");
                exit(0);//正常退出
            default:
                break;
        }
    }
}

// [主页面的输入判断]
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
        error("非法输入!!!请选择:1/2/0");
    }
    return '\0';
}

// [功能选择的输入判断] 
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
        error("非法输入!!!请选择:1/2/3/4/0");           
    }    
    return '\0';
}

// [异常提醒] 
void error(char *s){
    fprintf(stderr, "%s\n", s);//标准错误输出到一个文件中
}

// [管理员入口]  返回值0表示返回主页面,1表示继续执行本函数
int usrmanager(){
    printf("\n****************************欢迎进管理员功能操作页面****************************\n");
	printf("^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^~^~^~^~\n"); 
    printf("\t\t\t☆  1:打印图书信息\n\t\t\t☆  2:注册新图书\n\t\t\t☆  3:修改现存图书信息\n\t\t\t☆  4:注销现存图书\n\t\t\t☆  5:保存图书信息\n\t\t\t☆  6:载入图书信息\n\t\t\t☆  0:返回主页面\n");
    printf("请选择:\n");
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

// [打印图书信息]
void printbook()
{
    BOOKS *pr=head;
	//system("cls");//清除控制台屏幕	
    printf("*********************************打印图书信息**********************************\n");
	if(pr == NULL)
	{
		printf("抱歉!图书馆没有图书!  (*_*)\n");
	}
    while(pr != NULL)
	{		 
         printf("图书编号:%ld\t图书名:%s\t图书作者:%s\t图书总存数:%d\t借出数量:%d\n",pr->data.id,pr->data.name,pr->data.author,pr->data.count,pr->data.borrow);
	     pr = pr->next;
	}
    printf("*******************************************************************************\n");
}

// [注册新图书]
void addbook()
{
	BOOKS *p = NULL;
    BOOKS *pr = head;
    p=(BOOKS *)malloc(sizeof(BOOKS));
	if(p == NULL) exit(0);
	while(head != NULL && pr->next != NULL  )
	{   //遍历到最后一个节点添加图书信息
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
            printf("非法输入(图书编号范围0~999999!!)\n");
            fflush(stdin);//刷新标准输入缓冲区
            continue;			
		}
        printf("please input name(length:0~19):\n");
		scanf("%s",pr->data.name);
		if(strlen(pr->data.name) > LENGTH){
            printf("非法输入(图书名长度0~19)!!\n");
            fflush(stdin);
            continue;
		}
     	printf("please input author(length:0~19):\n");
		scanf("%s",pr->data.author);
		if(strlen(pr->data.author) > LENGTH){
            printf("非法输入(图书作者名长度0~19)!!\n");
            fflush(stdin);
            continue;
		}
    	printf("please input count(num:0~99):\n");
	    scanf("%d",&pr->data.count);
		getchar();
	    if(!(pr->data.count >= 0 && pr->data.count <= 99)){
            printf("非法输入(每类书总存数不得超过99本!!)\n");
            fflush(stdin);
            continue;
        }
     	pr->data.borrow=0;
		if(pr->data.borrow == 0){
			printf("恭喜成功注册新图书!!\n");
			return;
		}
		free(p);
	}
}

// [修改现存图书信息]
void modbook(){
	long modid;
	int choice;
    BOOKS *pr = head;
	printf("请输入你要修改现存图书的id:\n");
  	scanf("%ld",&modid);
	if(!(modid >= 0 && modid <= 999999)){
         printf("非法输入(图书编号范围0~999999!!)\n");
         printf("系统自动为你返回上一级页面 (^@^)\n");
         return;
    }
	while(1){
		if(pr->data.id == modid){
            break;
		}
		else if(pr->next == NULL){
			printf("图书馆没有id为%d的图书!! (&!&)\n",modid);
			printf("修改失败，系统自动为你返回上一级页面 (^@^)\n");
		    return;
		}
		pr = pr->next;
	}
	printf("请选择要修改的数据项:\n1:图书名\n2:图书作者\n0:放弃修改\n");
	scanf("%d",&choice);
	switch(choice){
        case 1:
            printf("请输入新的图书名:\n");
            scanf("%s",pr->data.name);
		    if(strlen(pr->data.name) > LENGTH){
                printf("非法输入(图书名长度0~19)!!\n");
                printf("系统自动为你返回上一级页面 (^@^)\n");
                return;
			}else{
			    printf("修改成功\n");
			}
            break;
        case 2:
            printf("请输入新的图书作者:\n");
			scanf("%s",pr->data.author);
		    if(strlen(pr->data.author) > LENGTH){
                printf("非法输入(图书作者名长度0~19)!!\n");
				printf("系统自动为你返回上一级页面 (^@^)\n");
                return;
			}else{
			    printf("修改成功\n");
			}
            break;
        case 0:
			printf("放弃修改，系统自动为你返回上一级页面\n");
			return;
        default:
			printf("非法输入，系统自动为你返回上一级页面\n");
			return;
            break;
    }
}

// [注销现存图书]
void delbook(){
	long delid;
	BOOKS *pr = head,*p = head;
	if(head == NULL){
		printf("抱歉!图书馆没有图书!  (*_*)\n");
        printf("系统自动为你返回上一级页面 (^@^)\n");
        return;
	}
	printf("请输入你要注销现存图书id:");
	scanf("%ld",&delid);
	if(!(delid >= 0 && delid <= 999999)){
        printf("非法输入(图书编号范围0~999999!!)\n");
        printf("系统自动为你返回上一级页面 (^@^)\n");
		return;
    }
	while(delid != p->data.id && p->next != NULL){//未找到删除节点且未到表尾
		pr = p;
		p = p->next;
	}
	if(delid == p->data.id){
		if(p == head){//若待删节点为头节点
			head = p->next;
		}else{//若待删节点不是头节点
			pr->next = p->next;
		}
		free(p);
		printf("成功注销id为%ld的图书\n",delid);
	}else{
		printf("图书馆没有id为%ld的图书!! (&!&)\n",delid);
	}
}


int usrstudent(){
    printf("\n****************************欢迎进入学生功能操作页面****************************\n");
	printf("^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^^~^~^~^~^~^~^~^~^~^~^~\n"); 
    printf("\t\t\t☆  1:查找图书\n\t\t\t☆  2:借阅图书\n\t\t\t☆  3:归还图书\n\t\t\t☆  4:查看已借阅情况\n\t\t\t☆  5:保存图书信息\n\t\t\t☆  6:载入图书信息\n\t\t\t☆  0:返回主页\n");
	printf("请选择:\n");
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

// [查找图书]
void lookupbook()
{
	int choice;
	BOOKS *pr=head;
	char name[LENGTH],author[LENGTH];
	if(pr == NULL)
	{
		printf("抱歉!图书馆没有图书!请先让管理员注册图书!!  (*_*)\n");
        printf("查找失败，系统自动为你返回上一级页面\n");
        return;
	}
	printf("请选择查找图书方式:\n1:按图书名查找\n2:按作者名查找\n0:放弃查找\n");
	scanf("%d",&choice);
    switch(choice){
        case 1:
			printf("请输入要查找的图书名(长度0~19):\n");
			scanf("%s",name);
		    if(strlen(name) > LENGTH){
                printf("非法输入(图书名长度0~19)!!\n");
                printf("查找失败，系统自动为你返回上一级页面\n");
                return;
			}
            //system("cls");//清除控制台屏幕	
            printf("******************************打印筛选后图书信息********************************\n");
            while(pr != NULL)
			{
				if(strcmp(pr->data.name,name) == 0){
                     printf("图书编号:%ld\t图书名:%s\t图书作者:%s\t图书总存数:%d\t借出数量:%d\n",pr->data.id,pr->data.name,pr->data.author,pr->data.count,pr->data.borrow);	                
				}
			    pr = pr->next;
			}
            printf("********************************************************************************\n");
            break;
        case 2:
            printf("请输入要查找的作者名(长度0~19):\n");
			scanf("%s",author);
		    if(strlen(author) > LENGTH){
                printf("非法输入(作者名长度0~19)!!\n");
                printf("查找失败，系统自动为你返回上一级页面\n");
                return;
			}
            //system("cls");//清除控制台屏幕	
            printf("******************************打印筛选后图书信息********************************\n");
            while(pr != NULL)
			{
				if(strcmp(pr->data.author,author) == 0){
                     printf("图书编号:%ld\t图书名:%s\t图书作者:%s\t图书总存数:%d\t借出数量:%d\n",pr->data.id,pr->data.name,pr->data.author,pr->data.count,pr->data.borrow);
				}
			    pr = pr->next;
			}
            printf("********************************************************************************\n");
            break;
        case 0:
			printf("放弃修改，系统自动为你返回上一级页面\n");
            return;
        default:
			printf("非法输入，系统自动为你返回上一级页面\n");
            break;
    }
}

// [借阅图书]
void borrowbook()
{
	long id;
	int num,have;
	BOOKS *pr = head;
	if(pr == NULL)
	{
		printf("抱歉!图书馆没有图书!请先让管理员注册图书!!  (*_*)\n");
	    printf("借阅失败，系统自动为你返回上一级页面\n");
        return;
	}
	printf("请输入你想要借阅图书的id:\n");
	scanf("%ld",&id);
	if(!(id >= 0 && id <= 999999)){
         printf("非法输入(图书编号范围0~999999!!)\n");
         printf("系统自动为你返回上一级页面 (^@^)\n");
         return;
    }
	while(pr->next != NULL){
		if(pr->data.id == id){
			if(pr->data.borrow >= pr->data.count){
				printf("抱歉(~-~),该类图书已借阅完了!!\n");	
				printf("借阅失败，系统自动为你返回上一级页面\n");
                return;
			}else{
				break;
			}          
		}else{
			if(pr == NULL){
				printf("图书馆没有id为%ld的图书!! (&!&)\n",id);
			    printf("借阅失败，系统自动为你返回上一级页面\n");
                return;
			}else{
					pr = pr->next;
			}
		}
	}
	printf("请输入借阅该类图书的数量:\n");
	scanf("%d",&num);
	have = (pr->data.count)-(pr->data.borrow);
	if(num > have){
		printf("抱歉，图书馆目前该类图书仅有%d本可借\n",have);
		printf("借书失败，系统自动为你返回上一级页面\n");
		return;
	}
	pr->data.borrow += num;
	printf("恭喜借阅成功!!祝你学习愉快(^*^)\n");
}

// [归还图书]
void returnbook()
{
	long id;
	int num;
	BOOKS *pr = head;
	if(pr == NULL)
	{
		printf("抱歉!图书馆没有图书!请先让管理员注册图书!!  (*_*)\n");
		printf("归还失败，系统自动为你返回上一级页面\n");
        return;
	}
	printf("请输入你想要归还图书的id:\n");
	scanf("%ld",&id);
	if(!(id >= 0 && id <= 999999)){
         printf("非法输入(图书编号范围0~999999!!)\n");
         printf("系统自动为你返回上一级页面 (^@^)\n");
         return;
    }
	while(1){
		if(pr->data.id == id){
			if(pr->data.borrow == 0){
				printf("抱歉(~-~),该类图书你没有借阅何来归还!!\n");
				printf("归还失败，系统自动为你返回上一级页面\n");
                return;
			}else{
				break;
			}          
		}
		else if(pr->next == NULL){
			printf("图书馆没有id为%ld的图书!! (&!&)\n",id);
			printf("归还失败，系统自动为你返回上一级页面\n");
            return;
		}
		pr = pr->next;
	}
	printf("请输入归还该类图书的数量:\n");
	scanf("%d",&num);
	if(num > pr->data.borrow){
		printf("抱歉，你还书的数量超过借书的数量\n");
		printf("还书失败，系统自动为你返回上一级页面\n");
		return;
	}
	pr->data.borrow -= num;
	printf("恭喜归还成功!!祝你学习愉快(^*^)\n");
}

// [查看已借阅情况]
void viewbook()
{
	BOOKS *pr=head;
	if(pr == NULL)
	{
		printf("抱歉!图书馆没有图书!请先让管理员注册图书!!  (*_*)\n");
		printf("查看失败，系统自动为你返回上一级页面\n");
        return;
	}
	//system("cls");//清除控制台屏幕	
    printf("*******************************打印已借阅图书信息*******************************\n");
    while(pr != NULL)
	{	
		 if(pr->data.borrow > 0){
             printf("图书编号:%ld\t图书名:%s\t图书作者:%s\t图书总存数:%d\t借出数量:%d\n",pr->data.id,pr->data.name,pr->data.author,pr->data.count,pr->data.borrow);
		 }
		 pr = pr->next;
	}
    printf("*******************************************************************************\n");
}

// [保存图书信息]
void save()
{
	FILE *fp;
    BOOKS *pr = head;
	if((fp = fopen("d:\\booksystem.txt","w")) == NULL)
	{
		printf("Failure to open file!\n");
        exit(1);//错误退出
	}
    //遍历将节点写入文件
    while(pr)
	{
		fwrite(pr,sizeof(BOOKS),1,fp);
        pr=pr->next;
	}
	fclose(fp);
	printf("成功保存图书信息至路径d:\\booksystem.txt\n");
}

// [载入图书信息]
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
	printf("成功从路径d:\\booksystem.txt载入图书信息\n");
}
