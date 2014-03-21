#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define typef int
#define typec int
const typef inff = 0x3f3f3f3f;
const typef infc = 0x3f3f3f3f;
const int E = 3010;
const int N = 1010;

struct state
{
    int x, y;
    typef f;
    typec w;

    state(int xx, int yy, typef ff, typec ww)
    {
        x = xx; y = yy; f = ff; w = ww;
    }
};

struct network
{
    int nv, ne, pnt[E], nxt[E];
    int vis[N], que[N], head[N], pv[N], pe[N];
    typef flow, cap[E];
    typec cost, dis[E], d[N];

    void addedge(int u, int v, typef c, typec w){
        pnt[ne] = v; cap[ne] = c;
        dis[ne] = +w; nxt[ne] = head[u]; head[u] = (ne++);
        pnt[ne] = u; cap[ne] = 0;
        dis[ne] = -w; nxt[ne] = head[v]; head[v] = (ne++);
    }

    int mincost(int src, int sink) {
        int i, k, f, r;
        typef mxf;
        for (flow = 0, cost = 0; ;) {
            memset(pv, -1, sizeof(pv));
            memset(vis, 0, sizeof(vis));
            for (i = 0; i < nv; ++i) d[i] = infc;
            d[src] = 0; pv[src] = src; vis[src] = 1;

            for (f = 0, r = 1, que[0] = src; r != f;) {
                i = que[f++]; vis[i] = 0;
                if (N == f) f = 0;
                for (k = head[i]; k != -1; k = nxt[k])
                    if (cap[k] && dis[k]+d[i] < d[pnt[k]])
                    {
                        d[pnt[k]] = dis[k] + d[i];
                        if (0 == vis[pnt[k]]) {
                            vis[pnt[k]] = 1;
                            que[r++] = pnt[k];
                            if (N == r) r = 0;
                        }
                        pv[pnt[k]]=i; pe[pnt[k]]=k;
                    }
            }
            if (-1 == pv[sink]) break;

            for (k = sink, mxf = inff; k != src; k = pv[k])
                if (cap[pe[k]] < mxf) mxf = cap[pe[k]];
            flow += mxf; cost += d[sink] * mxf;

            for (k = sink; k != src; k = pv[k]) {
                cap[pe[k]] -= mxf; cap[pe[k] ^ 1] += mxf;
            }
        }
        return cost;
    }

    void build(int v, int e, vector<state> &vec)
    {
        nv = v; ne = 0;
        memset(head, -1, sizeof(head));

        int x, y; typef f; typec w;
        for (int i = 0; i < e; ++i){
            x = vec[i].x;
            y = vec[i].y;
            f = vec[i].f;
            w = vec[i].w;
            addedge(x, y, f, w);
        }
    }
}g;

int main()
{
    int N, A, B, i, j, K, DA, DB;
    while (cin >> N >> A >> B && N)
    {
        vector<state> v;
        for (i = 1; i <= N; i++)
        {
            cin >> K >> DA >> DB;
            v.push_back(state(0, i, K, 0));
            v.push_back(state(i, N+1, inff, DA));
            v.push_back(state(i, N+2, inff, DB));
        }
        v.push_back(state(N+1, N+3, A, 0));
        v.push_back(state(N+2, N+3, B, 0));

        network g;
        g.build(N+4, N*3+2, v);
        g.mincost(0, N+3);
        //cout << g.flow << endl;
        cout << g.cost << endl;
    }
    return 0;
}

