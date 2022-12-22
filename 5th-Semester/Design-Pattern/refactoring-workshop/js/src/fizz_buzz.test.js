import say from './fizz_buzz'

describe("Fizz Buzz", () => {
  it("returns a number", () => {
    expect(say(1)).toBe("1")
    expect(say(4)).toBe("4")
    expect(say(7)).toBe("7")
  })

  it("fizz when is a factor of 3", () => {
    expect(say(3)).toBe("Fizz")
    expect(say(6)).toBe("Fizz")
    expect(say(9)).toBe("Fizz")
  })

  it("buzz when is a factor of 5", () => {
    expect(say(5)).toBe("Buzz")
    expect(say(10)).toBe("Buzz")
    expect(say(20)).toBe("Buzz")
  })

  it("fizzbuzz when is a factor of 3 and 5", () => {
    expect(say(15)).toBe("FizzBuzz")
    expect(say(30)).toBe("FizzBuzz")
  })
})
