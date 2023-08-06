const SHA256 = require("crypto-js/sha256");

function hashList(list) {
  const jsonString = JSON.stringify(list);
  const hash = SHA256(jsonString).toString();
  return hash;
}

VISITED_NODES = [];
const PARENT_MAP = {};


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

function isNotVisited(state){
  
  hashOfState = hashList(state);
  return !VISITED_NODES.includes(hashOfState);
}
function expand(state) {
  VISITED_NODES.push(hashList(state));
  console.log(state);

  // Queue to store states to be expanded
  let queue = [state];

  while (queue.length > 0) {
    let currentState = queue.shift();

    let move_up = f_move_up([...currentState]);
    let move_down = f_move_down([...currentState]);
    let move_left = f_move_left([...currentState]);
    let move_right = f_move_right([...currentState]);

    if (
      isGoalState(move_up) ||
      isGoalState(move_down) ||
      isGoalState(move_left) ||
      isGoalState(move_right)
    ) {
      console.log("Reached End!");
      printPath(currentState);
      return;
    }

    if (move_up && isNotVisited(move_up)) {
      VISITED_NODES.push(hashList(move_up));
      queue.push(move_up);
      PARENT_MAP[hashList(move_up)] = currentState;
    }
    if (move_down && isNotVisited(move_down)) {
      VISITED_NODES.push(hashList(move_down));
      queue.push(move_down);
      PARENT_MAP[hashList(move_down)] = currentState;
    }
    if (move_left && isNotVisited(move_left)) {
      VISITED_NODES.push(hashList(move_left));
      queue.push(move_left);
      PARENT_MAP[hashList(move_left)] = currentState;
    }
    if (move_right && isNotVisited(move_right)) {
      VISITED_NODES.push(hashList(move_right));
      queue.push(move_right);
      PARENT_MAP[hashList(move_right)] = currentState;
    }
  }
}

function printPath(state) {
  let path = [];
  let currentState = state;

  while (currentState) {
    path.push(currentState);
    currentState = PARENT_MAP[hashList(currentState)];
  }

  console.log("Path:");
  for (let i = path.length - 1; i >= 0; i--) {
    console.log(path[i]);
  }
}


let initial_state = [1, 2, 3, 4, 0, 5, 6, 7, 8];
expand(initial_state);

