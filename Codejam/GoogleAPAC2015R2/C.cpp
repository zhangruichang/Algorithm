


int n,k,cnt;
bool visited[10000];
int f()
{
	sort(a,a+n);
	memset(visited,0,sizeof(bool)*n);
	cnt=0,remainnum=n,pos1,pos2,pos3;
	while(1)
	{
		if(remainnum<=2)
			break;
		//target
		cnt=0;
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
			{
				if(cnt==0)
				{
					target=a[i]+k,cnt++,pos1=i;
				}
				else if(cnt==1)
				{
					if(target==a[i])
						target+=k,cnt++,pos2=i;
				}
				else if(cnt==2)
				{
					if(target==a[i])
					{
						cnt=0,remainnum-=3,visited[pos1]=1,visited[pos2]=1,visited[i]=1;
						break;
					}
				}
			}
		}
	}
	return remainnum;
}