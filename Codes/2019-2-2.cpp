#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define MaxN 10000
struct Node
{
	int value;
	Node* child[3];
	Node* parent;
	int ifVisited;
};

int g_Path[MaxN];
int g_pathIndex = 0;

struct Customer
{
	int leafValue;
	int weight;
};
Customer g_customer[MaxN];
int g_customerCnt = 0;
int g_found = 0;

bool cmp(Customer a, Customer b)
{
	return a.weight < b.weight;
}

Node* InitNode(int value)
{
	Node* node = new Node;
	node->value = value;
	node->parent = NULL;
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		node->child[i] = NULL;
	}
	return node;
}

Node* findWithValue(int value, Node* root)
{
	int i = 0;
	if (root == NULL)
		return NULL;
	if (root->value == value)
		return root;
	for (i = 0; i < 3; i++)
	{
		Node *result = findWithValue(value, root->child[i]);
		if (result != NULL)
			return result;
			 
	}
	return NULL;

}
void InitVisited(Node* root)
{
	int i = 0;
	if (root == NULL)
		return;

	root->ifVisited = 0;

	for (i = 0; i < 3; i++)
	{
		InitVisited(root->child[i]);
	}
	return;

}

int DFS_Search(Node *current, int value)
{
	g_Path[g_pathIndex++] = current->value;
	current->ifVisited = 1;
	if (current->value == value)
	{
		return 1;
		g_found = 1;
	}
		
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (current->child[i] != NULL && current->child[i]->ifVisited==0)
		{
			if (DFS_Search(current->child[i], value))
			{
				return 1;
			}
		}
	}
	if (current->parent->ifVisited == 0)
	{
		if (DFS_Search(current->parent, value))
		{
			return 1;
		}
	}
	
	if (!g_found)
	{
		g_pathIndex--;
		return 0;
	}
	else
		return 1;
}


int main()
{
	int dataLine = 0;
	scanf("%d", &dataLine);

	int i = 0;
	int childIndex = 0;
	int value;
	Node* root = NULL;

	for (i = 0; i < dataLine; i++)
	{
		scanf("%d", &value);
		Node* searchedNode = findWithValue(value, root);
		if (searchedNode == NULL)
		{
			searchedNode = InitNode(value);
			if (i == 0)
				root = searchedNode;
		}
		for (childIndex = 0; childIndex < 3; childIndex++)
		{
			scanf("%d", &value);
			if (value != -1)
			{
				searchedNode->child[childIndex] = InitNode(value);
				searchedNode->child[childIndex]->parent = searchedNode;
			}
		}
	}

	scanf("%d", &g_customerCnt);
	for (i = 0; i < g_customerCnt; i++)
	{
		scanf("%d %d", &g_customer[i].leafValue, &g_customer[i].weight);
	}

	sort(g_customer, g_customer + g_customerCnt, cmp);

	
	
	for (i = 0; i < g_customerCnt; i++)
	{
		g_found = 0;
		InitVisited(root);
		g_pathIndex = 0;
		if (i == 0)
			DFS_Search(root, g_customer[i].leafValue);
		else
		{
			Node* tmp = findWithValue(g_customer[i-1].leafValue,root);
			DFS_Search(tmp, g_customer[i].leafValue);

		}

		for (int j = 0; j < g_pathIndex; j++)
		{
			printf("%d ", g_Path[j]);
		}
		printf("\n");

	}

	system("Pause");
	return 0;
}