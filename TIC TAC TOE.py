board = [" "] * 9

def show():
    print("\n {} | {} | {} \n---+---+---\n {} | {} | {} \n---+---+---\n {} | {} | {} \n"
          .format(*board))

def win(b, s):
    combos = [(0,1,2),(3,4,5),(6,7,8),(0,3,6),(1,4,7),(2,5,8),(0,4,8),(2,4,6)]
    return any(b[i]==b[j]==b[k]==s for i,j,k in combos)

turn = "X"
while True:
    show()
    pos = int(input(f"Player {turn}, choose (1-9): ")) - 1
    if board[pos] != " ": 
        print("Taken!"); continue
    board[pos] = turn

    if win(board, turn):
        show(); print(f"Player {turn} wins!"); break
    if " " not in board:
        show(); print("Draw!"); break

    turn = "O" if turn == "X" else "X"
