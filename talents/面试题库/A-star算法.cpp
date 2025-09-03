#include <bits/stdc++.h>
using namespace std;

/**
 * 面试要求：
 * 实现 A* 算法，找到从起点到终点的最短路径长度。
 *
 * 约束条件：
 * 1. 只能在四个方向（上下左右）移动，代价=1。
 * 2. 启发函数 h(n) = 曼哈顿距离。
 * 3. 如果目标不可达，返回 -1。
 *
 * 可选加分：
 * - 支持对角线移动（代价 √2）。
 * - 支持不同权重格子。
 * - 启发函数可替换为欧几里得距离。
 */

struct Node {
    int x, y;          // 坐标
    int g, h;          // g: 实际代价, h: 启发式代价
    int f() const { return g + h; }
    bool operator>(const Node& other) const {
        return f() > other.f();
    }
};

/// 启发函数：曼哈顿距离
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

/**
 * @brief 使用 A* 寻路
 * @param grid 地图 (0: 空地, 1: 障碍)
 * @param start 起点 (sx, sy)
 * @param goal  终点 (gx, gy)
 * @return 最短路径长度，如果不可达返回 -1
 */
int aStarSearch(const vector<vector<int>>& grid,
                pair<int,int> start,
                pair<int,int> goal) 
{
    // TODO: 实现 A* 算法
    // 1. 定义 open list (priority_queue) 和 closed set
    // 2. 初始化起点，g=0, h=heuristic
    // 3. 循环：取出 f 最小的节点
    // 4. 如果是目标，返回 g
    // 5. 否则扩展邻居，更新 g,h 并加入 open list
    // 6. 若找不到目标，返回 -1

    return -1; // 占位
}

/// 测试函数
void runTests() {
    vector<vector<int>> grid = {
        {0,0,0,0,0},
        {1,1,0,1,0},
        {0,0,0,0,0},
        {0,1,1,1,0},
        {0,0,0,0,0}
    };

    pair<int,int> start = {0,0};
    pair<int,int> goal = {4,4};

    int result = aStarSearch(grid, start, goal);
    cout << "结果: " << result << " (期望: 8)" << endl;
}

int main() {
    runTests();
    return 0;
}
