int dfs(int** grid, int row, int col, int i, int j) {
    if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) {
        return 0;
    }
    grid[i][j] = 0;
    int area = 1;
    area += dfs(grid, row, col, i - 1, j);
    area += dfs(grid, row, col, i + 1, j);
    area += dfs(grid, row, col, i, j - 1);
    area += dfs(grid, row, col, i, j + 1);  
    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize == 0) {
        return 0;
    }    
    int row = gridSize;
    int col = gridColSize[0];
    int max_area = 0;   
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                int current_area = dfs(grid, row, col, i, j);
                if (current_area > max_area) {
                    max_area = current_area;
                }
            }
        }
    }    
    return max_area;
}