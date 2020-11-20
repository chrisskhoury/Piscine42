ldapsearch -xLLL sn='*bon*' cn | grep "cn" | wc -l | tr -d ' '
