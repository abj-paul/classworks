import { PlaintextToHtmlConverter } from './plaintext_to_html_converter'

describe("Text Converter integration test", () => {
  it("sample.txt", () => {
    const converter = new PlaintextToHtmlConverter()
    expect(converter.toHtml()).toEqual("abc<br />&lt;hello&gt;")
  })
})
