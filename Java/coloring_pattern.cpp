  bool isSafe(int curnode,int curcol,int n,bool graph[101][101],vector<int>& col)
    {
        for(int i=0;i<n;i++)
        {
            if(graph[curnode][i] && col[i]==curcol) //If any neighbour has same color, returns false
            return false;
        }
        return true;
    }
    
    bool f(bool graph[101][101],vector<int>& col,int i,int& m,int& n)
    {
        if(i==n)
            return true;
        for(int j=1;j<=m;j++)
        {
            col[i]=j;   //Assign some color to ith node
            if(isSafe(i,j,n,graph,col))  //Check if it doesn't violate given condition
            {
                if(f(graph,col,i+1,m,n))    //If all nodes are colored it will return true
                return true;
            }
        }
        col[i]=0;   //Uncoloring the already colored node
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> col(n);
        return f(graph,col,0,m,n);
    }
