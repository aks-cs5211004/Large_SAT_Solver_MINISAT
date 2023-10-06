chmod 777 execute3
GRAPH="$1.graph"
INPUT="$1.satoutput"
OUTPUT="$1.mapping"
N=$(awk 'NR==1 {print $1; exit}' $GRAPH)
./execute3 "$N" < $INPUT > $OUTPUT