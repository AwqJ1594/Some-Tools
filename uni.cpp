#include "stdio.h"
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std; 
int time_count = 114514;
struct plannet{
	int count;//科技水平 
	bool be_found,be_continued = 1,be_attacked_able = true;//文明的暴露，是否存在和可攻击性 
	short int pos[1];//只有两个坐标，懒得写第三个 
	bool cilv_destroy(plannet *cilv,int count_cilv_number/*文明号码*/);
	int cilv_if(){
		srand((unsigned int)time(NULL));
		int random_val = rand() % 1;//懒得解释 
		return random_val;
	}//简单的自行判断
	bool cilv_destroy(plannet *cilv,int count_cilv_number/*文明号码*/){
		if(cilv[count_cilv_number].be_continued == true){
			time_count--;
			return 1;//文明的”诚意“判断，不会溯源，因为我懒 
	}else {
		return 0;
	}}
	int cilv_progress/*文明在进步的过程*/(plannet *cliv,int i){
		srand((unsigned int)time(NULL));//srand中的参数就是seed，也就是随机数将会在0~(seed-1)中进行产生
		int random_pro = rand() % 2;//文明进度的随机性，应为技术爆炸 
		cliv[i].count += random_pro;//文明进度增加 
		srand((unsigned int)time(NULL));//srand中的参数就是seed，也就是随机数将会在0~(seed-1)中进行产生
		int random_val = rand() % 101;//产生0~100以内的数据
		if(cliv[i].count >= 50/*文明足够强大就会开始排查其他的文明*/){
			int count_cilv = 0;
			for(int fx = random_val;fx <= (100+random_val);fx++){
				for(int fy = (random_val = rand() % 101);fy <= (100 + random_val);fy++){
					if(cliv[count_cilv].pos[0] == fx  && cliv[count_cilv].pos[1] == fy || cliv[i].count >= cliv[count_cilv].count/*科技必须比他们高*/){
						cliv[count_cilv].be_found = true;//如果遍历成功，标记坐标 
						if(cilv_destory(cilv,count_cilv)//报错.jpg){
							cliv[i].count+3;
							cliv[count_cilv].be_continued = 0;
							cliv[i].be_found = true;
							cout << "文明对" << count_cilv << "进行清理，他们不再存在了。"<< endl;
							break;}//毁灭这个文明 
						else if(cilv_if() == false){
							cliv[i].be_attacked_able = false;cout << "这个文明被吓傻了，不再会排查宇宙" << endl;
							break;}//文明被吓傻了 
					}
				}
			}
		if(cilv_if() == true){
			cout <<"文明仍然相信宇宙中有文明，并将会再次排查。" << endl;
		}else {
			cout << "文明死了，他们进入了彻底的内耗阶段" << endl; 
			cliv[i].be_attacked_able = false;
		} 
		}
}
	
	

int main(){
	plannet cilv[114514];
	int i = 1;
	for(int i = 1;i <= 114514;i++){
		srand((unsigned int)time(NULL));
		int random_val = rand() % 31;//懒得解释 
		cout << "文明初始化中，请稍后。。。" << endl;
		cout << "初始化程度：" << i / 114514 << "%" << endl;
	}
	system("cls");
	cout <<"欢迎来到文明模拟。" << endl;
	system("pause");
	system("cls");
	while(time_count != 1){
		i++;
		for(int i = 1;i <= 114514;i++){
			cout << "这是第" << i << "个文明，他们的科技水平为：" << cilv[i].count << endl;
			cout << "文明水平将在这个话以后加上一或二" << endl;
			cout << "文明将会进入扫描阶段（如果不满50的水平会跳过）" << endl;
			system("pause"); 
			cilv[i].cilv_progress(&cilv,i);//优化方法：实现多线程
		}
	}
	system("cls");
	cout << "文明们死了，只剩下宇宙中单一的，孤独的文明，而他，也会因为黑暗森林，而继续保持沉默..." << endl;
	system("pause");
	return 0;
}
