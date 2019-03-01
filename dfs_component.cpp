/*使用深度优先搜索找出图中的所有连通分量
方法int count（） 表示图中有几个连通分量
方法id(int v)     表示顶点v在第几个连通分量中
方法boolean connect(int v,int w)  表示两个顶点是否连通

数组int id[]的大小是图的顶点数G.V(),表示这个顶点所在连通分量的id;也就是所谓的标识符，范围是（0 ~ count - 1）
*/

public class CC
{
    private boolean[] marked;
    private int[] id;
    private int count;
    
    public CC(Graph G)           //图的预处理构造函数         
    {
        marked = new boolean[G.V()];
        id = new int[G.V()];   
        for(int s=0;s<G.V();s++)   //要求对每一个顶点都进行dfs,
            if(!marked[s])     //dfs时会不断深入mark和订单s连通顶点，一但遇到没有s连通的点，那么就知道他们属于不同的连通分量里
            {
                dfs(G,s);
                count++;
            }    
    }
    
    public void dfs(Graph G,int s)   
    {
        marked[s] = true;
        id[s] = count;       //和最初版的dfs相比，就多了这一句，表示顶点s所在的id，即该顶点在哪个连通分量里面
        for(int w: G.adj(s))
            if(!marked[s])    
                dfs(G,s);
                count++;
    }
    
    public boolean connected(int v,int w)   //用于坚定两个顶点是否联通
    {return id[v]==id[w];}
    
    public int id(int v)         //给出顶点索引，就知道它所在的连通分量的id,真的很强大，很有实际用处！！
    {    return id[v];}
    
    public int count()
    {return count;}
}