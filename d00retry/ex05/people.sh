ldapsearch -LLL -Q -t "uid=z*" cn | grep '^cn:' | cut -c 5- | sort -fr
