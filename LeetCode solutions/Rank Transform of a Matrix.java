class Solution {
    
    public int find(int[] parent,int k)
    {
        while(k!=parent[k])
        {
            parent[k]=parent[parent[k]];
            k=parent[k];
        }
        
        return k;
    }
    
    public int[][] go(int[][] ans,List<int[]> tmp,int[] r,int[] c)
    {
        int n,m;
        n=ans.length;
        m=ans[0].length;
        int parent[] = new int[n+m];
        int size[] = new int[n+m];
        int a[] = new int[2];
        int sz=tmp.size();
        
        for(int i=0;i<(n+m);i++)
        {
            parent[i]=i;
            size[i]=0;
        }
        
        for(int i=0;i<sz;i++)
        {
            a = tmp.get(i);
            int p1 = find(parent,a[0]);
            int p2 = find(parent,a[1]+n);
            
            if(p1!=p2)
            {
                size[p1]=Math.max(size[p1],Math.max(size[p2],Math.max(r[a[0]],c[a[1]])+1));
                parent[p2]=p1;
            }
        }
        
        
        for(int i=0;i<sz;i++)
        {
            a = tmp.get(i);
            ans[a[0]][a[1]] = r[a[0]] = c[a[1]] = size[find(parent,a[0])];
        }
        
        return ans;
    }
    
    public int[][] matrixRankTransform(int[][] a) {
        
        int n,m;
        n = a.length;
        m = a[0].length;
        
        int r[] = new int[n];
        int c[] = new int[m];
        int aa[][] = new int[n*m][3];
        int ans[][] = new int[n][m];
        List<int[]> tmp = new ArrayList<>();
        
        int k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                aa[k][0] = a[i][j];
                aa[k][1]=i;
                aa[k][2]=j;
                k++;
            }
        }
        
        java.util.Arrays.sort(aa, new java.util.Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if(a[0]>b[0]) return 1;
                if(a[0]<b[0]) return -1;
                if(a[1]>b[1]) return 1;
                if(a[1]<b[1]) return -1;
                if(a[2]>b[2]) return 1;
                return -1;
        }});
        
        int last=-1;
        for(int i=0;i<n*m;i++)
        {
            int tmpp[] = new int[2];
            if(last!=aa[i][0])
            {
                ans = go(ans,tmp,r,c);
                last = aa[i][0];
                tmp.clear();
            }
            tmpp[0]=aa[i][1];
            tmpp[1]=aa[i][2];
            tmp.add(tmpp);
        }
        ans = go(ans,tmp,r,c);
        return ans;   
    }
}