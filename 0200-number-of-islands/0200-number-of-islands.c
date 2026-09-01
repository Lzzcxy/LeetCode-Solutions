void dfs(char** grid, int row, int col, int i, int j) {
    if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    dfs(grid, row, col, i - 1, j);
    dfs(grid, row, col, i + 1, j);
    dfs(grid, row, col, i, j - 1);
    dfs(grid, row, col, i, j + 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize == 0) {
        return 0;
    }
    int row = gridSize;
    int col = gridColSize[0];
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, row, col, i, j);
            }
        }
    }   
    return count;
}