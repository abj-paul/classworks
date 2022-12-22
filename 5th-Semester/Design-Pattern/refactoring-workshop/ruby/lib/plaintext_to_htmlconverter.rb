# Adapted from https://github.com/emilybache/Racing-Car-Katas

class PlaintextToHtmlConverter
  def to_html
    @source = IO.read('./lib/simple.txt')
    basic_html_encode
  end

  private

  def stash_next_character_and_advance_the_pointer
    c = @source[@i]
    @i += 1
    c
  end

  def add_a_new_line
    @converted_line = @converted_line.join('')
    @result.push(@converted_line)
    @converted_line = []
  end

  def push_a_character_to_the_output
    @converted_line.push(@character_to_convert)
  end

  def basic_html_encode
    @i = 0
    @result = []
    @converted_line = []
    @character_to_convert = stash_next_character_and_advance_the_pointer

    while @i <= @source.length
      case (@character_to_convert)
      when "<"
        @converted_line.push("&lt;")
      when ">"
        @converted_line.push("&gt;")
      when "&"
        @converted_line.push("&amp;")
      when "\n"
        add_a_new_line
      else
        push_a_character_to_the_output
      end

      @character_to_convert = stash_next_character_and_advance_the_pointer
    end

    add_a_new_line
    @result = @result.join('<br />')
    @result
  end

end