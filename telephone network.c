#include <stdio.h>
#define MAX 10
#define INFINITY -9999

void dijkstra(int G[MAX][MAX],int n,int startnode,char name[MAX]);

int main()
{
	printf("\n    -----DSA PROJECT-----\n");
	printf("\nYash Gupta  -  15BCE2073\n");
	printf("\n-------------------------------------------------\n");
	printf("\nThis is the simulation of a telephone network.");
	printf("\nThe nodes are switching stations/cell towers.");
	printf("\nThe edges are transmission lines/routing paths.");
	printf("\nEdge weights are the bandwidths.");
	printf("\nWe will find the path with max. bandwidth.\n");
	printf("\n-------------------------------------------------\n");

	int G[MAX][MAX],i,j,n,u,f,g=0,h=0;
	char ch;
	printf("\nEnter the details of the network:\n");
	do
	{
		h=0;
		printf("\nEnter the no. of nodes: ");
		scanf("%d",&n);
		char name[n],c;
		printf("\nEnter the names of the nodes:\n");
		for(i=0;i<n;i++)
		{
			fflush(stdin);
			scanf("%c",&name[i]);
		}
		printf("\nEnter the adjacency matrix for the network:\n");
		for(i=0;i<n;i++)
		{
			printf("\nEnter adjacency for %c:\n",name[i]);
			for(j=0;j<n;j++)
				scanf("%d",&G[i][j]);
		}
		printf("\n\nThe adjacency matrix is:\n\n\n\t");
	  for(i=0;i<n;i++)
	    printf("%c\t",name[i]);
	  printf("\n\n");
	  for(i=0;i<n;i++)
	  {
	    printf("%c\t",name[i]);
	    for(j=0;j<n;j++)
	    {
	      printf("%d\t",G[i][j]);
	    }
	    printf("\n\n");
	  }
		do
		{
			f=0;
			printf("\nEnter the source node: ");
			do
			{
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
				{
					printf("\nInvalid node!");
					printf("\nEnter an existing source node: ");
				}

			}while(f==0);

			dijkstra(G,n,u,name);
			f=0;
			printf("Do you want to continue?(y/n) : ");
			fflush(stdin);
			scanf("%c",&ch);
			while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N')
			{
				f=1;
				printf("Please enter a valid choice!(y/n) : ");
				fflush(stdin);
				scanf("%c",&ch);
			}
			if(ch=='n'||ch=='N')
			{
				printf("-------------------------------------------------\n");
				g=1;
				break;
			}
			if(f==1)
				printf("\n");
			printf("Do you want to continue with the same network?(y/n) : ");
			fflush(stdin);
			scanf("%c",&ch);
			while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N')
			{
				printf("Please enter a valid choice!(y/n) : ");
				fflush(stdin);
				scanf("%c",&ch);
			}
			printf("-------------------------------------------------\n");
			if(ch=='n'||ch=='N')
				h=1;
		}while(g==0&&h==0);
		if(g==0)
			printf("\nEnter the details of the new network:\n");

	}while(g==0);
	getchar();
	return 0;
}

void dijkstra(int G[MAX][MAX],int n,int startnode,char name[MAX])
{
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,maxdistance,nextnode,endnode,i,j,k,x,f;
	char st[MAX],c;

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
		maxdistance=INFINITY;
		for(i=0;i<n;i++)
		{
			if(distance[i]>maxdistance&&visited[i]==0)
			{
				maxdistance=distance[i];
				nextnode=i;
			}
		}
		visited[nextnode]=1;

		for(i=0;i<n;i++)
		{
			x=0;
			if(visited[i]==1)
			{
				k=0;
				st[k++]=name[nextnode];
				j=nextnode;
				do
				{
					j=pred[j];
					st[k++]=name[j];
				}
				while(j!=startnode);
				for(j=0;j<k;j++)
				{
					if(st[j]==name[i])
					{
						x=1;
						break;
					}
				}
			}
			if(maxdistance+cost[nextnode][i]>distance[i]&&x==0)
			{
				distance[i]=maxdistance+cost[nextnode][i];
				pred[i]=nextnode;
			}
		}
		count++;
	}

	printf("\nEnter the destination node: ");
	do
	{
		f=0;
		fflush(stdin);
		scanf("%c",&c);
		for(i=0;i<n;i++)
		{
			if(name[i]==c)
			{
				endnode=i;
				if(endnode==startnode)
					f=1;
				else
					f=2;
				break;
			}
		}
		if(f==0)
		{
			printf("\nInvalid node!");
			printf("\nEnter an existing destinantion node: ");
		}
		else if(f==1)
		{
			printf("\nStarting and destination nodes cannot be same!");
			printf("\nEnter a distinct destinantion node: ");
		}
	}while(f!=2);

	k=0;
	if(distance[endnode]<=0)
		printf("\n%C cannot be reached!",name[endnode]);
	else
	{
		st[k++]=name[endnode];
		j=endnode;
		do
		{
			j=pred[j];
			st[k++]=name[j];
		}
		while(j!=startnode);
		printf("\nRoute of the call is : %c",st[k-1]);
		for(j=k-2;j>=0;j--)
			printf(" -> %c",st[j]);
		printf("\nBandwidth of the route from %c to %c = %d",name[startnode],name[endnode],distance[endnode]);
	}
	printf("\n\n-------------------------------------------------\n");
}
