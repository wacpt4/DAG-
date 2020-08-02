#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <errno.h>
//#include <unistd.h>
#include <signal.h>

using namespace std;

#define MAX_VERTEX_NUM 600

//����ÿ��������Ϣ�����ݽṹ
struct GraphNode {
	int vertex;//��ǰ����ı��
	int inDegree;//��ǰ��������
	int topNum;//��ǰ��������������˳����
};

//ͼ�ڵ���Ϣ
typedef struct Node {
	int edge_num;//�ߺ� 
	int src;//Դ�� 
	int vertex;//���� 
	int weight;//�ߵ�Ȩ�� 
}Node;

/*******************************************************
*  �����ƣ� �ڽӱ�ͼ
********************************************************/
class Graph {
private:
	int edge_num;//ͼ�ߵĸ���
	int vertex_num;//ͼ�Ķ�����Ŀ
	list<Node> * graph_list;//�ڽӱ�
	vector<GraphNode> nodeArr;//����ÿ��������Ϣ������

public:
	Graph() {}
	Graph(char* graph[], int edgenum);
	~Graph();
	void print();
	vector<int> topoSort();//��������
private:
	vector<int> get_graph_value(char* graph[], int columns);
	void addEdge(char* graph[], int columns);
};


/*************************************************
*  �������ƣ�topoSort()
*  ������������ͼ�еĶ��������������
*  �����б���
*  ���ؽ�������ض�����������֮��Ľ��
*************************************************/
vector<int> Graph::topoSort()
{
	vector<int> topoSortArr;

	for (int count = 0; count < vertex_num; ++count) {
		//�ҵ�һ�����Ϊ0�Ķ���
		int i;
		for (i = 0; i < vertex_num; ++i) {
			if ((nodeArr[i].inDegree == 0) && (nodeArr[i].vertex != -1))
				break;
		}

		if (i == vertex_num)
			break;

		//��ʱ����i�����Ϊ0
		//ɾ���õ��ɾ����õ����ڵı�
		//�����붥��i�����Ķ������ȼ�1
		nodeArr[i].inDegree = -1;
		for (list<Node>::iterator it = graph_list[i].begin(); it != graph_list[i].end(); ++it) {
			nodeArr[(*it).vertex].inDegree--;
		}

		topoSortArr.push_back(i);
	}

	return topoSortArr;
}

/*************************************************
*  �������ƣ�print
*  ������������ͼ����Ϣ���ڽӱ����ʽ�������׼���
*  �����б���
*  ���ؽ������
*************************************************/
void Graph::print()
{
	cout << "******************************************************************" << endl;
	//for(int i = 0 ; i < MAX_VERTEX_NUM; ++i){
	for (int i = 0; i < vertex_num; ++i) {
		if (graph_list[i].begin() != graph_list[i].end()) {
			cout << i << "-->";
			for (list<Node>::iterator it = graph_list[i].begin(); it != graph_list[i].end(); ++it) {
				cout << (*it).vertex << "(�ߺ�:" << (*it).edge_num << ",Ȩ��:" << (*it).weight << ")-->";
			}
			cout << "NULL" << endl;
		}
	}

	cout << "******************************************************************" << endl;
}

/*************************************************
*  �������ƣ�get_graph_value
*  ������������ͼ��ÿһ���ߵ���Ϣ���浽һ��������
*  �����б�: graph��ָ��ͼ��Ϣ�Ķ�ά����
			 columns:ͼ�ĵڼ�����
*  ���ؽ������
*************************************************/
vector<int> Graph::get_graph_value(char* graph[], int columns)
{
	vector<int> v;
	char buff[20];
	int i = 0, j = 0, val;
	memset(buff, 0, 20);

	while ((graph[columns][i] != '\n') && (graph[columns][i] != '\0')) {
		if (graph[columns][i] != ',') {
			buff[j] = graph[columns][i];
			j++;
		}
		else {
			j = 0;
			val = atoi(buff);
			v.push_back(val);
			memset(buff, 0, 20);
		}
		i++;
	}
	val = atoi(buff);
	v.push_back(val);

	return v;
}



/*************************************************
*  �������ƣ�addEdge
*  ������������ͼ��ÿһ���ߵ���Ϣ����ͼ���ڽӱ���
*  �����б�graph��ָ��ͼ��Ϣ�Ķ�ά����
			 columns:ͼ�ĵڼ�����
*  ���ؽ������
*************************************************/
void Graph::addEdge(char* graph[], int columns)
{
	Node node;
	vector<int> v = get_graph_value(graph, columns);

	node.edge_num = v[0];
	node.src = v[1];
	node.vertex = v[2];
	node.weight = v[3];


	//���ݶ���ı�ţ�����ܵĶ�����Ŀ
	if (node.vertex > vertex_num)
		vertex_num = node.vertex;

	//Ҫ�����ظ��ıߣ����Ǳߵ�Ȩ�ز�һ��
	for (list<Node>::iterator it = graph_list[node.src].begin(); it != graph_list[node.src].end(); ++it) {
		if ((*it).vertex == node.vertex) {
			if ((*it).weight > node.weight) {
				(*it).weight = node.weight;
			}
			return;
		}
	}

	//����Ϣд�뵽����ÿ�������������
	nodeArr[node.src].vertex = node.src;
	nodeArr[node.vertex].vertex = node.vertex;
	nodeArr[node.vertex].inDegree++;//��ȼ�1 

	graph_list[node.src].push_back(node);
}


/*************************************************
*  �������ƣ����캯��
*  �������������ڽӱ����ʽ����ͼ����Ϣ,��������뾭���Ķ���
*  �����б�graph��ָ��ͼ��Ϣ�Ķ�ά����
			 edgenum:ͼ�ıߵĸ���
*  ���ؽ������
*************************************************/
Graph::Graph(char* graph[], int edgenum) :nodeArr(MAX_VERTEX_NUM)
{
	edge_num = edgenum;
	vertex_num = 0;
	graph_list = new list<Node>[MAX_VERTEX_NUM + 1];

	//�Ա��涥����Ϣ��������г�ʼ�������vertext=-1��ʾû�иö���
	for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
		nodeArr[i].vertex = -1;
		nodeArr[i].inDegree = 0;
		nodeArr[i].topNum = -1;
	}

	for (int i = 0; i < edgenum; ++i) {
		addEdge(graph, i);
	}

	vertex_num++;
}


/*************************************************
*  �������ƣ���������
*  �����������ͷŶ�̬������ڴ�
*  �����б���
*  ���ؽ������
*************************************************/
Graph::~Graph()
{
	delete[] graph_list;
}

#endif