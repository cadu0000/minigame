import models.Board
import java.util.Scanner

fun main(args: Array<String>) {
    val horizontal: Int = Scanner(System.`in`).nextInt()
    val vertical: Int = Scanner(System.`in`).nextInt()

    val board: Board = Board(horizontal, vertical)
    var variavel = board.createBoard()
    board.showBoard(variavel)
}