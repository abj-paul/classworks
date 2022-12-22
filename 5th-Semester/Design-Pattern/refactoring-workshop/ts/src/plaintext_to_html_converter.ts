// Adapted from https://github.com/emilybache/Racing-Car-Katas
const fs = require('fs')
const path = require("path")

class PlaintextToHtmlConverter {
    toHtml() {
        const text = fs.readFileSync(path.join(__dirname, 'sample.txt'), 'utf8')
        const htmlLines = this._basicHtmlEncode(text)
        return htmlLines
    }

    _basicHtmlEncode (source: string) {
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
            let line: string = convertedLine.join('')
            result.push(line)
            convertedLine = []
        };

        var pushACharacterToTheOutput = () => {
            convertedLine.push(characterToConvert);
        };

        let i = 0;
        let result: string[] = [];
        let convertedLine: string[] = [];
        let characterToConvert = stashNextCharacterAndAdvanceThePointer();
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
        let finalResult: string = result.join('<br />');
        return finalResult;
    }
}

export { PlaintextToHtmlConverter }