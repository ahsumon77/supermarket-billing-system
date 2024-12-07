#include <bits/stdc++.h>
using namespace std;
#define N 3

struct Node {
    Node* parent;
    int mat[N][N];
    int x, y, cost, level;
};

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

Node* newNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node* parent) {
    Node* node = new Node;
    memcpy(node->mat, mat, sizeof node->mat);
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->x = newX;
    node->y = newY;
    node->cost = INT_MAX;
    node->level = level;
    node->parent = parent;
    return node;
}

int calculateCost(int initial[N][N], int final[N][N]) {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                count++;
    return count;
}

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void printPath(Node* root) {
    if (root == nullptr)
        return;
    printPath(root->parent);
    printMatrix(root->mat);
}

struct comp {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};

void solve(int initial[N][N], int x, int y, int final[N][N]) {
    priority_queue<Node*, vector<Node*>, comp> pq;
    Node* root = newNode(initial, x, y, x, y, 0, nullptr);
    root->cost = calculateCost(initial, final);
    pq.push(root);

    int row[] = { 1, 0, -1, 0 };
    int col[] = { 0, -1, 0, 1 };

    while (!pq.empty()) {
        Node* min = pq.top();
        pq.pop();
        if (min->cost == 0) {
            printPath(min);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = min->x + row[i];
            int newY = min->y + col[i];
            if (isSafe(newX, newY)) {
                Node* child = newNode(min->mat, min->x, min->y, newX, newY, min->level + 1, min);
                child->cost = calculateCost(child->mat, final);
                pq.push(child);
            }
        }
    }
}

int main() {
    int initial[N][N] = {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    int final[N][N] = {
        {1, 2, 3},
        {5, 8, 6},
        {0, 7, 4}
    };

    int x = 1, y = 2;

    solve(initial, x, y, final);

    return 0;
}

