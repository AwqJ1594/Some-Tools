#include "stdio.h"
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std; 
int time_count = 114514;
struct plannet{
	int count;//�Ƽ�ˮƽ 
	bool be_found,be_continued = 1,be_attacked_able = true;//�����ı�¶���Ƿ���ںͿɹ����� 
	short int pos[1];//ֻ���������꣬����д������ 
	bool cilv_destroy(plannet *cilv,int count_cilv_number/*��������*/);
	int cilv_if(){
		srand((unsigned int)time(NULL));
		int random_val = rand() % 1;//���ý��� 
		return random_val;
	}//�򵥵������ж�
	bool cilv_destroy(plannet *cilv,int count_cilv_number/*��������*/){
		if(cilv[count_cilv_number].be_continued == true){
			time_count--;
			return 1;//�����ġ����⡰�жϣ�������Դ����Ϊ���� 
	}else {
		return 0;
	}}
	int cilv_progress/*�����ڽ����Ĺ���*/(plannet *cliv,int i){
		srand((unsigned int)time(NULL));//srand�еĲ�������seed��Ҳ���������������0~(seed-1)�н��в���
		int random_pro = rand() % 2;//�������ȵ�����ԣ�ӦΪ������ը 
		cliv[i].count += random_pro;//������������ 
		srand((unsigned int)time(NULL));//srand�еĲ�������seed��Ҳ���������������0~(seed-1)�н��в���
		int random_val = rand() % 101;//����0~100���ڵ�����
		if(cliv[i].count >= 50/*�����㹻ǿ��ͻῪʼ�Ų�����������*/){
			int count_cilv = 0;
			for(int fx = random_val;fx <= (100+random_val);fx++){
				for(int fy = (random_val = rand() % 101);fy <= (100 + random_val);fy++){
					if(cliv[count_cilv].pos[0] == fx  && cliv[count_cilv].pos[1] == fy || cliv[i].count >= cliv[count_cilv].count/*�Ƽ���������Ǹ�*/){
						cliv[count_cilv].be_found = true;//��������ɹ���������� 
						if(cilv_destory(cilv,count_cilv)//����.jpg){
							cliv[i].count+3;
							cliv[count_cilv].be_continued = 0;
							cliv[i].be_found = true;
							cout << "������" << count_cilv << "�����������ǲ��ٴ����ˡ�"<< endl;
							break;}//����������� 
						else if(cilv_if() == false){
							cliv[i].be_attacked_able = false;cout << "�����������ɵ�ˣ����ٻ��Ų�����" << endl;
							break;}//��������ɵ�� 
					}
				}
			}
		if(cilv_if() == true){
			cout <<"������Ȼ�������������������������ٴ��Ų顣" << endl;
		}else {
			cout << "�������ˣ����ǽ����˳��׵��ںĽ׶�" << endl; 
			cliv[i].be_attacked_able = false;
		} 
		}
}
	
	

int main(){
	plannet cilv[114514];
	int i = 1;
	for(int i = 1;i <= 114514;i++){
		srand((unsigned int)time(NULL));
		int random_val = rand() % 31;//���ý��� 
		cout << "������ʼ���У����Ժ󡣡���" << endl;
		cout << "��ʼ���̶ȣ�" << i / 114514 << "%" << endl;
	}
	system("cls");
	cout <<"��ӭ��������ģ�⡣" << endl;
	system("pause");
	system("cls");
	while(time_count != 1){
		i++;
		for(int i = 1;i <= 114514;i++){
			cout << "���ǵ�" << i << "�����������ǵĿƼ�ˮƽΪ��" << cilv[i].count << endl;
			cout << "����ˮƽ����������Ժ����һ���" << endl;
			cout << "�����������ɨ��׶Σ��������50��ˮƽ��������" << endl;
			system("pause"); 
			cilv[i].cilv_progress(&cilv,i);//�Ż�������ʵ�ֶ��߳�
		}
	}
	system("cls");
	cout << "���������ˣ�ֻʣ�������е�һ�ģ��¶���������������Ҳ����Ϊ�ڰ�ɭ�֣����������ֳ�Ĭ..." << endl;
	system("pause");
	return 0;
}
