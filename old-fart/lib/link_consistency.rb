def link_to_path(text, path)
  target = @items.find { |i| i.identifier == path }
  raise RuntimeError, "Inconsistent link in \"#{@item.identifier}\": path \"#{path}\" does not exist" if target.nil?
  return link_to(text, target)
end

def link_to_name(text, name)
  target = @items.find { |i| i[:target_name] == name }
  raise RuntimeError, "Inconsistent link in \"#{@item.identifier}\": target name \"#{name}\" does not exist" if target.nil?
  return link_to(text, target)
end
