package workshop;

import org.junit.Test;

import java.io.IOException;

import static org.junit.Assert.assertEquals;

public class HtmlPagesConverterTest {
    PlaintextToHtmlConverterFake converter = new PlaintextToHtmlConverterFake();

    @Test
    public void charConversion() throws Exception {
        converter.setRead("<");
        assertEquals("&lt;", converter.toHtml());

        converter.setRead(">");
        assertEquals("&gt;", converter.toHtml());

        converter.setRead("&");
        assertEquals("&amp;", converter.toHtml());

        converter.setRead("\n");
        assertEquals("<br />", converter.toHtml());
    }

    @Test
    public void noConversion() throws Exception {
        converter.setRead("simple");
        assertEquals("simple", converter.toHtml());
    }

    @Test
    public void mixedCharConversion() throws Exception {
        converter.setRead("<small>\n&space");
        assertEquals("&lt;small&gt;<br />&amp;space", converter.toHtml());
    }

    class PlaintextToHtmlConverterFake extends PlaintextToHtmlConverter {
        String text;
        protected void setRead(String text) {
            this.text = text;
        }
        @Override
        protected String read() throws IOException {
            return text;
        }
    }
}
