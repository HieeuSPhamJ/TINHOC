import lichess.api
from lichess.format import PYCHESS
import chess
import chess.svg
    
board = chess.Board()


from flask import Flask, render_template

app = Flask(__name__)


@app.route('/')
def hello_world():
   img = chess.svg.board(board)

   return render_template('index.html', img=img)


if __name__ == '__main__':
   app.run()