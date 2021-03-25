#!/bin/bash

make -C .. re
cp ../replace .

line=1
show_result=0

if [ "$1" == "--show-result" ]
then
	show_result=1
fi

while IFS= read -r args
do
	file=$(echo -n $args | cut -d " " -f 1)
	s1=$(echo -n $args | cut -d '"' -f 2)
	s2=$(echo -n $args | cut -d '"' -f 4)
	sed "s/$s1/$s2/g" files/$file > files/tmp.replace
	./replace files/$file "$s1" "$s2"
	sed_replace=files/tmp.replace
	replace=files/${file%.*}.replace
	if [ $show_result -eq 1 ]
	then
		echo ------SED------- 
		cat $sed_replace
		echo "-----YOURS------" 
		cat $replace
		echo ---------------- 
	fi
	echo $sed_buf | diff - "$replace" 1> /dev/null
	status=$?
	if [ -z $status ]
	then
		echo "KO line $line: $args"
	else
		echo OK
	fi
	((line=line+1))
	rm -rf files/*.replace files/.replace
done < arguments.txt

rm -f replace
