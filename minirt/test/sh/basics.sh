reset
echo "basic: sphere" &
cat data_test/basics/sphere.rt & ./miniRT data_test/basics/sphere.rt
echo "\n\nbasic: plane" &
cat data_test/basics/plane.rt & ./miniRT data_test/basics/plane.rt
echo "\n\nbasic: cylinder" &
cat data_test/basics/cylinder.rt & ./miniRT data_test/basics/cylinder.rt
reset