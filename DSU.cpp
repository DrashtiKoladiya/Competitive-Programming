struct DSU
{
        int parent[500001],size[500001];
        void init(int n)
        {
            for(int i=1;i<=n;i++)
            {
                parent[i]=i;
                size[i]=1;
            }
        }
        
        int getParent(int k)
        {
            while(k != parent[k])
            {
                parent[k]=parent[parent[k]];
                k= parent[k];
            }
            return k;
        }
        
        int getSize(int m)
        {
            return size[getParent(m)];
        }
        
        void unioon(int x,int y)
        {
            int p1= getParent(x);
            int p2= getParent(y);
            
            if(p1==p2)
            {
                return;
            }
            if(size[p1]>size[p2])
            {
                swap(p1,p2);
            }
            size[p2]+=size[p1];
            size[p1]=0;
            parent[p1]=parent[p2];
        }
    
};