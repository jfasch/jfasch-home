def context()
  if @item[:context]
    case @item[:context]
    when "course"
      return render('contexts/course')
    when "oss"
      return render('contexts/oss')
    else
      raise "unknown context \"#{@item[:context]}\" in #{@item.identifier}"
    end
  else
    return render('contexts/default')
  end
end
