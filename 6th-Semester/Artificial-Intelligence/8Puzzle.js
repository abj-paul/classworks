const SHA256 = require("crypto-js/sha256");

function hashList(list) {
  const jsonString = JSON.stringify(list);
  const hash = SHA256(jsonString).toString();
  return hash;
}

VISITED_NODES = [];



function f_move_up(curr_state) {
  let empty_index = 0;

  for (let index = 0; index < curr_state.length; index++) {
    if (curr_state[index] === 0) {
      empty_index = index;
      break;
    }
  }

  if (empty_index === 0 || empty_index === 1 || empty_index === 2) return false;

  let temp = curr_state[empty_index];
  curr_state[empty_index] = curr_state[empty_index - 3];
  curr_state[empty_index - 3] = temp;
  console.log(`swapped up: ${curr_state}`);
  return curr_state;
}

function f_move_down(curr_state) {
  let empty_index = 0;

  for (let index = 0; index < curr_state.length; index++) {
    if (curr_state[index] === 0) {
      empty_index = index;
      break;
    }
  }

  if (empty_index === 6 || empty_index === 7 || empty_index === 8) return false;

  let temp = curr_state[empty_index];
  curr_state[empty_index] = curr_state[empty_index + 3];
  curr_state[empty_index + 3] = temp;
  console.log(`swapped down: ${curr_state}`);
  return curr_state;
}

function f_move_left(curr_state) {
  let empty_index = 0;

  for (let index = 0; index < curr_state.length; index++) {
    if (curr_state[index] === 0) {
      empty_index = index;
      break;
    }
  }

  if (empty_index === 0 || empty_index === 3 || empty_index === 6) return false;

  let temp = curr_state[empty_index];
  curr_state[empty_index] = curr_state[empty_index - 1];
  curr_state[empty_index - 1] = temp;
  console.log(`swapped left: ${curr_state}`);
  return curr_state;
}

function f_move_right(curr_state) {
  let empty_index = 0;

  for (let index = 0; index < curr_state.length; index++) {
    if (curr_state[index] === 0) {
      empty_index = index;
      break;
    }
  }

  if (empty_index === 2 || empty_index === 5 || empty_index === 8) return false;

  let temp = curr_state[empty_index];
  curr_state[empty_index] = curr_state[empty_index + 1];
  curr_state[empty_index + 1] = temp;
  console.log(`swapped right: ${curr_state}`);
  return curr_state;
}

function isGoalState(state) {
  if (!state) return false;

  for (let i = 1; i < state.length; i++) {
    if (state[i] <= state[i - 1]) {
      return false;
    }
  }
  return true;
}

function isNotVisisted(state){
  
  hashOfState = hashList(state);
  return !VISITED_NODES.includes(hashOfState);
}

function expand(state) {
  VISITED_NODES.push(hashList(state));
  console.log(state);
  let move_up = f_move_up([...state]);
  let move_down = f_move_down([...state]);
  let move_left = f_move_left([...state]);
  let move_right = f_move_right([...state]);

  console.log(`It got: Swap Up: ${move_up}`);

  if (
    isGoalState(move_up) ||
    isGoalState(move_down) ||
    isGoalState(move_left) ||
    isGoalState(move_right)
  ) {
    return "Reached End!";
  }

  if (move_up && isNotVisisted(move_up)) expand(move_up);
  if (move_down && isNotVisisted(move_down)) expand(move_down);
  if (move_left && isNotVisisted(move_left)) expand(move_left);
  if (move_right && isNotVisisted(move_right)) expand(move_right);
}

let initial_state = [1, 2, 3, 4, 0, 5, 6, 7, 8];
expand(initial_state);

