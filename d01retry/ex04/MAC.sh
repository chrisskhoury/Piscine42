ifconfig | grep ether | sed 's/ether//g' | xargs | tr " " "\n"
