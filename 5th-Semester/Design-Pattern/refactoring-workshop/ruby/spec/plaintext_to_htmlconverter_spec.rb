require 'rspec'
require_relative '../lib/plaintext_to_htmlconverter'

describe 'PlaintextToHtmlConverter' do
  it 'reads the actual file' do
    expect(PlaintextToHtmlConverter.new.to_html).to eq("abc<br />&lt;hello&gt;")
  end

  it 'simple word' do
    allow(IO).to receive(:read).and_return("simple")
    actual = PlaintextToHtmlConverter.new.to_html
    expect(actual).to eq("simple")
  end

  it '<' do
    allow(IO).to receive(:read).and_return("<")
    actual = PlaintextToHtmlConverter.new.to_html
    expect(actual).to eq("&lt;")
  end

  it '>' do
    allow(IO).to receive(:read).and_return(">")
    actual = PlaintextToHtmlConverter.new.to_html
    expect(actual).to eq("&gt;")
  end

  it '&' do
    allow(IO).to receive(:read).and_return("&")
    actual = PlaintextToHtmlConverter.new.to_html
    expect(actual).to eq("&amp;")
  end

  it '\n' do
    allow(IO).to receive(:read).and_return("\n")
    actual = PlaintextToHtmlConverter.new.to_html
    expect(actual).to eq("<br />")
  end

  it 'mixed encodings with word' do
    allow(IO).to receive(:read).and_return("<small>\n&space")
    actual = PlaintextToHtmlConverter.new.to_html
    expect(actual).to eq("&lt;small&gt;<br />&amp;space")
  end
end