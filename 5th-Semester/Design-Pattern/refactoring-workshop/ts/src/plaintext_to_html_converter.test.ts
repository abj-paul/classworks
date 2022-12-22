import { PlaintextToHtmlConverter } from './plaintext_to_html_converter'
import fs from 'fs'
jest.mock("fs")

describe("Text Converter", () => {
  let converter: PlaintextToHtmlConverter
  let mockReadFileSync: jest.Mock
  beforeEach(() => {
    converter = new PlaintextToHtmlConverter()
    mockReadFileSync = fs.readFileSync as jest.Mock
  })

  test.each([
    ["<", "&lt;"],
    [">", "&gt;"],
    ["&", "&amp;"],
    ["\n", "<br />"]
  ])('char requires conversion', (originalChar, expected) => {
    mockReadFileSync.mockReturnValue(originalChar)
    expect(converter.toHtml()).toEqual(expected)
  });

  it("no conversion", () => {
    mockReadFileSync.mockReturnValue("simple")
    expect(converter.toHtml()).toEqual("simple")
  })

  it("multiple char conversion", () => {
    mockReadFileSync.mockReturnValue("<small>\n&space")
    expect(converter.toHtml()).toEqual("&lt;small&gt;<br />&amp;space")
  })
})
