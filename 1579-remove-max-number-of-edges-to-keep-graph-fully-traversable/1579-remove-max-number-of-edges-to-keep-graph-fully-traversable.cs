public class UnionFind
{
    public int[] parent, size;
    public int components;

    public UnionFind(int n)
    {
        components = n;
        parent = new int[n + 1];
        size = new int[n + 1];
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int Find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    public bool Unite(int x, int y)
    {
        int rootX = Find(x), rootY = Find(y);
        if (rootX == rootY) return false;
        if (size[rootX] < size[rootY])
        {
            int temp = rootX;
            rootX = rootY;
            rootY = temp;
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        components--;
        return true;
    }

    public bool IsConnected()
    {
        return components == 1;
    }
}
public class Solution {
    public int MaxNumEdgesToRemove(int n, int[][] edges) {
        UnionFind alice = new UnionFind(n);
        UnionFind bob = new UnionFind(n);
        int edgesRequired = 0;

        // Process type 3 edges first
        foreach (var edge in edges)
        {
            if (edge[0] == 3)
            {
                if (alice.Unite(edge[1], edge[2]) | bob.Unite(edge[1], edge[2]))
                {
                    edgesRequired++;
                }
            }
        }

        // Process type 1 and type 2 edges
        foreach (var edge in edges)
        {
            if (edge[0] == 1)
            {
                if (alice.Unite(edge[1], edge[2]))
                {
                    edgesRequired++;
                }
            }
            else if (edge[0] == 2)
            {
                if (bob.Unite(edge[1], edge[2]))
                {
                    edgesRequired++;
                }
            }
        }

        // Check if both are fully connected
        if (alice.IsConnected() && bob.IsConnected())
        {
            return edges.Length - edgesRequired;
        }

        return -1;
    }
}