#!/usr/bin/sh
chmod 777 execute2
INPUT="$1.graph"
OUTPUT="$1.satinput"
MINISATOP="$1.satoutput"


N=$(awk 'NR==1 {print $1; exit}' $INPUT)
l=0
r=$N

while [ "$l" -le "$r" ];
do

    mid=$(( (l+r)/2 ))
    ./execute2 "$mid" < "$INPUT" > "$OUTPUT"
    minisat $OUTPUT $MINISATOP

    result=$(awk 'NR==1 {print $1; exit}' $MINISATOP)

    if [ "$result" = "SAT" ]; then
        l=$(expr $mid + 1);
    elif [ "$result" = "UNSAT" ]; then
        r=$(expr $mid - 1);
    fi
done


./execute2 $(expr $l - 1) < "$INPUT" > "$OUTPUT"
minisat $OUTPUT $MINISATOP
chmod 777 execute4
GRAPH="$1.graph"
INPUT="$1.satoutput"
OUTPUT="$1.mapping"
N=$(awk 'NR==1 {print $1; exit}' $GRAPH)
./execute4 "$N" < $INPUT > $OUTPUT
echo $(expr $l - 1)
