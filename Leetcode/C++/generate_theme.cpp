

int f1(vector<int> v){
	int n=v.size();
	return f(v, 0, n-1);
}

int f2(vector<int> v){
	int sum=0, n=v.size();
	for(int i=1;i<n;i++){
		if(v[i]>v[i-1]) sum+=v[i]-v[i-1];
	}
	return sum;
}

#{1,4,5,3,6,7,8}

int f3(vector<int> v){
	int maxx=0, n=v.size();
	for(int mid=0;mid<n;mid++){
		maxx=max(maxx, f(v, 0, mid), f(v, mid, n-1));
	}
	return maxx;
}

int f(vector<int> v, int s, int e){
	int sx=v[s], maxx=0;
	for(int i=s+1;i<=e;i++){
		if(v[i]>sx) maxx=max(maxx, v[i]-sx);
		else sx=v[i];
	}
	return maxx;
}