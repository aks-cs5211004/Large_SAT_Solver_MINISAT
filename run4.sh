chmod 777 execute2
INPUT="$1.graph"
OUTPUT="$1.satinput"
MINISATOP="$1.satoutput"
N="$2"
./execute2 $N < "$INPUT" > "$OUTPUT"
minisat $OUTPUT $MINISATOP