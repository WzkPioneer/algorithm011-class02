class Solution {
public:
    bool isRoot[210]={false};
    int father[210];
    int findFather(int n)
    {
        if(n==father[n]) return n;
        else 
        {
            int fa=findFather(father[n]);
            father[n]=fa;
            return fa;
        }
    }

    void Unin(int a,int b)
    {
        int fa_a=findFather(a);
        int fa_b=findFather(b);
        if(fa_a!=fa_b)
        {
            father[fa_a]=fa_b;
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int len=M.size();
        if(len==0) return 0;
        for(int i=0;i<len;i++)
        {
            father[i]=i;
        }
        for(int i=1;i<len;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(M[i][j]==1) Unin(i,j);
            }
        }
        for(int i=0;i<len;i++)
        {
            isRoot[findFather(i)]=true;        
        }
        int ans=0;
        for(int i=0;i<len;i++)
        {
            if(isRoot[i]) ans++;           
        }
        return ans;
    }
};