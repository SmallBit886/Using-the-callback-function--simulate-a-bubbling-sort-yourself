#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//���ûص�����ģ��ð�ݺ���
//�Լ�дһ��qsort����
//��qsort��-- �⺯�� -- ���� --quick sort����������
//��һ���������������������Ԫ�ص�ַ��
//�ڶ��������������������Ԫ�ظ�����
//�����������������������ÿ��Ԫ�ش�С����λ�ֽڣ�
//���ĸ��������Ǻ���ָ�룻�Ƚ�����Ԫ�����ú����ĵ�ַ���������ʹ�����Լ�д��
//            ����ָ��������������Ǵ��Ƚϵ�����Ԫ�صĵ�ַ
struct stu
{
	char name[20];
	int age;
};
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;//����
//	for (i = 0; i < 10; i++)
//	{
//		//һ��ð������
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
void swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
int cmp_int(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}
int cmp_str_age(const void* p1, const void* p2)
{
	return ((struct stu*)p1)->age - ((struct stu*)p2)->age;
}
#include <string.h>
int cmp_str_name(const void* p1, const void* p2)
{
	return strcmp(((struct stu*)p1)->name, ((struct stu*)p2)->name);
}

void bubble_sort(void* base, int sz,int width,int(*com)(void*e1,void*e2))
{
	int i = 0;//����
	for (i = 0; i < 10; i++)
	{
		//һ��ð������
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//����Ԫ�صıȽ�
			if (com((char*)base+j* width,(char*)base+(j+1)*width) > 0)
			{
				//����
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
void text4()
{
	int arr[10] = { 9,7,5,3,2,8,0,1,6,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz,sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);//0 1 2 3 4 5 6 7 8 9
	}
}

void text5()
{
	struct stu s[3] = {{"zhangsan",20},{"lisi",10},{"wangwu",30}};
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz,sizeof(s[0]), cmp_str_name);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s ", s[i]);//lisi wangwu zhangsan
	}
}
int main()
{
	
	text4();
	text5();
	return 0;
}