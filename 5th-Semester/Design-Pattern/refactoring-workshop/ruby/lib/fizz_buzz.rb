class FizzBuzz
  def self.say(input)
    if input % 15 == 0
      result = 'FizzBuzz'
    else
      if input % 3 == 0
        result = 'Fizz'
      end

      if input % 5 == 0
        result = 'Buzz'
      end
    end

    return result if result
    input.to_s
  end
end
