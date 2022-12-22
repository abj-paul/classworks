require 'rspec'
require_relative '../lib/trivia_game'

describe 'Trivia' do
  it 'sample usage' do
    game = Game.new

    game.add("Chet")
    game.add("Pat")
    game.add("Sue")

    loop do
      game.roll(rand(1..6))

      if rand(1..10) == 7
        not_a_winner = game.wrong_answer
      else
        not_a_winner = game.was_correctly_answered
      end
      break if(not_a_winner)
    end
  end
end