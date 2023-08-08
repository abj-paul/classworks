
document.addEventListener("DOMContentLoaded", () => {
    const tiles = document.querySelectorAll(".tile");
    const emptyTile = document.querySelector(".empty-tile");
    let emptyIndex = 8;
    
    tiles.forEach((tile) => {
	tile.addEventListener("click", () => moveTile(tile));
    });
    
    function moveTile(tile) {
	const tileIndex = parseInt(tile.dataset.index);
	const rowDiff = Math.abs(Math.floor(tileIndex / 3) - Math.floor(emptyIndex / 3));
	const colDiff = Math.abs(tileIndex % 3 - emptyIndex % 3);
	
	if ((rowDiff === 1 && colDiff === 0) || (rowDiff === 0 && colDiff === 1)) {
	    swapTiles(tileIndex, emptyIndex);
	    emptyIndex = tileIndex;
	}
	
	if (checkWin()) {
	    setTimeout(() => {
		alert("Congratulations! You solved the puzzle.");
		shuffleBoard();
	    }, 200);
	}
    }
    
    function swapTiles(index1, index2) {
	[tiles[index1].innerText, tiles[index2].innerText] = [tiles[index2].innerText, tiles[index1].innerText];

	if(tiles[index1].innerText==""){
	    tiles[index1].classList.add("empty-tile");
	    tiles[index2].classList.remove("empty-tile");
	}else{
	    tiles[index2].classList.add("empty-tile");
	    tiles[index1].classList.remove("empty-tile");
	}

    }
    
    function checkWin() {
	for (let i = 0; i < tiles.length - 1; i++) {
	    if (parseInt(tiles[i].innerText) !== i + 1) {
		return false;
	    }
	}
	return true;
    }

});

function swapTile(index1, index2) {
    const tiles = document.querySelectorAll(".tile");
	[tiles[index1].innerText, tiles[index2].innerText] = [tiles[index2].innerText, tiles[index1].innerText];
    }

    
function shuffleBoard() {

    const tiles = document.querySelectorAll(".tile");
    let currentIndex = tiles.length;
    let randomIndex;
    
    while (currentIndex !== 0) {
	randomIndex = Math.floor(Math.random() * currentIndex);
	currentIndex--;
	
	swapTile(currentIndex, randomIndex);
	
	if (currentIndex === emptyIndex || randomIndex === emptyIndex) {
	    emptyIndex = currentIndex === emptyIndex ? randomIndex : currentIndex;
	}
    }
    console.log("Done shuffling");
}



function generateGameContainer(stepNumber, state){
  const gameContainer = document.createElement("div");
  gameContainer.classList.add("game-container");

  const stepHeader = document.createElement("h4");
  const stepSpan = document.createElement("span");
  stepSpan.setAttribute("id", "step");
  stepSpan.textContent = stepNumber;
  stepHeader.textContent = "Step ";
  stepHeader.appendChild(stepSpan);

  const puzzleBoard = document.createElement("div");
  puzzleBoard.classList.add("puzzle-board");
  puzzleBoard.setAttribute("id", "board");

  for (let i = 0; i < 9; i++) {
    const tile = document.createElement("div");
    tile.classList.add("solution-tile");
    //tile.textContent = i < 8 ? i + 1 : ""; // Set tile number (1 to 8), and leave the last tile empty
    if(state[i]==0) 
  	tile.classList.add("solution-empty-tile");
      tile.textContent = state[i];
    tile.setAttribute("data-index", i);
    puzzleBoard.appendChild(tile);
  }


  gameContainer.appendChild(stepHeader);
  gameContainer.appendChild(puzzleBoard);

  return gameContainer;
}




function generateSolution(){
    current_state = [];

    let tiles = Array.from(document.querySelectorAll(".tile"));


    tiles.forEach((tile)=>{
	if(!tile.innerText) current_state.push(0);
	else current_state.push(tile.innerText);
    })
    console.log("Current State:"+current_state);

    const url = "http://localhost:3000/api/v1/result";
    const data = {
	state: current_state
    };
    
    fetch(url, {
	method: "POST",
	headers: {
	    "Content-Type": "application/json",
	},
	body: JSON.stringify(data),
    })
	.then((response) => response.json())
	.then((data) => {
	    let steps = data.Steps;
	    console.log(steps);

	    for(let stepNumber=1; stepNumber<=steps.length; stepNumber++){
		const generatedGameContainer = generateGameContainer(stepNumber,steps[stepNumber-1]);
		document.getElementsByClassName("solution-section")[0].appendChild(generatedGameContainer);
	    }
	})
	.catch((error) => {
	    console.error("Error:", error);
	});
}
