# -*- coding: utf-8 -*-
def my_breadcrumbs
  ret = ''
  unless @item.reps[0].path == "/"
    breadcrumbs_trail.each do |b|
      ret += link_to(b[:title] , b.reps[0].path) if b
      if b != @item
        ret += '»'
      else
        ret += ''
      end
    end
  end
  return ret
end
