class Solution {

    private int countLive(int row, int col, int[][] board) {

        int count = 0;

        if (col - 1 >= 0) {

            if (row - 1 >= 0 && board[row - 1][col - 1] >= 1)
                count++;

            if (row + 1 < board.length && board[row + 1][col - 1] >= 1)
                count++;

            if (board[row][col - 1] >= 1)
                count++;
        }

        if (col + 1 < board[0].length) {

            if (row - 1 >= 0 && board[row - 1][col + 1] >= 1)
                count++;

            if (row + 1 < board.length && board[row + 1][col + 1] >= 1)
                count++;

            if (board[row][col + 1] >= 1)
                count++;
        }

        if (row - 1 >= 0 && board[row - 1][col] >= 1)
            count++;

        if (row + 1 < board.length && board[row + 1][col] >= 1)
            count++;

        return count;
    }

    public void gameOfLife(int[][] board) {

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {

                int count = countLive(i, j, board);

                if (board[i][j] == 1) {

                    if (count != 2 && count != 3)
                        board[i][j] = 2;

                } else {

                    if (count == 3)
                        board[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {

                if (board[i][j] == 2)
                    board[i][j] = 0;

                if (board[i][j] == -1)
                    board[i][j] = 1;
            }
        }
    }
}
