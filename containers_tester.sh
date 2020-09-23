#Open with bash

#variables and path

#maybe a cpp script to auto complete includes and all

VECTOR="../vector/Vector.hpp"
MAP="../map/Map.hpp"
QUEUE="../queue/Queue.hpp"
STACK="../stack/Stack.hpp"
LIST="../list/List.hpp"
UTILS="../utils/Reverse_Iterator.hpp"

MAIN_INCLUDE="./utils/tester.hpp"
MAIN="./tester.cpp"
MAINS="./utils/test_vector.cpp ./utils/test_list.cpp ./utils/test_stack.cpp ./utils/test_queue.cpp ./utils/test_map.cpp"

SED="sed"

#seting up includes
clang++ -o SED ./utils/sed.cpp
./$SED "$MAIN_INCLUDE" "VECTOR" "#include \"$VECTOR\""
./$SED "$MAIN_INCLUDE" "MAP" "#include \"$MAP\""
./$SED "$MAIN_INCLUDE" "QUEUE" "#include \"$QUEUE\""
./$SED "$MAIN_INCLUDE" "STACK" "#include \"$STACK\""
./$SED "$MAIN_INCLUDE" "LIST" "#include \"$LIST\""

clang++ -o tester $MAIN $MAINS
./tester

#RESET
./$SED "$MAIN"  "#include \"$VECTOR\"" "VECTOR"
./$SED "$MAIN"  "#include \"$MAP\"" "MAP"
./$SED "$MAIN"  "#include \"$QUEUE\"" "QUEUE"
./$SED "$MAIN" "#include \"$STACK\"" "STACK"
./$SED "$MAIN" "#include \"$LIST\"" "LIST"
