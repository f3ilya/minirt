reset
echo "brightness 1/2: sphere1" &
cat data_test/brightness/sphere1.rt & ./miniRT data_test/brightness/sphere1.rt
echo "\n\nbrightness 1/2: sphere2" &
cat data_test/brightness/sphere2.rt & ./miniRT data_test/brightness/sphere2.rt
reset

echo "brightness 2/2: scene1" &
cat data_test/brightness2/scene1.rt & ./miniRT data_test/brightness2/scene1.rt
echo "\n\nbrightness 2/2: scene2" &
cat data_test/brightness2/scene2.rt & ./miniRT data_test/brightness2/scene2.rt
reset

echo "brightness 2/2: picture7 of the subject" &
cat data_test/brightness2/picture7.rt & ./miniRT data_test/brightness2/picture7.rt
reset