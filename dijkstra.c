#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode, char name[MAX]);

int main()
{
	int G[MAX][MAX], i, j, n, u, f;
	printf("\nEnter the no. of vertices: ");
	scanf("%d",&n);
	char name[n], c;
	printf("\nEnter the names of vertices:\n");
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		scanf("%c",&name[i]);
	}
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter adjacency for %c:\n",name[i]);
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	}
	f=0;
	do
	{
		printf("\nEnter the starting node: ");
		fflush(stdin);
		scanf("%c",&c);
		for(i=0;i<n;i++)
		{
			if(name[i]==c)
			{
				u=i;
				f=1;
				break;
			}
		}
		if(f==0)
			printf("\nInvalid node!\n");
	}while(f==0);
	dijkstra(G,n,u,name);
	getchar();
	return 0;
}

void dijkstra(int G[MAX][MAX], int n, int startnode, char name[MAX])
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i,j,k;
	char st[MAX];

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
		}
	}

	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<n-1)
	{
		mindistance=INFINITY;
		for(i=0;i<n;i++)			//choosing the next node (previous step)
		{
			if(distance[i]<mindistance&&visited[i]==0)
			{
				mindistance=distance[i];
				nextnode=i;
			}
		}
		visited[nextnode]=1;

		for(i=0;i<n;i++)			//choosing whether to replace distances in i-th node or node(next step)
		{
			if(visited[i]==0)
			{
				if(mindistance+cost[nextnode][i]<distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			}
		}
		count++;
	}

	for(i=0;i<n;i++)				//printing distance of each node
	{
		if(i!=startnode)
		{
			k=0;
			if(distance[i]==INFINITY)
				printf("\n%C cannot be reached!\n", name[i]);
			else
			{
				printf("\nDistance of %c = %d", name[i], distance[i]);
				st[k++]=name[i];
				j=i;
				do
				{
					j=pred[j];
					st[k++]=name[j];
				}
				while(j!=startnode);
				printf("\nPath : %c",st[k-1]);
				for(j=k-2;j>=0;j--)
					printf(" - %c",st[j]);
				printf("\n");
			}
		}
	}
}
