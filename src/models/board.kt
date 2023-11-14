package models

class Board constructor(
    var horizontal: Int = 2,
    var vertical: Int = 2,
){

    fun createBoard(): Array<Array<String>> {
        var board: Array<Array<String>> = Array(horizontal){Array(vertical){""} }
        for (i in 0 until horizontal) {
            for (j in 0 until vertical) {
                board[i][j] = "_"
            }
        }
        return board
    }

    fun showBoard(board: Array<Array<String>>){
        //board[movements.getHorizontalPosition()][movements.getVerticalPosition()] = char
        val array: Array<Array<String>> = board
        for (row in board){
            println(row.contentToString())
        }
    }
}