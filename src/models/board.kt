package models

class Board constructor(
    var horizontal: Int = 2,
    var vertical: Int = 2,
    val board: Array<Array<String>> = Array(horizontal){
        Array(vertical){
            "_"
        }
    }
){
    fun chooseYourChar(char: String): Array<Array<String>> {
        board[0][0] = char
        return board
    }

    fun showBoard(horizontalPosition: Int, verticalPosition: Int){
        board[horizontalPosition][verticalPosition] = "C"
        for (row in board){
            println(row.contentToString())
        }
    }
}