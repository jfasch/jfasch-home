require 'nokogiri'

class MyDoc < Nokogiri::XML::SAX::Document
  def initialize(depth)
    @depth = depth
    @current_level = 0
    @current_text = nil
    @current_id = nil
    # eventually, we will have this completed:
    @toc = ''
  end
  
  def start_element(name, attributes = [])
    level = _heading_level(name)
    return if level == 0 # not a heading
    raise "Heading already active" unless @current_text.nil?
    @current_id = nil
    attributes.each do |attr|
      if attr[0] == 'id'
        @current_id = attr[1]
      end
    end
    # activate capture of heading text
    @current_text = ''
  end

  def end_element(name)
    level = _heading_level(name)
    return if level == 0 # not a heading
    if level > @current_level
      (1..level-@current_level).each do |l|
        @toc << '<ul class="toc">'
      end
    elsif level < @current_level
      (1..@current_level-level).each do |l|
        @toc << '</ul>'
      end
    end

    @current_level = level
      
    @toc << '<li>'
    @toc << '<a href="#' << @current_id << '">' << @current_text << '</a>'
    @toc << '</li>'
    @current_text = nil
    @current_id = nil
  end

  def characters(ch)
    @current_text << ch unless @current_text.nil?
  end

  def done()
    if @current_level > 0
      (1..@current_level).each do |l|
        @toc << '</ul>'
      end
    end
    return @toc
  end

  def _heading_level(str)
    match = /^[Hh]([0-9]+)$/.match(str)
    if match
      return match[1].to_i
    else
      return 0
    end
  end

end

def toc(item, depth)
  content = @item_rep.instance_eval { @content[:pre] }

  my_doc = MyDoc.new(depth)
  parser = Nokogiri::HTML::SAX::Parser.new(my_doc)
  parser.parse(content)  

  return my_doc.done()
end
