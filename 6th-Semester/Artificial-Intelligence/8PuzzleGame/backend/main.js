
const express = require('express');
const cors = require('cors');


// Constants
const PORT = 3000;

const app = express();
const eightPuzzleGame = require("./8Puzzle.js");

// Middleware
app.use(express.json());
app.use(cors());


app.post('/api/v1/result', (req, res) => {
    console.log("Received request...");
    console.log(req.body);

    let initial_state =  JSON.parse(JSON.stringify(req.body.state));

    let lastStep = eightPuzzleGame.expand(initial_state);
    let steps = eightPuzzleGame.getPath(lastStep);
    steps.unshift([0,1,2,3,4,5,6,7,8]);
    res.status(200).send({"Steps" : steps});
});


app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});
