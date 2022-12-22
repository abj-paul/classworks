import Game from './trivia_game'
describe("Trivia", () => {
  let originalLog: any
  let loggedMessages: string[]

  beforeEach(() => {
    originalLog = console.log
    loggedMessages = []

    console.log = (message: string) => {
      loggedMessages.push(message)
    }
  })

  afterEach(() => {
    console.log = originalLog
  })

  it("correctly answered", function () {
    let game = new Game()
    game.add("Chet")
    game.add("Pat")
    game.roll(2)
    game.wasCorrectlyAnswered()

    expect(loggedMessages).toEqual([
      "Chet was added",
      "They are player number 1",
      "Pat was added", 
      "They are player number 2", 
      "Chet is the current player",
      "They have rolled a 2",
      "Chet's new location is 2",
      "The category is Sports",
      "Sports Question 0",
      "Answer was correct!!!!",
      "Chet now has 1 Gold Coins."])
  })

  it("wrong answer", function () {
    let game = new Game()
    game.add("Chet")
    game.add("Pat")
    game.roll(1)
    game.wrongAnswer()

    expect(loggedMessages).toEqual([
    "Chet was added", 
    "They are player number 1", 
    "Pat was added", 
    "They are player number 2",
    "Chet is the current player",
    "They have rolled a 1",
    "Chet's new location is 1",
    "The category is Science",
    "Science Question 0",
    "Question was incorrectly answered",
    "Chet was sent to the penalty box"])
  })

  xit("a sample client usage of the game", function () {
    let notAWinner = false

    let game = new Game()

    game.add("Chet")
    game.add("Pat")
    game.add("Sue")

    do {
      game.roll(Math.floor(Math.random() * 6) + 1)

      if (Math.floor(Math.random() * 10) == 7) {
        notAWinner = game.wrongAnswer()
      } else {
        notAWinner = game.wasCorrectlyAnswered()
      }
    } while (notAWinner)
  })
})
