﻿//// DAG图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//#include "CAlgrorithm_DAG.h"
//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//#ifndef GRAPH_H
//#define GRAPH_H
//
//#include <list>
//#include <iostream>
//#include <vector>
//#include <stdlib.h>
//#include <string.h>
//#include <algorithm>
//#include <iterator>
//#include <stdio.h>
//#include <errno.h>
////#include <unistd.h>
//#include <signal.h>
//
//using namespace std;
//
//#define MAX_VERTEX_NUM 600
//
////图节点信息
//typedef struct Node {
//	int edge_num;//边号 
//	int src;//源点 
//	int vertex;//自身 
//	int weight;//边的权重 
//}Node;
//
///*******************************************************
//*  类名称： 邻接表图
//********************************************************/
//class Graph {
//private:
//	int edge_num;//图边的个数
//	int vertex_num;//图的顶点数目
//	list<Node> * graph_list;//邻接表
//public:
//	Graph() {}
//	Graph(char* graph[], int edgenum);
//	~Graph();
//	void print();//以邻接表的形式打印图信息
//private:
//	vector<int> get_graph_value(char* graph[], int columns);//获得每条边的数据
//	void addEdge(char* graph[], int columns);
//};
//
//
///*************************************************
//函数名称：print
//功能描述：将图的信息以邻接表的形式输出到标准输出
//参数列表：无
//返回结果：无
//*************************************************/
//void Graph::print()
//{
//	cout << "******************************************************************" << endl;
//	//for(int i = 0 ; i < MAX_VERTEX_NUM; ++i){
//	for (int i = 0; i < vertex_num; ++i) {
//		if (graph_list[i].begin() != graph_list[i].end()) {
//			cout << i << "-->";
//			for (list<Node>::iterator it = graph_list[i].begin(); it != graph_list[i].end(); ++it) {
//				cout << (*it).vertex << "(边号:" << (*it).edge_num << ",权重:" << (*it).weight << ")-->";
//			}
//			cout << "NULL" << endl;
//		}
//	}
//
//	cout << "******************************************************************" << endl;
//}
//
///*************************************************
//函数名称：get_graph_value
//功能描述：将图的每一条边的信息保存到一个数组中
//参数列表: graph：指向图信息的二维数组
//		  columns:图的第几条边
//返回结果：无
//*************************************************/
//vector<int> Graph::get_graph_value(char* graph[], int columns)
//{
//	vector<int> v;
//	char buff[20];
//	int i = 0, j = 0, val;
//	memset(buff, 0, 20);
//
//	while ((graph[columns][i] != '\n') && (graph[columns][i] != '\0')) {
//		if (graph[columns][i] != ',') {
//			buff[j] = graph[columns][i];
//			j++;
//		}
//		else {
//			j = 0;
//			val = atoi(buff);
//			v.push_back(val);
//			memset(buff, 0, 20);
//		}
//		i++;
//	}
//	val = atoi(buff);
//	v.push_back(val);
//
//	return v;
//}
//
//
//
///*************************************************
//函数名称：addEdge
//功能描述：将图的每一条边的信息加入图的邻接表中
//参数列表：graph：指向图信息的二维数组
//		  columns:图的第几条边
//返回结果：无
//*************************************************/
//void Graph::addEdge(char* graph[], int columns)
//{
//	Node node;
//	vector<int> v = get_graph_value(graph, columns);
//
//	node.edge_num = v[0];
//	node.src = v[1];
//	node.vertex = v[2];
//	node.weight = v[3];
//
//	if (node.vertex > vertex_num)
//		vertex_num = node.vertex;
//
//	//要考虑重复的边，但是边的权重不一样
//	for (list<Node>::iterator it = graph_list[node.src].begin(); it != graph_list[node.src].end(); ++it) {
//		if ((*it).vertex == node.vertex) {
//			if ((*it).weight > node.weight) {
//				(*it).weight = node.weight;
//			}
//			return;
//		}
//	}
//	graph_list[node.src].push_back(node);
//}
//
//
///*************************************************
//函数名称：构造函数
//功能描述：以邻接表的形式保存图的信息,并保存必须经过的顶点
//参数列表：graph：指向图信息的二维数组
//		  edgenum:图的边的个数
//返回结果：无
//*************************************************/
//Graph::Graph(char* graph[], int edgenum)
//{
//	edge_num = edgenum;
//	vertex_num = 0;
//	graph_list = new list<Node>[MAX_VERTEX_NUM + 1];
//
//	for (int i = 0; i < edgenum; ++i) {
//		addEdge(graph, i);
//	}
//
//	vertex_num++;
//}
//
//
///*************************************************
//函数名称：析构函数
//功能描述：释放动态分配的内存
//参数列表：无
//返回结果：无
//*************************************************/
//Graph::~Graph()
//{
//	delete[] graph_list;
//}
//
//#endif
//
////0, 0, 1, 1
////1, 0, 2, 2
////2, 0, 3, 1
//
////int main()
////{
////    std::cout << "Hello World!\n";
////}
//
//// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
//// 调试程序: F5 或调试 >“开始调试”菜单
//
//// 入门使用技巧: 
////   1. 使用解决方案资源管理器窗口添加/管理文件
////   2. 使用团队资源管理器窗口连接到源代码管理
////   3. 使用输出窗口查看生成输出和其他消息
////   4. 使用错误列表窗口查看错误
////   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
////   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
