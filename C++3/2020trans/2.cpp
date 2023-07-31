#include <iostream>
#include <vector>
#include <algorithm>

int findNumberTowerLength(const std::vector<std::vector<int>>& tower) {
    int rows = tower.size();
    if (rows == 0) {
        return 0;
    }

    std::vector<std::vector<int>> memo(rows, std::vector<int>(rows, -1));
   
    std::function<int(int, int)> calculateLength = [&](int row, int col) -> int {
        if (row == rows - 1) {
            return tower[row][col];
        }

        if (memo[row][col] != -1) {
            return memo[row][col];
        }

        int leftSum = calculateLength(row + 1, col);
        int rightSum = calculateLength(row + 1, col + 1);
        memo[row][col] = std::max(leftSum, rightSum) + tower[row][col];
        return memo[row][col];
    };

    return calculateLength(0, 0);
}

int main() {
    std::vector<std::vector<int>> tower = {
        {3},
        {7, 4},
        {2, 4, 6},
        {8, 5, 9, 3}
    };

    int length = findNumberTowerLength(tower);
    std::cout << "The length of the number tower is: " << length << std::endl;

    return 0;
}
