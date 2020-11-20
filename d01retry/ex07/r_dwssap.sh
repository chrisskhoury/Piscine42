cat /etc/passwd | sed /#/d | sed -n 'n;p' | cut -d ':' -f 1 | rev | sort -r | awk "FNR>=$FT_LINE1 && FNR<=$FT_LINE2" | sed '$!s/$/, /; $s/$/./' | tr -d '\n'
