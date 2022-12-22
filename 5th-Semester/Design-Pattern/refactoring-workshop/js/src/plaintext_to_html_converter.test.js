import { PlaintextToHtmlConverter } from './plaintext_to_html_converter'
import fs from 'fs'
jest.mock("fs")

describe("Text Converter", () => {
  let converter
  beforeEach(() => {
    converter = new PlaintextToHtmlConverter()
  })

  test.each([
    ["<", "&lt;"],
    [">", "&gt;"],
    ["&", "&amp;"],
    ["\n", "<br />"]
  ])('char requires conversion', (originalChar, expected) => {
    fs.readFileSync.mockReturnValue(originalChar)
    expect(converter.toHtml()).toEqual(expected)
  });

  it("no conversion", () => {
    fs.readFileSync.mockReturnValue("simple")
    expect(converter.toHtml()).toEqual("simple")
  })

  it("multiple char conversion", () => {
    fs.readFileSync.mockReturnValue("<small>\n&space")
    expect(converter.toHtml()).toEqual("&lt;small&gt;<br />&amp;space")
  })
})
