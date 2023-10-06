chmod 777 execute2
INPUT="$1.graph"
OUTPUT="$1.satinput"
MINISATOP="$1.satoutput"
./execute2 26 < "$INPUT" > "$OUTPUT"
minisat $OUTPUT $MINISATOP