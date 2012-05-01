# -*- coding: utf-8 -*-
class EncodeFilter < Nanoc::Filter
  identifier :encode_umlauts
 
  def run(content, params={})
    content.gsub( 'ä', '&auml;' ).gsub( 'ö', '&ouml;' ).gsub( 'ü', '&uuml;' ).gsub( 'Ä', '&Auml;' ).gsub( 'Ö', '&Ouml;' ).gsub( 'Ü', '&Uuml;').gsub( 'ß', '&szlig;' )
  end
end
