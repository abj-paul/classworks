// Adapted from https://github.com/emilybache/Racing-Car-Katas
import fs from 'fs'
import path from 'path'

class PlaintextToHtmlConverter {
    toHtml() {
        const text = fs.readFileSync(path.join(__dirname, 'sample.txt'), 'utf8')
        const htmlLines = this._basicHtmlEncode(text)
        return htmlLines
    }

    _basicHtmlEncode (source) {
        //pick the character from source string
        //and increment the pointer
        var stashNextCharacterAndAdvanceThePointer = () => {
            var c = source.charAt(i)
            i += 1
            return c

        };

        //stringfy convertedLine array and push into result
        //reset convertedLine
        var addANewLine = () => {
            convertedLine = convertedLine.join('')
            result.push(convertedLine)
            convertedLine = []
        };

        var pushACharacterToTheOutput = () => {
            convertedLine.push(characterToConvert);
        };

        var i = 0;
        var result = [];
        var convertedLine = [];
        var characterToConvert = stashNextCharacterAndAdvanceThePointer();
        while (i <= source.length) {

            switch (characterToConvert) {
                case '<':
                    convertedLine.push('&lt;');
                    break;
                case '>':
                    convertedLine.push('&gt;');
                    break;
                case '&':
                    convertedLine.push('&amp;');
                    break;
                case '\n':
                    addANewLine();
                    break;
                default:
                    pushACharacterToTheOutput();
            }

            characterToConvert = stashNextCharacterAndAdvanceThePointer();
        }
        addANewLine();
        result = result.join('<br />');
        return result;
    }
}

export { PlaintextToHtmlConverter }