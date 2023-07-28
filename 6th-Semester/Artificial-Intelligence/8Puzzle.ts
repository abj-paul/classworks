f_move_up(curr_state : number[] ):void {
    empty_index = 0

    foreach((element)) index,piece in enumerate(curr_state):
        if piece == 0 :
            empty_index = index
            break

    if empty_index==0 or empty_index==1 or empty_index==2: return False

    temp = curr_state[empty_index]
    curr_state[empty_index] = curr_state[empty_index-3]
    curr_state[empty_index-3] = temp
    print(f"swapped up:{curr_state}")
    return curr_state
}

def f_move_down(curr_state):
    empty_index = 0

    for index,piece in enumerate(curr_state):
        if piece == 0 :
            empty_index = index
            break

    if empty_index==6 or empty_index==7 or empty_index==8: return False

    temp = curr_state[empty_index]
    curr_state[empty_index] = curr_state[empty_index+3]
    curr_state[empty_index+3] = temp
    print(f"swapped down:{curr_state}")
    return curr_state


def f_move_left(curr_state):
    empty_index = 0

    for index,piece in enumerate(curr_state):
        if piece == 0 :
            empty_index = index
            break

    if empty_index==0 or empty_index==3 or empty_index==6: return False

    temp = curr_state[empty_index]
    curr_state[empty_index] = curr_state[empty_index-1]
    curr_state[empty_index-1] = temp
    print(f"swapped left:{curr_state}")
    return curr_state

def f_move_right(curr_state):
    empty_index = 0

    for index,piece in enumerate(curr_state):
        if piece == 0 :
            empty_index = index
            break

    if empty_index==2 or empty_index==5 or empty_index==8: return False

    temp = curr_state[empty_index]
    curr_state[empty_index] = curr_state[empty_index+1]
    curr_state[empty_index+1] = temp
    print(f"swapped right:{curr_state}")
    return curr_state



def isGoalState(state):
    if not state: return False

    for i in range(1,len(state)):
        if state[i]<=state[i-1]:
            return False
    return True
            


def expand(state):
    print(state)
    move_up = f_move_up(state)
    move_down = f_move_down(state)
    move_left = f_move_left(state)
    move_right = f_move_right(state)

    print(f"It got: Swap Up: {move_up}")

    if isGoalState(move_up) or isGoalState(move_down) or isGoalState(move_left) or isGoalState(move_right):
        return "Reached End!"

    if move_up: expand(move_up)
    if move_down: expand(move_down)
    if move_left: expand(move_left)
    if move_right: expand(move_right)




initial_state = [ 1, 2, 3,
                  4, 0, 5,
                  6, 7, 8 ]
expand(initial_state)

