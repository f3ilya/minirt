reset
echo "bonus: multi-spots" &
cat data_test/bonus/multi_spots.rt & ./miniRT_bonus data_test/bonus/multi_spots.rt
reset
echo "\n\nbonus: new object : cone" &
cat data_test/bonus/cone.rt & ./miniRT_bonus data_test/bonus/cone.rt
reset
echo "\n\nbonus: phong reflectance" &
echo "\nsphere" &
cat data_test/bonus/sphere.rt & ./miniRT_bonus data_test/bonus/sphere.rt
echo "\nplane" &
cat data_test/bonus/plane.rt & ./miniRT_bonus data_test/bonus/plane.rt
echo "\ncylinder" &
cat data_test/bonus/cylinder.rt & ./miniRT_bonus data_test/bonus/cylinder.rt
reset
echo "\n\nbonus: picture7 of subject" &
cat data_test/bonus/picture7.rt & ./miniRT_bonus data_test/bonus/picture7.rt
reset
echo "\n\nbonus: snowman" &
cat data_test/bonus/snowman.rt & ./miniRT_bonus data_test/bonus/snowman.rt
reset