include Nanoc::Helpers::LinkTo

def menu(identifier, indent=0, embedded=true)
  # Get other item
  other = @items.find { |i| i.identifier == identifier }

  if other.nil?
    raise RuntimeError, "Cannot create menu for #{identifier}: not found"
  end

  # Check whether we are in other or a child
  in_other_tree = is_in_tree(@item, other)

  res = ' '*indent + '<li>' + link_to_unless_current(other[:title] || other.identifier, other)

  # if submenus are desired for other, then sort children according to
  # their :menu_order. items without :menu_order come at the end.
  children_with_order = {}
  children_without_order = []
  
  if in_other_tree && other[:menu]
    other.children.each do |c|
      if c[:menu_order].nil?
        children_without_order.push(c)
      else
        children_with_order[c[:menu_order]] = c
      end
    end
  end

  if children_with_order.length + children_without_order.length != 0
    res += "\n" + ' '*(indent+4) + "<ul>\n"
    children_with_order.sort.each do |c|
      res += menu(c[1].identifier, indent+6, false)
    end
    children_without_order.each do |c|
      res += menu(c.identifier, indent+6, false)
    end
    res += ' '*(indent+4) + "</ul>\n"
    res += ' '*(indent+2) + "</li>"
  else
    res += "</li>"
  end

  res += "\n" unless embedded
  
  res
end

def is_in_tree(child, root)
  # the tree's root is in the tree
  if child == root
    return true
  end
  # a toplevel item cannot be anybody else's child
  if child.parent.nil?
    return false
  end
  return is_in_tree(child.parent, root)
end
