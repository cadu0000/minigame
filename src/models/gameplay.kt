/*
package models

class Gameplay {
    private var horizontalPosition: Int = 0
    private var verticalPosition: Int = 0
    private val board = Board()

    fun moveRight(){
        if(board.horizontal<=horizontalPosition){
            return println("movement not allowed")
        }
        horizontalPosition++
        board.showBoard(horizontalPosition, verticalPosition)
    }

    fun moveLeft(){
        if(horizontalPosition==0){
            return println("movement not allowed")
        }
        horizontalPosition--
        board.showBoard(horizontalPosition, verticalPosition)
    }

    fun moveUp(){
        if(board.vertical==0){
            return println("movement not allowed")
        }
        verticalPosition--
        board.showBoard(horizontalPosition, verticalPosition)
    }
    fun moveDown(){
        if(board.vertical<=verticalPosition) {
            return println("movement not allowed")
        }
        verticalPosition++
        board.showBoard(horizontalPosition, verticalPosition)
    }

    fun getHorizontalPosition(): Int{
        return horizontalPosition
    }
    fun getVerticalPosition(): Int{
        return verticalPosition
    }
}
*/
