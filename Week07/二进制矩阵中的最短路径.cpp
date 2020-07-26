struct Node {
    int x;
    int y;
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 0;
        queue<Node> myQ; // BFS一般通过队列方式解决
        int M = grid.size();
        int N = grid[0].size();

        // 先判断边界条件，很明显，这两种情况下都是不能到达终点的。
        if (grid[0][0] == 1 || grid[M - 1][N - 1] == 1) {
            return -1;
        }
        
        // 备忘录，记录已经走过的节点
        vector<vector<int>> mem(M, vector<int>(N, 0));
        
        myQ.push({0, 0});
        mem[0][0] = 1;

        // 以下是标准BFS的写法
        while (!myQ.empty()) {
            int size = myQ.size();

            for (int i = 0; i < size; i++) {
                Node currentNode = myQ.front();
                int x = currentNode.x;
                int y = currentNode.y;

                // 判断是否满足退出的条件
                if (x == (N - 1) && y == (M - 1)) {
                    return (ans + 1);
                }

                // 下一个节点所有可能情况
                vector<Node> nextNodes = {{x + 1, y}, {x - 1, y}, {x + 1, y - 1}, {x + 1, y + 1},
                                          {x, y + 1}, {x, y - 1}, {x - 1, y - 1}, {x - 1, y + 1}};

                for (auto& n : nextNodes) {
                    // 过滤条件1： 边界检查
                    if (n.x < 0 || n.x >= N || n.y < 0 || n.y >= M) {
                        continue;
                    }
                    // 过滤条件2：备忘录检查
                    if (mem[n.y][n.x] == 1) {
                        continue;
                    }
                    // 过滤条件3：题目中的要求
                    if (grid[n.y][n.x] == 1) {
                        continue;
                    }

                    // 通过过滤筛选，加入队列！
                    mem[n.y][n.x] = 1;
                    myQ.push(n);
                }               

                myQ.pop();
            }
            ans++;
        }

        return -1;        
    }
};
