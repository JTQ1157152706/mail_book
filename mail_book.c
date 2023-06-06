#include <stdio.h>
#include <string.h>
#include "mail_book.h"
#include "tools.h"

static int count = 0;	//	有效联系人
static char name[50][20] = {};
static char tel[50][12] = {};
static char sex[50] = {};

void add(void)
{
	if(50 <= count)
	{
		printf("系统正在升级,请稍候!\n");
		return;
	}

	int i = 0;
	while(sex[i]) i++;

	printf("请输入姓名、性别、电话:");
	scanf("%s %c %s",name[i],&sex[i],tel[i]);
	count++;

	msg_show("联系人添加成功!",1.5);
}

void del(void)
{
	char key[20] = {};
	printf("请输入要删除的联系人姓名:");
	scanf("%s",key);

	for(int i=0; i<50; i++)
	{
		if(sex[i])
		{
			if(0 == strcmp(key,name[i]))	
			{
				sex[i] = 0;
				count--;
				msg_show("联系人删除成功!\n",1.5);
				return;
			}
		}
	}
	msg_show("查无此人,请检查!\n",1.5);
}

void mod(void)
{
	printf("%s\n",__func__);
	
}

void find(void)
{
	char key[20] = {};
	printf("请输入要查找的关键字:");
	scanf("%s",key);

	for(int i=0; i<50; i++)
	{
		if(sex[i])
		{
			if(strstr(name[i],key) || strstr(tel[i],key))
			{
				printf("%s %s %s\n",
					name[i],'w' == sex[i]?"女":"男",tel[i]);	
			}
		}
	}
	anykey_continue();
}

void show(void)
{
	for(int i=0; i<50; i++)
	{
		if(sex[i])
		{
			printf("%s %s %s\n",
				name[i],'w' == sex[i]?"女":"男",tel[i]);	
		}
	}
	anykey_continue();
}

