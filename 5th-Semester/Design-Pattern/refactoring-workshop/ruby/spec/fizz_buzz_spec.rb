require 'rspec'
require_relative '../lib/fizz_buzz'

describe 'FizzBuzz' do
  it 'says a number' do
    expect(FizzBuzz.say(1)).to eq('1')
    expect(FizzBuzz.say(2)).to eq('2')
  end

  it 'says Fizz when is a factor of 3' do
    expect(FizzBuzz.say(3)).to eq('Fizz')
    expect(FizzBuzz.say(6)).to eq('Fizz')
  end

  it 'says Buzz when is a factor of 5' do
    expect(FizzBuzz.say(5)).to eq('Buzz')
    expect(FizzBuzz.say(10)).to eq('Buzz')
  end

  it 'says FizzBuzz when is a factor of 3 and 5' do
    expect(FizzBuzz.say(15)).to eq('FizzBuzz')
    expect(FizzBuzz.say(30)).to eq('FizzBuzz')
  end
end